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

#define CALL_CODEGEN(t) /*0print_optree(t, 0);*/ burm_label(t); burm_reduce(t, 1);

void print_optree(op_tree_t *t, int offset) {
    for(int i = 0; i < offset; i++)
        printf(" ");
    
    printf("op: %u\n", t->op);

    if(t->kids[0] != NULL)
        print_optree(t->kids[0], offset + 2);
    if(t->kids[1] != NULL)
        print_optree(t->kids[1], offset + 2);
}
%}

%token  OR END ID COND RETURN HEAD TAIL ISLIST BREAK CONTINUE VAR NOT RA NUM ';' '(' ')' '=' '-' '.' ':' ',' GTEQ
%start  program

@attributes { char *val; } ID
@attributes { long val; } NUM
@attributes { symbol_t *symbols_inh; } funcdef
@attributes { symbol_t *symbols_inh; op_tree_t *op_tree; } pars

@attributes { symbol_t *symbols_inh; symbol_t *symbols; op_tree_t *op_tree; } vardef
@attributes { symbol_t *symbols_inh; } stats
@attributes { symbol_t *label; symbol_t *symbols_inh; char *cond_endlab; } cond
@attributes { symbol_t *label; } condlab
@attributes { symbol_t *symbols_inh; op_tree_t *op_tree; } stat
@attributes { symbol_t *symbols_inh; char *cond_endlab; char *cond_startlab; } guarded
@attributes { char* label; } guardend
@attributes { char* label; } condend
@attributes { symbol_t *symbols_inh; char *cond_endlab; char *cond_startlab; } contexp

@attributes { symbol_t *symbols_inh; op_tree_t *op_tree; } term
@attributes { symbol_t *symbols_inh; op_tree_t *op_tree; } expr
@attributes { symbol_t *symbols_inh; op_tree_t *op_tree; } addexp
@attributes { symbol_t *symbols_inh; op_tree_t *op_tree; } mulexp
@attributes { symbol_t *symbols_inh; op_tree_t *op_tree; } dotexp
@attributes { symbol_t *symbols_inh; op_tree_t *op_tree; } listexp
@attributes { symbol_t *symbols_inh; op_tree_t *op_tree; } orexp
@attributes { symbol_t *symbols_inh; } cargs
@attributes { symbol_t *symbols_inh; char *label; } glab

@traversal @preorder check
@traversal @preorder preamble
@traversal @preorder codegen

%%
program :    /* empty */
        |    program funcdef ';'
        ;

funcdef :    ID '(' ')' stats END
             @{
                 @i @funcdef.symbols_inh@ = NULL;
                 @i @stats.symbols_inh@ = @funcdef.symbols_inh@;

                 @preamble printf(".text\n.globl %s\n%s:\npushq %rbp\nmovq %rsp, %rbp\nsubq $" "48, %rsp\n", @ID.val@, @ID.val@);
             @}
        |    ID '(' pars ')' stats END
             @{
                 @i @funcdef.symbols_inh@ = @pars.symbols_inh@;
                 @i @stats.symbols_inh@ = @funcdef.symbols_inh@;

                 @preamble printf(".text\n.globl %s\n%s:\npushq %rbp\nmovq %rsp, %rbp\nsubq $" "48, %rsp\n", @ID.val@, @ID.val@);
             @}
        ;

pars    :    ID ',' pars
             @{
                 @i @pars.symbols_inh@ = append_symbol_node(new_symbol_node(@ID.val@, VARIABLE), @pars.1.symbols_inh@);
                 @i NEW_OP_TREE_NODE(@pars.op_tree@, VARDEF, @pars.1.op_tree@, NULL, 0, @ID.val@)
                 
                 @check check_symbol_def(@ID.val@, @pars.1.symbols_inh@);
                 @codegen CALL_CODEGEN(@pars.op_tree@);
             @}
        |    ID
             @{       
                 @i NEW_OP_TREE_NODE(@pars.op_tree@, VARDEF, NULL, NULL, 0, @ID.val@)
                 @i @pars.symbols_inh@ = new_symbol_node(@ID.val@, VARIABLE); 

                 @codegen CALL_CODEGEN(@pars.op_tree@);
             @}
        ;

