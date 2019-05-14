%{
#include "ag.h"
#include "codegen.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    if(tail == NULL)
        return head;

    head->next = tail;
    return head;
}

symbol_t* symbols_merge(symbol_t *head1, symbol_t *head2) {
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    // This implementation is VERY inefficient
    symbol_t *new_list_1_end, *list_1_end = head1;
    while(list_1_end != NULL) {
        head2 = append_symbol_node(new_symbol_node(list_1_end->name, list_1_end->type), head2);
        list_1_end = list_1_end->next;
    }
    return head2;
}

void print_symbols(symbol_t *head) {
    printf("Symbols: ");
    do {
        printf("%s ", head->name);
    } while((head = head->next) != NULL);
    printf("\n");
}

void check_symbol_usage(char *name, symbol_type_t type, symbol_t* head) {
    if(head == NULL) {
        printf("Error: Symbol '%s' not found.\n", name);
        exit(3);
    }

    do {
        if(strcmp(name, head->name) == 0 && type == head->type)
            return;
    } while((head = head->next) != NULL);
    printf("Error: Symbol '%s' not found.\n", name);
    exit(3);
}

void check_symbol_def(char *name, symbol_t *head) {
    if(head == NULL) {
        return;
    }

    do {
        if(strcmp(name, head->name) == 0) {
            printf("Error: Symbol '%s' already defined.\n", name);
            exit(3);
        }
    } while((head = head->next) != NULL);
}

// Codegen
extern STATEPTR_TYPE burm_label(op_tree_t *t);
extern void burm_reduce(op_tree_t *t, int goalnt);

#define CALL_CODEGEN(t) burm_label(t); burm_reduce(t, 1);
%}

%token  OR END ID COND RETURN HEAD TAIL ISLIST BREAK CONTINUE VAR NOT RA NUM ';' '(' ')' '=' '-' '.' ':' ',' GTEQ
%start  program

@attributes { char *val; } ID
@attributes { long val; } NUM
@attributes { symbol_t *symbols_inh; } funcdef
@attributes { symbol_t *symbols_inh; op_tree_t *op_tree; } pars

@attributes { symbol_t *symbols_inh; symbol_t *symbols; } vardef
@attributes { symbol_t *symbols_inh; symbol_t *symbols; } stats
@attributes { symbol_t *label; symbol_t *symbols_inh; } cond
@attributes { symbol_t *label; } condlab
@attributes { symbol_t *symbols_inh; op_tree_t *op_tree; } stat
@attributes { symbol_t *symbols_inh; } guarded

@attributes { symbol_t *symbols_inh; op_tree_t *op_tree; } term
@attributes { symbol_t *symbols_inh; op_tree_t *op_tree; } expr
@attributes { symbol_t *symbols_inh; } addexp
@attributes { symbol_t *symbols_inh; } mulexp
@attributes { symbol_t *symbols_inh; } dotexp
@attributes { symbol_t *symbols_inh; } orexp
@attributes { symbol_t *symbols_inh; } cargs
@attributes { symbol_t *symbols_inh; } glab

@traversal @preorder check
@traversal @preorder codegen

%%
program :    /* empty */
        |    program funcdef ';'
        ;

funcdef :    ID '(' ')' stats END
             @{
                 @i @funcdef.symbols_inh@ = NULL;
                 @i @stats.symbols_inh@ = @funcdef.symbols_inh@;
             @}
        |    ID '(' pars ')' stats END
             @{
                 @i @funcdef.symbols_inh@ = @pars.symbols_inh@;
                 @i @stats.symbols_inh@ = @funcdef.symbols_inh@;
             @}
        ;

pars    :    pars ',' ID 
             @{
                 @i @pars.symbols_inh@ = append_symbol_node(new_symbol_node(@ID.val@, VARIABLE), @pars.1.symbols_inh@);
                 @i NEW_OP_TREE_NODE(@pars.op_tree@, VARDEF, @pars.1.op_tree@, NULL, 0);
                 
                 @check check_symbol_def(@ID.val@, @pars.1.symbols_inh@);
                 @codegen CALL_CODEGEN(@pars.op_tree@);
             @}
        |    ID
             @{       
                 @i NEW_OP_TREE_NODE(@pars.op_tree@, VARDEF, NULL, NULL, 0);
                 @i @pars.symbols_inh@ = new_symbol_node(@ID.val@, VARIABLE);

                 @codegen CALL_CODEGEN(@pars.op_tree@);
             @}
        ;

