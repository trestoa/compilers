%{
#include "ag.h"

#include <stdio.h>

int yylex();
int yyerror(char *s);

symbol_t* new_symbol_node(char *name, symbol_type_t type) {
    symbol_t *sym = malloc(sizeof(symbol_t));
    sym->name = name;
    sym->type = type;
    sym->next = NULL;
    return sym;
}

symbol_t* append_symbol_node(symbol_t *head, symbol_t *tail) {
    head->next = tail;
    return head;
}

symbol_t* symbols_merge(symbol_t *head1, symbol_t *head2) {
    // This implementation is VERY inefficient
    symbol_t *new_list_1_end, *list_1_end = head1;
    while(list_1_end->next != NULL) {
        head2 = append_symbol_node(new_symbol_node(list_1_end->name, list_1_end->type), head2);
        list_1_end = list_1_end->next;
    }
    return head2;
}

void print_symbols(symbol_t *head) {
    do {
        printf("%s ", head->name);
    } while((head = head->next) != NULL);
}

void check_symbol(char *name, symbol_type_t type, symbol_t* head) {
    if(head == NULL) {
        printf("Error: Symbol '%s' not found.", name);
        exit(3);
    }

    do {
        if(strcmp(name, head->name) == 0 && type == head->type)
            return;
    } while((head = head->next) != NULL);
    printf("Error: Symbol '%s' not found.", name);
        exit(3);
}
%}

%token  OR END ID COND RETURN HEAD TAIL ISLIST BREAK CONTINUE VAR NOT RA NUM ';' '(' ')' '=' '-' '.' ':' ',' GTEQ
%start  program

@attributes { char *val; } ID
@attributes { symbol_t *args; } funcdef
@attributes { symbol_t *args; } pars

@attributes { symbol_t *args; symbol_t *symbols; } vardef
@attributes { symbol_t *args; symbol_t *symbols; } stats
@attributes { symbol_t *label; symbol_t *args; } cond
@attributes { symbol_t *label; } condlab
@attributes { symbol_t *args; } stat
@attributes { symbol_t *args; } guarded

@attributes { symbol_t *args; } term
@attributes { symbol_t *args; } expr
@attributes { symbol_t *args; } addexp
@attributes { symbol_t *args; } mulexp
@attributes { symbol_t *args; } dotexp
@attributes { symbol_t *args; } orexp
@attributes { symbol_t *args; } cargs
@attributes { symbol_t *args; } glab

@traversal @preorder printArgs
@traversal @preorder check

%%
program :    /* empty */
        |    program funcdef ';'
        ;

funcdef :    ID '(' ')' stats END
             @{
                 @i @funcdef.args@ = NULL;
                 @i @stats.args@ = @funcdef.args@;
             @}
        |    ID '(' pars ')' stats END
             @{
                 @i @funcdef.args@ = @pars.args@;
                 @i @stats.args@ = @funcdef.args@;
                 
                 @printArgs print_symbols(@funcdef.args@);
             @}
        ;

pars    :    pars ',' ID 
             @{
                 @i @pars.args@ = append_symbol_node(new_symbol_node(@ID.val@, VARIABLE), @pars.1.args@);
             @}
        |    ID
             @{
                 @i @pars.args@ = new_symbol_node(@ID.val@, VARIABLE);
             @}
        ;

stats   :    /* empty */
             @{
                 @i @stats.symbols@ = NULL;
             @}
        |    stats stat ';'
             @{
                 @i @stats.symbols@ = @stats.1.symbols@;
                 @i @stats.1.args@ = @stats.0.args@;

                 @i @stat.args@ = symbols_merge(@stats.args@, @stats.symbols@);
             @}
        |    stats vardef ';'
             @{
                 @i @stats.symbols@ = append_symbol_node(@vardef.symbols@, @stats.1.symbols@);
                 @i @stats.1.args@ = @stats.0.args@;
                 @i @vardef.args@ = symbols_merge(@stats.args@, @stats.symbols@);
             @}
        ;

stat    :    RETURN expr
             @{
                 @i @expr.args@ = @stat.args@;
             @}
        |    cond
             @{
                 @i @cond.args@ = @stat.args@;
             @}
        |    ID '=' expr
             @{
                 @i @expr.args@ = @stat.args@;

                 @check check_symbol(@ID.val@, VARIABLE, @stat.args@);
             @}
        ;