stats    :    /* empty */
             @{
             @}
        |    stat ';' stats
             @{
                 @i @stats.1.symbols_inh@ = @stats.0.symbols_inh@;

                 @i @stat.symbols_inh@ = @stats.0.symbols_inh@;
             @}
        |    vardef ';' stats
             @{
                 @i @stats.1.symbols_inh@ = append_symbol_node(@vardef.symbols@, @stats.symbols_inh@);
                 @i @vardef.symbols_inh@ = @stats.symbols_inh@;
             @}
        ;

stat    :    RETURN expr
             @{
                 @i @expr.symbols_inh@ = @stat.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@stat.op_tree@, RET, @expr.op_tree@, NULL, 0, NULL);

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
                 @i NEW_OP_TREE_NODE(@stat.op_tree@, VARSET, @expr.op_tree@, NULL, 0, @ID.val@);

                 @check check_symbol_usage(@ID.val@, VARIABLE, @stat.symbols_inh@);
                 @codegen CALL_CODEGEN(@stat.op_tree@)
             @}
        ;

vardef  :    VAR ID '=' expr
             @{
                 @i @vardef.symbols@ = new_symbol_node(@ID.val@, VARIABLE);
                 @i @expr.symbols_inh@ = @vardef.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@vardef.op_tree@, VARSET, @expr.op_tree@, NULL, 0, @ID.val@);
                 
                 @check check_symbol_def(@ID.val@, @vardef.symbols_inh@);
                 @codegen op_tree_t *vardef_op_tree; NEW_OP_TREE_NODE(vardef_op_tree, VARDEF, NULL, NULL, 0, @ID.val@) CALL_CODEGEN(vardef_op_tree) CALL_CODEGEN(@vardef.op_tree@)
             @}
        ;

cond    :    condlab COND guarded condend
             @{
                 @i @cond.label@ = @condlab.label@;
                 @i @guarded.symbols_inh@ = @cond.label@ == NULL
                        ? @cond.symbols_inh@ 
                        : append_symbol_node(@cond.label@, @cond.symbols_inh@);
                 @i @guarded.cond_startlab@ = @cond.label@ != NULL ? @cond.label@->name : gen_label("cond");
                 @i @cond.cond_endlab@ = gen_endlabel(@guarded.cond_startlab@);
                 @i @guarded.cond_endlab@ = @cond.cond_endlab@;
                 @i @condend.label@ = @guarded.cond_endlab@;
                 
                 @check if(@cond.label@ != NULL) check_symbol_def(@cond.label@->name, @cond.symbols_inh@);
             @}
        ;

condend  :   END
             @{
                 @codegen printf("%s:\n", @condend.label@);
             @}
        ;

condlab :    /* empty */
             @{
                 @i @condlab.label@ = new_symbol_node(gen_label("cond"), LABEL);
                 @codegen printf("%s:\n", @condlab.label@->name);
             @}
        |    ID ':'
             @{
                 @i @condlab.label@ = new_symbol_node(@ID.val@, LABEL);
                 @codegen printf("%s:\n", @ID.val@);
             @}
        ;

guarded :    /* empty */
        |    expr RA stats contexp guardend guarded
             @{
                 @i @stats.symbols_inh@ = @guarded.symbols_inh@;
                 @i @guarded.1.symbols_inh@ = @guarded.symbols_inh@;
                 @i @expr.symbols_inh@ = @guarded.symbols_inh@;
                 @i @contexp.symbols_inh@ = @guarded.symbols_inh@;
                 @i @guarded.1.cond_endlab@ = @guarded.cond_endlab@;
                 @i @guarded.1.cond_startlab@ = @guarded.cond_startlab@;
                 @i @contexp.cond_endlab@ = @guarded.cond_endlab@;
                 @i @contexp.cond_startlab@ = @guarded.cond_startlab@;
                 @i @guardend.label@ = gen_label("guardedend");
                
                 @codegen op_tree_t *op_tree; NEW_OP_TREE_NODE(op_tree, GUARDED, @expr.op_tree@, NULL, 0, @guardend.label@) CALL_CODEGEN(op_tree);
             @}
        |    RA stats contexp ';' guarded
             @{
                 @i @stats.symbols_inh@ = @guarded.symbols_inh@;
                 @i @guarded.1.symbols_inh@ = @guarded.symbols_inh@;
                 @i @contexp.symbols_inh@ = @guarded.symbols_inh@;
                 @i @guarded.1.cond_endlab@ = @guarded.cond_endlab@;
                 @i @guarded.1.cond_startlab@ = @guarded.cond_startlab@;
                 @i @contexp.cond_endlab@ = @guarded.cond_endlab@;
                 @i @contexp.cond_startlab@ = @guarded.cond_startlab@;
             @}
        ;