stats   :    /* empty */
             @{
                 @i @stats.symbols@ = NULL;
             @}
        |    stats stat ';'
             @{
                 @i @stats.symbols@ = @stats.1.symbols@;
                 @i @stats.1.symbols_inh@ = @stats.0.symbols_inh@;

                 @i @stat.symbols_inh@ = symbols_merge(@stats.symbols_inh@, @stats.symbols@);
             @}
        |    stats vardef ';'
             @{
                 @i @stats.symbols@ = append_symbol_node(@vardef.symbols@, @stats.1.symbols@);
                 @i @stats.1.symbols_inh@ = @stats.0.symbols_inh@;
                 @i @vardef.symbols_inh@ = symbols_merge(@stats.symbols_inh@, @stats.1.symbols@);
             @}
        ;

stat    :    RETURN expr
             @{
                 @i @expr.symbols_inh@ = @stat.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@stat.op_tree@, RET, @expr.op_tree@, NULL, 0);

                 @codegen CALL_CODEGEN(@stat.op_tree@);
             @}
        |    cond
             @{
                 @i @cond.symbols_inh@ = @stat.symbols_inh@;
                 @i @stat.op_tree@=NULL;
             @}
        |    ID '=' expr
             @{
                 @i @expr.symbols_inh@ = @stat.symbols_inh@;
                 @i @stat.op_tree@=NULL;

                 @check check_symbol_usage(@ID.val@, VARIABLE, @stat.symbols_inh@);
             @}
        ;

vardef  :    VAR ID '=' expr
             @{
                 @i @vardef.symbols@ = new_symbol_node(@ID.val@, VARIABLE);
                 @i @expr.symbols_inh@ = @vardef.symbols_inh@;
                 
                 @check check_symbol_def(@ID.val@, @vardef.symbols_inh@);
             @}
        ;

cond    :    condlab COND guarded END
             @{
                 @i @cond.label@ = @condlab.label@;
                 @i @guarded.symbols_inh@ = @cond.label@ == NULL
                        ? @cond.symbols_inh@ 
                        : append_symbol_node(@cond.label@, @cond.symbols_inh@);
                 
                 @check if(@cond.label@ != NULL) check_symbol_def(@cond.label@->name, @cond.symbols_inh@);
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
                 @i @stats.symbols_inh@ = @guarded.symbols_inh@;
                 @i @guarded.1.symbols_inh@ = @guarded.symbols_inh@;
                 @i @expr.symbols_inh@ = @guarded.symbols_inh@;
                 @i @glab.symbols_inh@ = @guarded.symbols_inh@;
             @}
        |    guarded RA stats contexp glab ';'
             @{
                 @i @stats.symbols_inh@ = @guarded.symbols_inh@;
                 @i @guarded.1.symbols_inh@ = @guarded.symbols_inh@;
                 @i @glab.symbols_inh@ = @guarded.symbols_inh@;
             @}
        ;

glab    :    /* empty */
        |    ID @{ @check check_symbol_usage(@ID.val@, LABEL, @glab.symbols_inh@); @}
        ;

contexp :    CONTINUE
        |    BREAK
        ;

