%{
int yylex();
int yyerror(char *s);
%}

%token  OR END ID COND RETURN HEAD TAIL ISLIST BREAK CONTINUE VAR NOT RA NUM ';' '(' ')' '=' '-' '.' ':' ',' GTEQ
%start  program
%%
program :    /* empty */
        |    program funcdef ';'
        ;

funcdef :    ID '(' ')' stats END
        |    ID '(' pars ')' stats END
        ;

pars    :    pars ',' ID 
        |    ID

stats   :    /* empty */
        |    stats stat ';'

stat    :    RETURN expr
        |    cond
        |    VAR ID '=' expr
        |    ID '=' expr
        ;

cond    :    condlab COND guarded END
        ;

condlab :    /* empty */
        |    ID ':'
        ;

guarded :    /* empty */
        |    guarded expr RA stats contexp glab ';'
        |    guarded RA stats contexp glab ';'
        ;

glab    :    /* empty */
        |    ID
        ;

contexp :    CONTINUE
        |    BREAK
        ;

expr    :    listexp term
        |    numexp
        |    term GTEQ term
        |    term '=' term
        |    term '-' term
        ;

listexp :    NOT
        |    HEAD
        |    TAIL
        |    ISLIST
        |    NOT listexp
        |    HEAD listexp
        |    TAIL listexp
        |    ISLIST listexp
        ;

numexp  :    term
        |    numexp '+' term
        |    numexp '*' term
        |    numexp '.' term 
        |    numexp OR term 
        ;


term    :    '(' expr ')'
        |    NUM
        |    ID
        |    ID '(' ')'
        |    ID '(' cargs ')'
        ;

cargs   :    cargs ',' expr 
        |    expr

%%
#include "lex.yy.c"
int yyerror(char *e) {
        printf("Parser error: '%s'...\n", e);
        exit(2);
}

int main(void) {
        yyparse();
        return 0;
}