guardend:    ';'
             @{
                  @codegen printf("%s:\n", @guardend.label@);
             @}
        ;

glab    :    /* empty */ @{ @i @glab.label@ = NULL; @}
        |    ID
             @{ 
                @i @glab.label@ = @ID.val@;
                @check check_symbol_usage(@ID.val@, LABEL, @glab.symbols_inh@); 
             @}
        ;

contexp :    CONTINUE glab
             @{
                 @i @glab.symbols_inh@ = @contexp.symbols_inh@;
                 @codegen printf("jmp %s\n", @glab.label@ == NULL ? @contexp.cond_startlab@ : @glab.label@);
             @}
        |    BREAK glab
             @{
                 @i @glab.symbols_inh@ = @contexp.symbols_inh@;
                 @codegen printf("jmp %s\n", @glab.label@ == NULL ? @contexp.cond_endlab@ : gen_endlabel(@glab.label@));
             @}
        ;

expr    :    term
             @{
                 @i @term.symbols_inh@ = @expr.symbols_inh@;
                 @i @expr.op_tree@  = @term.op_tree@;
             @}
        |    listexp
             @{
                 @i @listexp.symbols_inh@ = @expr.symbols_inh@;
                 @i @expr.op_tree@  = @listexp.op_tree@;
             @}
        |    term addexp
             @{
                 @i @term.symbols_inh@ = @expr.symbols_inh@;
                 @i @addexp.symbols_inh@ = @expr.symbols_inh@;

                 @i NEW_OP_TREE_NODE(@expr.op_tree@, ADD, @term.op_tree@, @addexp.op_tree@, 0, NULL);
             @}
        |    term mulexp
             @{
                 @i @term.symbols_inh@ = @expr.symbols_inh@;
                 @i @mulexp.symbols_inh@ = @expr.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@expr.op_tree@, MUL, @term.op_tree@, @mulexp.op_tree@, 0, NULL);
             @}
        |    term dotexp
             @{
                 @i @term.symbols_inh@ = @expr.symbols_inh@;
                 @i @dotexp.symbols_inh@ = @expr.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@expr.op_tree@, MKLIST, @term.op_tree@, @dotexp.op_tree@, 0, NULL);
             @}
        |    term orexp
             @{
                 @i @term.symbols_inh@ = @expr.symbols_inh@;
                 @i @orexp.symbols_inh@ = @expr.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@expr.op_tree@, OROP, @term.op_tree@, @orexp.op_tree@, 0, NULL);
             @}
        |    term GTEQ term
             @{
                 @i @term.0.symbols_inh@ = @expr.symbols_inh@;
                 @i @term.1.symbols_inh@ = @expr.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@expr.op_tree@, GTEQOP, @term.0.op_tree@, @term.1.op_tree@, 0, NULL);          
             @}
        |    term '=' term
             @{
                 @i @term.0.symbols_inh@ = @expr.symbols_inh@;
                 @i @term.1.symbols_inh@ = @expr.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@expr.op_tree@, EQOP, @term.0.op_tree@, @term.1.op_tree@, 0, NULL);
             @}
        |    term '-' term
             @{
                 @i @term.0.symbols_inh@ = @expr.symbols_inh@;
                 @i @term.1.symbols_inh@ = @expr.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@expr.op_tree@, SUB, @term.0.op_tree@, @term.1.op_tree@, 0, NULL);
             @}
        ;