expr    :    term
             @{
                 @i @term.symbols_inh@ = @expr.symbols_inh@;
                 @i @expr.op_tree@  = @term.op_tree@;
             @}
        |    listexp term
             @{
                 @i @term.symbols_inh@ = @expr.symbols_inh@;
                 @i @expr.op_tree@  = NULL;
             @}
        |    term addexp
             @{
                 @i @term.symbols_inh@ = @expr.symbols_inh@;
                 @i @addexp.symbols_inh@ = @expr.symbols_inh@;
                 @i @expr.op_tree@  = NULL;
             @}
        |    term mulexp
             @{
                 @i @term.symbols_inh@ = @expr.symbols_inh@;
                 @i @mulexp.symbols_inh@ = @expr.symbols_inh@;
                 @i @expr.op_tree@  = NULL;
             @}
        |    term dotexp
             @{
                 @i @term.symbols_inh@ = @expr.symbols_inh@;
                 @i @dotexp.symbols_inh@ = @expr.symbols_inh@;
                 @i @expr.op_tree@  = NULL;
             @}
        |    term orexp
             @{
                 @i @term.symbols_inh@ = @expr.symbols_inh@;
                 @i @orexp.symbols_inh@ = @expr.symbols_inh@;
                 @i @expr.op_tree@  = NULL;
             @}
        |    term GTEQ term
             @{
                 @i @term.0.symbols_inh@ = @expr.symbols_inh@;
                 @i @term.1.symbols_inh@ = @expr.symbols_inh@;
                 @i @expr.op_tree@  = NULL;
             @}
        |    term '=' term
             @{
                 @i @term.0.symbols_inh@ = @expr.symbols_inh@;
                 @i @term.1.symbols_inh@ = @expr.symbols_inh@;
                 @i @expr.op_tree@  = NULL;
             @}
        |    term '-' term
             @{
                 @i @term.0.symbols_inh@ = @expr.symbols_inh@;
                 @i @term.1.symbols_inh@ = @expr.symbols_inh@;
                 @i @expr.op_tree@  = NULL;
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
                 @i @addexp.1.symbols_inh@ = @addexp.symbols_inh@;
                 @i @term.symbols_inh@ = @addexp.symbols_inh@;
             @}
        |    '+' term
             @{
                 @i @term.symbols_inh@ = @addexp.symbols_inh@;
             @}
        ;

mulexp  :    '*' term mulexp
             @{
                 @i @mulexp.1.symbols_inh@ = @mulexp.symbols_inh@;
                 @i @term.symbols_inh@ = @mulexp.symbols_inh@;
             @}
        |    '*' term
             @{
                 @i @term.symbols_inh@ = @mulexp.symbols_inh@;
             @}
        ;

dotexp  :    '.' term dotexp
             @{
                 @i @dotexp.1.symbols_inh@ = @dotexp.symbols_inh@;
                 @i @term.symbols_inh@ = @dotexp.symbols_inh@;
             @}
        |    '.' term
             @{
                 @i @term.symbols_inh@ = @dotexp.symbols_inh@;
             @}
        ;

orexp   :    OR term orexp
             @{
                 @i @orexp.1.symbols_inh@ = @orexp.symbols_inh@;
                 @i @term.symbols_inh@ = @orexp.symbols_inh@;
             @}
        |    OR term
             @{
                 @i @term.symbols_inh@ = @orexp.symbols_inh@;
             @}
        ;

term    :    '(' expr ')'
             @{
                 @i @expr.symbols_inh@ = @term.symbols_inh@;
                 @i @term.op_tree@  = NULL;
             @}
        |    NUM
             @{
                 @i NEW_OP_TREE_NODE(@term.op_tree@, CONSTANT, NULL, NULL, @NUM.val@);                 
             @}
        |    ID 
             @{ 
                 @i @term.op_tree@  = NULL;
                 
                 @check check_symbol_usage(@ID.val@, VARIABLE, @term.symbols_inh@); 
             @}
        |    ID '(' ')'
             @{
                 @i @term.op_tree@  = NULL;
             @}
        |    ID '(' cargs ')'
             @{
                 @i @cargs.symbols_inh@ = @term.symbols_inh@;
                 @i @term.op_tree@  = NULL;
             @}
        ;

cargs   :    cargs ',' expr
             @{
                 @i @cargs.1.symbols_inh@ = @cargs.symbols_inh@;
                 @i @expr.symbols_inh@ = @cargs.symbols_inh@;
             @}
        |    expr
             @{
                 @i @expr.symbols_inh@ = @cargs.symbols_inh@;
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