vardef  :    VAR ID '=' expr
             @{
                 @i @vardef.symbols@ = new_symbol_node(@ID.val@, VARIABLE);
                 @i @expr.args@ = @vardef.args@;
             @}
        ;

cond    :    condlab COND guarded END
             @{
                 @i @cond.label@ = @condlab.label@;
                 @i @guarded.args@ = @cond.label@ == NULL
                        ? @cond.args@ 
                        : append_symbol_node(@cond.label@, @cond.args@);
             @}
        ;

condlab :    /* empty */
             @{
                 @i @condlab.label@ = NULL;
             @}
        |    ID ':'
             @{
                 @i @condlab.label@ = new_symbol_node(@ID.val@, LABEL);
             @}
        ;

guarded :    /* empty */
        |    guarded expr RA stats contexp glab ';'
             @{
                 @i @stats.args@ = @guarded.args@;
                 @i @guarded.1.args@ = @guarded.args@;
                 @i @expr.args@ = @guarded.args@;
                 @i @glab.args@ = @guarded.args@;
             @}
        |    guarded RA stats contexp glab ';'
             @{
                 @i @stats.args@ = @guarded.args@;
                 @i @guarded.1.args@ = @guarded.args@;
                 @i @glab.args@ = @guarded.args@;
             @}
        ;

glab    :    /* empty */
        |    ID @{ @check check_symbol(@ID.val@, VARIABLE, @glab.args@); @}
        ;

contexp :    CONTINUE
        |    BREAK
        ;

expr    :    term
             @{
                 @i @term.args@ = @expr.args@;
             @}
        |    listexp term
             @{
                 @i @term.args@ = @expr.args@;
             @}
        |    term addexp
             @{
                 @i @term.args@ = @expr.args@;
                 @i @addexp.args@ = @expr.args@;
             @}
        |    term mulexp
             @{
                 @i @term.args@ = @expr.args@;
                 @i @mulexp.args@ = @expr.args@;
             @}
        |    term dotexp
             @{
                 @i @term.args@ = @expr.args@;
                 @i @dotexp.args@ = @expr.args@;
             @}
        |    term orexp
             @{
                 @i @term.args@ = @expr.args@;
                 @i @orexp.args@ = @expr.args@;
             @}
        |    term GTEQ term
             @{
                 @i @term.0.args@ = @expr.args@;
                 @i @term.1.args@ = @expr.args@;
             @}
        |    term '=' term
             @{
                 @i @term.0.args@ = @expr.args@;
                 @i @term.1.args@ = @expr.args@;
             @}
        |    term '-' term
             @{
                 @i @term.0.args@ = @expr.args@;
                 @i @term.1.args@ = @expr.args@;
             @}
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

addexp  :    '+' term addexp
             @{
                 @i @addexp.1.args@ = @addexp.args@;
                 @i @term.args@ = @addexp.args@;
             @}
        |    '+' term
             @{
                 @i @term.args@ = @addexp.args@;
             @}
        ;

mulexp  :    '*' term mulexp
             @{
                 @i @mulexp.1.args@ = @mulexp.args@;
                 @i @term.args@ = @mulexp.args@;
             @}
        |    '*' term
             @{
                 @i @term.args@ = @mulexp.args@;
             @}
        ;

dotexp  :    '.' term dotexp
             @{
                 @i @dotexp.1.args@ = @dotexp.args@;
                 @i @term.args@ = @dotexp.args@;
             @}
        |    '.' term
             @{
                 @i @term.args@ = @dotexp.args@;
             @}
        ;

orexp   :    OR term orexp
             @{
                 @i @orexp.1.args@ = @orexp.args@;
                 @i @term.args@ = @orexp.args@;
             @}
        |    OR term
             @{
                 @i @term.args@ = @orexp.args@;
             @}
        ;

term    :    '(' expr ')'
             @{
                 @i @expr.args@ = @term.args@;
             @}
        |    NUM
        |    ID @{ @check check_symbol(@ID.val@, VARIABLE, @term.args@); @}
        |    ID '(' ')'
        |    ID '(' cargs ')'
             @{
                 @i @cargs.args@ = @term.args@;
             @}
        ;

cargs   :    cargs ',' expr
             @{
                 @i @cargs.1.args@ = @cargs.args@;
                 @i @expr.args@ = @cargs.args@;
             @}
        |    expr
             @{
                 @i @expr.args@ = @cargs.args@;
             @}
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