listexp :    NOT term           
             @{ 
                 @i @term.symbols_inh@ = @listexp.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@listexp.op_tree@, NOTOP, @term.op_tree@, NULL, 0, NULL); 
             @}
        |    HEAD term          
             @{ 
                 @i @term.symbols_inh@ = @listexp.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@listexp.op_tree@, HEADOP, @term.op_tree@, NULL, 0, NULL); 
             @}
        |    TAIL term          
             @{ 
                 @i @term.symbols_inh@ = @listexp.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@listexp.op_tree@, TAILOP, @term.op_tree@, NULL, 0, NULL);
             @}
        |    ISLIST term        
             @{ 
                 @i @term.symbols_inh@ = @listexp.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@listexp.op_tree@, ISLISTOP, @term.op_tree@, NULL, 0, NULL);
             @}
        |    NOT listexp        
             @{ 
                 @i @listexp.1.symbols_inh@ = @listexp.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@listexp.op_tree@, NOTOP, @listexp.1.op_tree@, NULL, 0, NULL); 
             @}
        |    HEAD listexp       
             @{ 
                 @i @listexp.1.symbols_inh@ = @listexp.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@listexp.op_tree@, HEADOP, @listexp.1.op_tree@, NULL, 0, NULL);
             @}
        |    TAIL listexp
             @{ 
                 @i @listexp.1.symbols_inh@ = @listexp.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@listexp.op_tree@, TAILOP, @listexp.1.op_tree@, NULL, 0, NULL); 
             @}
        |    ISLIST listexp     
             @{
                 @i @listexp.1.symbols_inh@ = @listexp.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@listexp.op_tree@, ISLISTOP, @listexp.1.op_tree@, NULL, 0, NULL); 
             @}
        ;

addexp  :    '+' term addexp
             @{
                 @i @addexp.1.symbols_inh@ = @addexp.symbols_inh@;
                 @i @term.symbols_inh@ = @addexp.symbols_inh@;
                 @i NEW_OP_TREE_NODE(@addexp.op_tree@, ADD, @term.op_tree@, @addexp.1.op_tree@, 0, NULL);
             @}
        |    '+' term
             @{
                 @i @term.symbols_inh@ = @addexp.symbols_inh@;
                 @i @addexp.op_tree@ = @term.op_tree@;
             @}
        ;

mulexp  :    '*' term mulexp
             @{
                 @i @mulexp.1.symbols_inh@ = @mulexp.symbols_inh@;
                 @i @term.symbols_inh@ = @mulexp.symbols_inh@;

                 @i NEW_OP_TREE_NODE(@mulexp.op_tree@, MUL, @term.op_tree@, @mulexp.1.op_tree@, 0, NULL);
             @}
        |    '*' term
             @{
                 @i @term.symbols_inh@ = @mulexp.symbols_inh@;
                 @i @mulexp.op_tree@ = @term.op_tree@;
             @}
        ;

dotexp  :    '.' term dotexp
             @{
                 @i @dotexp.1.symbols_inh@ = @dotexp.symbols_inh@;
                 @i @term.symbols_inh@ = @dotexp.symbols_inh@;

                 @i NEW_OP_TREE_NODE(@dotexp.op_tree@, MKLIST, @term.op_tree@, @dotexp.1.op_tree@, 0, NULL);
             @}
        |    '.' term
             @{
                 @i @term.symbols_inh@ = @dotexp.symbols_inh@;
                 @i @dotexp.op_tree@ = @term.op_tree@;
             @}
        ;

orexp   :    OR term orexp
             @{
                 @i @orexp.1.symbols_inh@ = @orexp.symbols_inh@;
                 @i @term.symbols_inh@ = @orexp.symbols_inh@;

                 @i NEW_OP_TREE_NODE(@orexp.op_tree@, OROP, @term.op_tree@, @orexp.1.op_tree@, 0, NULL);
             @}
        |    OR term
             @{
                 @i @term.symbols_inh@ = @orexp.symbols_inh@;
                 @i @orexp.op_tree@ = @term.op_tree@;
             @}
        ;

term    :    '(' expr ')'
             @{
                 @i @expr.symbols_inh@ = @term.symbols_inh@;
                 @i @term.op_tree@  = @expr.op_tree@;
             @}
        |    NUM
             @{
                 @i NEW_OP_TREE_NODE(@term.op_tree@, CONSTANT, NULL, NULL, @NUM.val@, NULL);                 
             @}
        |    ID 
             @{ 
                 @i NEW_OP_TREE_NODE(@term.op_tree@, VARUSE, NULL, NULL, 0, @ID.val@)
                 
                 @check check_symbol_usage(@ID.val@, VARIABLE, @term.symbols_inh@); 
             @}
        |    ID '(' ')'
             @{
                 @i NEW_OP_TREE_NODE(@term.op_tree@, FUNCALL, NULL, NULL, 0, @ID.val@)
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
