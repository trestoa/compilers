%{
#include "attribute_types.h"
%}

%{ 
int yylex();
int yyerror(char *s);

typedef enum symbol_type {
    LABEL = 0,
    VAR = 1
} symbol_type_t;

typedef struct symbol {
    symbol_type_t type,
    char *name,
    symbol_t *next
} symbol_t;
 %}
%token VAR ISLIST BREAK ID RA NOT END COND HEAD RETURN OR NUM CONTINUE TAIL GTEQ


%start program

@attributes { T_LABEL label; T_SYMBOLS symbols; } cond
@attributes { T_ARGS args; T_SYMBOLS symbols; } stats
@attributes { T_SYMBOLS symbols; } vardef
@attributes { T_VAL val; } ID
@attributes { T_LABEL label; } condlab
@attributes { T_ARGS args; } pars
@attributes { T_SYMBOLS symbols; } guarded
@attributes { T_SYMBOLS symbols; T_SYMBOLS_USED symbols_used; } expr
@attributes { T_SYMBOLS_USED symbols_used; } term
@attributes { T_ARGS args; } funcdef
@attributes { T_SYMBOLS symbols; } stat
@attributes { T_SYMBOLS_USED symbols_used; } addexp
@attributes { T_LABEL label; T_SYMBOLS symbols; } glab


%%
cond : condlab COND guarded END
       @{
           @i /* INVALID ASSIGNMENT */@guarded.symbols@ = @cond.symbols@;
           @i @cond.label@ = @condlab.label@;
       @}
     ;
mulexp : '*' term mulexp
       | '*' term
       ;
guarded : 
        | guarded expr RA stats contexp glab ';'
          @{
              @i @glab.symbols@ = @guarded.0.symbols@;
              @i @expr.symbols@ = @guarded.0.symbols@;
              @i @guarded.1.symbols@ = @guarded.0.symbols@;
              @i @stats.args@ = @guarded.0.symbols@;
          @}
        | guarded RA stats contexp glab ';'
        ;
program : 
        | program funcdef ';'
        ;
condlab : 
        | ID ':'
          @{
              @i @condlab.label@ = @ID.val@;
          @}
        ;
stats : 
      | stats stat ';'
        @{
            @i @stats.1.args@ = @stats.0.args@;
            @i @stats.0.symbols@ = @stats.1.symbols@;
            @i /* INVALID ASSIGNMENT */@stat.symbols@ = @stats.0.symbols@;
        @}
      | stats vardef ';'
        @{
            @i @stats.0.symbols@ = @vardef.symbols@ + @stats.1.symbols@;
            @i @stats.1.args@ = @stats.0.args@;
        @}
      ;
funcdef : ID '(' ')' stats END
        | ID '(' pars ')' stats END
          @{
              @i @stats.args@ = @funcdef.args@;
              @i @funcdef.args@ = @pars.args@;
          @}
        ;
stat : RETURN expr
       @{
           @i @expr.symbols@ = @stat.symbols@;
       @}
     | cond
       @{
           @i @cond.symbols@ = @stat.symbols@;
       @}
     | ID '=' expr
     ;
orexp : OR term orexp
      | OR term
      ;
expr : term
     | listexp term
     | term addexp
       @{
           @i /* INVALID ASSIGNMENT */@expr.symbols_used@ = @addexp.symbols_used@;
       @}
     | term mulexp
     | term dotexp
     | term orexp
     | term GTEQ term
     | term '=' term
     | term '-' term
     ;
listexp : NOT
        | HEAD
        | TAIL
        | ISLIST
        | NOT listexp
        | HEAD listexp
        | TAIL listexp
        | ISLIST listexp
        ;
glab : 
     | ID
       @{
           @i @glab.label@ = @ID.val@;
       @}
     ;
pars : pars ',' ID
       @{
           @i /* INVALID ASSIGNMENT */@pars.0.args@ = @pars.1.args@;
       @}
     | ID
       @{
           @i @pars.args@ = @ID.val@;
       @}
     ;
term : '(' expr ')'
     | NUM
     | ID
       @{
           @i @term.symbols_used@ = @ID.val@;
       @}
     | ID '(' ')'
     | ID '(' cargs ')'
     ;
contexp : CONTINUE
        | BREAK
        ;
vardef : VAR ID '=' expr
         @{
             @i @vardef.symbols@ = @ID.val@;
         @}
       ;
cargs : cargs ',' expr
      | expr
      ;
addexp : '+' term addexp
       | '+' term
         @{
             @i @addexp.symbols_used@ = @term.symbols_used@;
         @}
       ;
dotexp : '.' term dotexp
       | '.' term
       ;

%%

int yyerror(char *e) {
        printf("Parser error: '%s'...\n", e);
        exit(2);
}

int main(void) {
        yyparse();
        return 0;
}

