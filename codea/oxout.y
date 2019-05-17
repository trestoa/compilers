/* output from Ox version 1.5.1 */

/* Ox-generated Attribute-Grammar evaluator parser specification
   for Yacc-compatible parser generators

   Copyright (C) 1992-2018  Kurt M. Bischoff

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As an exception to the standard GNU General Public License, you may
   create a larger work that contains the Ox Attribute-Grammar evaluator
   parser specification skeleton and distribute that work under terms of
   your own choice, so long as that work isn't itself an
   Attribute-Grammar evaluator generator using the skeleton or a
   modified version thereof as an evaluator parser specification
   skeleton.  */

%{
/* Identify Ox output. */
#define YYYOX 1

#ifdef __cplusplus
#define __YYYSTRUCT YYSTYPE::
#else
#define __YYYSTRUCT struct
#endif

#include <stdlib.h>
#if defined(__sun) && defined(__SVR4)
#include <strings.h>
#else
#include <string.h>
#endif
%}
#line 1 "gram.y"
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
%start
#line 145 "oxout.y"
yyyAugNonterm
#line 97 "gram.y"



#line 151 "oxout.y"

%{
#define yyyinit()


struct yyyT1
#line 99 "gram.y"
 { char *val; }
#line 160 "oxout.y"
;


struct yyyT2
#line 100 "gram.y"
 { long val; }
#line 167 "oxout.y"
;


struct yyyT3
#line 101 "gram.y"
 { symbol_t *symbols_inh; }
#line 174 "oxout.y"
;


struct yyyT4
#line 102 "gram.y"
 { symbol_t *symbols_inh; op_tree_t *op_tree; }
#line 181 "oxout.y"
;


struct yyyT5
#line 104 "gram.y"
 { symbol_t *symbols_inh; symbol_t *symbols; }
#line 188 "oxout.y"
;


struct yyyT6
#line 105 "gram.y"
 { symbol_t *symbols_inh; symbol_t *symbols; }
#line 195 "oxout.y"
;


struct yyyT7
#line 106 "gram.y"
 { symbol_t *label; symbol_t *symbols_inh; }
#line 202 "oxout.y"
;


struct yyyT8
#line 107 "gram.y"
 { symbol_t *label; }
#line 209 "oxout.y"
;


struct yyyT9
#line 108 "gram.y"
 { symbol_t *symbols_inh; op_tree_t *op_tree; }
#line 216 "oxout.y"
;


struct yyyT10
#line 109 "gram.y"
 { symbol_t *symbols_inh; }
#line 223 "oxout.y"
;


struct yyyT11
#line 111 "gram.y"
 { symbol_t *symbols_inh; op_tree_t *op_tree; }
#line 230 "oxout.y"
;


struct yyyT12
#line 112 "gram.y"
 { symbol_t *symbols_inh; op_tree_t *op_tree; }
#line 237 "oxout.y"
;


struct yyyT13
#line 113 "gram.y"
 { symbol_t *symbols_inh; op_tree_t *op_tree; }
#line 244 "oxout.y"
;


struct yyyT14
#line 114 "gram.y"
 { symbol_t *symbols_inh; }
#line 251 "oxout.y"
;


struct yyyT15
#line 115 "gram.y"
 { symbol_t *symbols_inh; }
#line 258 "oxout.y"
;


struct yyyT16
#line 116 "gram.y"
 { symbol_t *symbols_inh; }
#line 265 "oxout.y"
;


struct yyyT17
#line 117 "gram.y"
 { symbol_t *symbols_inh; }
#line 272 "oxout.y"
;


struct yyyT18
#line 118 "gram.y"
 { symbol_t *symbols_inh; }
#line 279 "oxout.y"
;


union yyyAttrbs {
  struct yyyT1 yyyAttrb1;
  struct yyyT2 yyyAttrb2;
  struct yyyT3 yyyAttrb3;
  struct yyyT4 yyyAttrb4;
  struct yyyT5 yyyAttrb5;
  struct yyyT6 yyyAttrb6;
  struct yyyT7 yyyAttrb7;
  struct yyyT8 yyyAttrb8;
  struct yyyT9 yyyAttrb9;
  struct yyyT10 yyyAttrb10;
  struct yyyT11 yyyAttrb11;
  struct yyyT12 yyyAttrb12;
  struct yyyT13 yyyAttrb13;
  struct yyyT14 yyyAttrb14;
  struct yyyT15 yyyAttrb15;
  struct yyyT16 yyyAttrb16;
  struct yyyT17 yyyAttrb17;
  struct yyyT18 yyyAttrb18;
};
typedef unsigned short yyyWAT;
typedef unsigned short yyyRCT;
typedef unsigned short yyyPNT;
typedef unsigned short yyyWST;
 /* funny type; as wide as the widest of yyyWAT,yyyWST,yyyRCT  */
typedef unsigned short yyyFT;



typedef union{struct yyyStackItem *stackref; struct yyyGenNode *noderef;} yyyParent;
struct yyyGenNode {yyyParent parent;
                   short parentIsStack; /* =1 => `(yyySIT *)parent' is referenced on the Yacc semantic stack  */
                                        /* =0 => `(yyyGNT *)parent' is this node's parent node  */
                   int cLlen; /* length of child list */
                   struct yyyGenNode **cL; /* child list */
                   int refCountListLen; /* length of RCL */
                   yyyRCT *refCountList;
                   yyyPNT prodNum;
                   yyyWST whichSym; /* which child of parent? */
                   union yyyAttrbs yyyAttrbs; /* the Ox semantic attributes */
                  };

typedef struct yyyGenNode yyyGNT;


struct yyySolvedSAlistCell;
struct yyyStackItem {yyyGNT *node;
                     struct yyySolvedSAlistCell *solvedSAlist;
                    };

typedef struct yyyStackItem yyySIT;
extern void yyyabort(void);

%}

%{
struct yyyRSitem {yyyGNT *node;
                  yyyWST whichSym;
                  yyyWAT wa;
                 };

static struct yyyRSitem *yyyRS;
static long yyyRSTop = 0L;
#define yyyRSBottom 1L
static long yyyAfterRS = 1L;

#include <limits.h>
#define yyyR USHRT_MAX
%}
%type <yyyOxAttrbs> yyyAugNonterm
%union {
struct yyyOxAttrbsT {
struct yyyStackItem *yyyOxStackItem;
} yyyOxAttrbs;
}

%{
#include <stdio.h>
#include <stdarg.h>

static int yyyYok = 1;

static void yyyExecuteRRsection(yyyGNT *rootNode);
static void yyyDecorate(void);
#ifdef YYMSTA
struct yyyOxAttrbsT; /* hack required to compensate for `msta' behavior */
#endif
static void yyyGenIntNode(long yyyProdNum, int yyyRHSlength, int yyyNattrbs, __YYYSTRUCT yyyOxAttrbsT *yyval_OxAttrbs, ...);
static void yyyReclaimSemStkEls(int yyyRHSlength, ...);
static void yyyAdjustINRC(long yyyProdNum, int yyyRHSlength, long startP, long stopP, __YYYSTRUCT yyyOxAttrbsT *yyval_OxAttrbs, ...);
static void yyyCheckUnsolvedInstTrav(yyyGNT *rootNode,long *nNZrc,long *cycleSum);
static void yyyUnsolvedInstSearchTravAux(yyyGNT *pNode);

%}


#line 124 "gram.y"
%%
#line 381 "oxout.y"
yyyAugNonterm
	:		program
		{
		 yyyDecorate(); yyyExecuteRRsection($<yyyOxAttrbs>1.yyyOxStackItem->node);
		}
	;
#line 125 "gram.y"
program :    /* empty */
#line 390 "oxout.y"

{if(yyyYok){
yyyGenIntNode(1,0,0,&$<yyyOxAttrbs>$);
yyyAdjustINRC(1,0,0,0,&$<yyyOxAttrbs>$);
yyyReclaimSemStkEls(0);}}
#line 126 "gram.y"
        |    program funcdef ';'
#line 398 "oxout.y"

{if(yyyYok){
yyyGenIntNode(2,3,0,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyAdjustINRC(2,3,0,0,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyReclaimSemStkEls(3,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);}}
#line 127 "gram.y"
        ;

funcdef :    ID '(' ')' stats END
#line 408 "oxout.y"

{if(yyyYok){
yyyGenIntNode(3,5,1,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4,&$<yyyOxAttrbs>5);

#line 130 "gram.y"


#line 416 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb3.symbols_inh
#line 131 "gram.y"
 = NULL;

#line 421 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->cL[3]->yyyAttrbs.yyyAttrb6.symbols_inh
#line 132 "gram.y"
 =
#line 425 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb3.symbols_inh
#line 132 "gram.y"
;

#line 430 "oxout.y"
yyyAdjustINRC(3,5,0,6,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4,&$<yyyOxAttrbs>5);
yyyReclaimSemStkEls(5,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4,&$<yyyOxAttrbs>5);}}
#line 135 "gram.y"

        |    ID '(' pars ')' stats END
#line 436 "oxout.y"

{if(yyyYok){
yyyGenIntNode(4,6,1,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4,&$<yyyOxAttrbs>5,&$<yyyOxAttrbs>6);
yyyAdjustINRC(4,6,6,12,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4,&$<yyyOxAttrbs>5,&$<yyyOxAttrbs>6);
yyyReclaimSemStkEls(6,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4,&$<yyyOxAttrbs>5,&$<yyyOxAttrbs>6);}}
#line 142 "gram.y"

        ;

pars    :    pars ',' ID
#line 447 "oxout.y"

{if(yyyYok){
yyyGenIntNode(5,3,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyAdjustINRC(5,3,12,18,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyReclaimSemStkEls(3,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);}}
#line 152 "gram.y"

        |    ID
#line 456 "oxout.y"

{if(yyyYok){
yyyGenIntNode(6,1,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);

#line 154 "gram.y"


#line 155 "gram.y"
NEW_OP_TREE_NODE(
#line 466 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb4.op_tree
#line 155 "gram.y"
, VARDEF, NULL, NULL, 0,
#line 470 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 155 "gram.y"
)

#line 475 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb4.symbols_inh
#line 156 "gram.y"
 = new_symbol_node(
#line 479 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 156 "gram.y"
, VARIABLE);

#line 484 "oxout.y"
yyyAdjustINRC(6,1,18,24,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyReclaimSemStkEls(1,&$<yyyOxAttrbs>1);}}
#line 159 "gram.y"

        ;

stats    :    /* empty */
#line 492 "oxout.y"

{if(yyyYok){
yyyGenIntNode(7,0,2,&$<yyyOxAttrbs>$);

#line 163 "gram.y"


#line 500 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb6.symbols
#line 164 "gram.y"
 = NULL;
#line 504 "oxout.y"
yyyAdjustINRC(7,0,24,27,&$<yyyOxAttrbs>$);
yyyReclaimSemStkEls(0);}}
#line 165 "gram.y"

        |    stats stat ';'
#line 510 "oxout.y"

{if(yyyYok){
yyyGenIntNode(8,3,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyAdjustINRC(8,3,27,36,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyReclaimSemStkEls(3,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);}}
#line 172 "gram.y"

        |    stats vardef ';'
#line 519 "oxout.y"

{if(yyyYok){
yyyGenIntNode(9,3,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyAdjustINRC(9,3,36,45,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyReclaimSemStkEls(3,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);}}
#line 178 "gram.y"

        ;

stat    :    RETURN expr
#line 530 "oxout.y"

{if(yyyYok){
yyyGenIntNode(10,2,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyAdjustINRC(10,2,45,51,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyReclaimSemStkEls(2,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);}}
#line 187 "gram.y"

        |    cond
#line 539 "oxout.y"

{if(yyyYok){
yyyGenIntNode(11,1,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);

$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb9.op_tree
#line 191 "gram.y"
=NULL;
#line 547 "oxout.y"
yyyAdjustINRC(11,1,51,57,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyReclaimSemStkEls(1,&$<yyyOxAttrbs>1);}}
#line 192 "gram.y"

        |    ID '=' expr
#line 553 "oxout.y"

{if(yyyYok){
yyyGenIntNode(12,3,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);

$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb9.op_tree
#line 196 "gram.y"
=NULL;

#line 562 "oxout.y"
yyyAdjustINRC(12,3,57,63,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyReclaimSemStkEls(3,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);}}
#line 199 "gram.y"

        ;

vardef  :    VAR ID '=' expr
#line 570 "oxout.y"

{if(yyyYok){
yyyGenIntNode(13,4,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4);

#line 203 "gram.y"


#line 578 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb5.symbols
#line 204 "gram.y"
 = new_symbol_node(
#line 582 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->cL[1]->yyyAttrbs.yyyAttrb1.val
#line 204 "gram.y"
, VARIABLE);
#line 586 "oxout.y"
yyyAdjustINRC(13,4,63,69,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4);
yyyReclaimSemStkEls(4,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4);}}
#line 208 "gram.y"

        ;

cond    :    condlab COND guarded END
#line 594 "oxout.y"

{if(yyyYok){
yyyGenIntNode(14,4,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4);
yyyAdjustINRC(14,4,69,75,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4);
yyyReclaimSemStkEls(4,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4);}}
#line 219 "gram.y"

        ;

condlab :    /* empty */
#line 605 "oxout.y"

{if(yyyYok){
yyyGenIntNode(15,0,1,&$<yyyOxAttrbs>$);

#line 223 "gram.y"


#line 613 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb8.label
#line 224 "gram.y"
 = NULL;
#line 617 "oxout.y"
yyyAdjustINRC(15,0,75,78,&$<yyyOxAttrbs>$);
yyyReclaimSemStkEls(0);}}
#line 225 "gram.y"

        |    ID ':'
#line 623 "oxout.y"

{if(yyyYok){
yyyGenIntNode(16,2,1,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);

#line 227 "gram.y"


#line 631 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb8.label
#line 228 "gram.y"
 = new_symbol_node(
#line 635 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 228 "gram.y"
, LABEL);
#line 639 "oxout.y"
yyyAdjustINRC(16,2,78,81,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyReclaimSemStkEls(2,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);}}
#line 229 "gram.y"

        ;

guarded :    /* empty */
#line 647 "oxout.y"

{if(yyyYok){
yyyGenIntNode(17,0,1,&$<yyyOxAttrbs>$);
yyyAdjustINRC(17,0,81,81,&$<yyyOxAttrbs>$);
yyyReclaimSemStkEls(0);}}
#line 233 "gram.y"
        |    guarded expr RA stats contexp glab ';'
#line 655 "oxout.y"

{if(yyyYok){
yyyGenIntNode(18,7,1,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4,&$<yyyOxAttrbs>5,&$<yyyOxAttrbs>6,&$<yyyOxAttrbs>7);
yyyAdjustINRC(18,7,81,93,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4,&$<yyyOxAttrbs>5,&$<yyyOxAttrbs>6,&$<yyyOxAttrbs>7);
yyyReclaimSemStkEls(7,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4,&$<yyyOxAttrbs>5,&$<yyyOxAttrbs>6,&$<yyyOxAttrbs>7);}}
#line 239 "gram.y"

        |    guarded RA stats contexp glab ';'
#line 664 "oxout.y"

{if(yyyYok){
yyyGenIntNode(19,6,1,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4,&$<yyyOxAttrbs>5,&$<yyyOxAttrbs>6);
yyyAdjustINRC(19,6,93,102,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4,&$<yyyOxAttrbs>5,&$<yyyOxAttrbs>6);
yyyReclaimSemStkEls(6,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4,&$<yyyOxAttrbs>5,&$<yyyOxAttrbs>6);}}
#line 245 "gram.y"

        ;

glab    :    /* empty */
#line 675 "oxout.y"

{if(yyyYok){
yyyGenIntNode(20,0,1,&$<yyyOxAttrbs>$);
yyyAdjustINRC(20,0,102,102,&$<yyyOxAttrbs>$);
yyyReclaimSemStkEls(0);}}
#line 249 "gram.y"
        |    ID
#line 683 "oxout.y"

{if(yyyYok){
yyyGenIntNode(21,1,1,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyAdjustINRC(21,1,102,102,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyReclaimSemStkEls(1,&$<yyyOxAttrbs>1);}}
#line 249 "gram.y"

        ;

contexp :    CONTINUE
#line 694 "oxout.y"

{if(yyyYok){
yyyGenIntNode(22,1,0,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyAdjustINRC(22,1,102,102,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyReclaimSemStkEls(1,&$<yyyOxAttrbs>1);}}
#line 253 "gram.y"
        |    BREAK
#line 702 "oxout.y"

{if(yyyYok){
yyyGenIntNode(23,1,0,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyAdjustINRC(23,1,102,102,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyReclaimSemStkEls(1,&$<yyyOxAttrbs>1);}}
#line 254 "gram.y"
        ;

expr    :    term
#line 712 "oxout.y"

{if(yyyYok){
yyyGenIntNode(24,1,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyAdjustINRC(24,1,102,108,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyReclaimSemStkEls(1,&$<yyyOxAttrbs>1);}}
#line 260 "gram.y"

        |    listexp term
#line 721 "oxout.y"

{if(yyyYok){
yyyGenIntNode(25,2,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);

$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb12.op_tree
#line 264 "gram.y"
  = NULL;
#line 729 "oxout.y"
yyyAdjustINRC(25,2,108,114,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyReclaimSemStkEls(2,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);}}
#line 265 "gram.y"

        |    term addexp
#line 735 "oxout.y"

{if(yyyYok){
yyyGenIntNode(26,2,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyAdjustINRC(26,2,114,123,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyReclaimSemStkEls(2,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);}}
#line 272 "gram.y"

        |    term mulexp
#line 744 "oxout.y"

{if(yyyYok){
yyyGenIntNode(27,2,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);

$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb12.op_tree
#line 277 "gram.y"
  = NULL;
#line 752 "oxout.y"
yyyAdjustINRC(27,2,123,132,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyReclaimSemStkEls(2,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);}}
#line 278 "gram.y"

        |    term dotexp
#line 758 "oxout.y"

{if(yyyYok){
yyyGenIntNode(28,2,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);

$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb12.op_tree
#line 283 "gram.y"
  = NULL;
#line 766 "oxout.y"
yyyAdjustINRC(28,2,132,141,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyReclaimSemStkEls(2,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);}}
#line 284 "gram.y"

        |    term orexp
#line 772 "oxout.y"

{if(yyyYok){
yyyGenIntNode(29,2,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);

$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb12.op_tree
#line 289 "gram.y"
  = NULL;
#line 780 "oxout.y"
yyyAdjustINRC(29,2,141,150,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyReclaimSemStkEls(2,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);}}
#line 290 "gram.y"

        |    term GTEQ term
#line 786 "oxout.y"

{if(yyyYok){
yyyGenIntNode(30,3,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);

$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb12.op_tree
#line 295 "gram.y"
  = NULL;
#line 794 "oxout.y"
yyyAdjustINRC(30,3,150,159,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyReclaimSemStkEls(3,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);}}
#line 296 "gram.y"

        |    term '=' term
#line 800 "oxout.y"

{if(yyyYok){
yyyGenIntNode(31,3,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);

$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb12.op_tree
#line 301 "gram.y"
  = NULL;
#line 808 "oxout.y"
yyyAdjustINRC(31,3,159,168,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyReclaimSemStkEls(3,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);}}
#line 302 "gram.y"

        |    term '-' term
#line 814 "oxout.y"

{if(yyyYok){
yyyGenIntNode(32,3,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);

$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb12.op_tree
#line 307 "gram.y"
  = NULL;
#line 822 "oxout.y"
yyyAdjustINRC(32,3,168,177,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyReclaimSemStkEls(3,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);}}
#line 308 "gram.y"

        ;

listexp :    NOT
#line 830 "oxout.y"

{if(yyyYok){
yyyGenIntNode(33,1,0,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyAdjustINRC(33,1,177,177,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyReclaimSemStkEls(1,&$<yyyOxAttrbs>1);}}
#line 312 "gram.y"
        |    HEAD
#line 838 "oxout.y"

{if(yyyYok){
yyyGenIntNode(34,1,0,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyAdjustINRC(34,1,177,177,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyReclaimSemStkEls(1,&$<yyyOxAttrbs>1);}}
#line 313 "gram.y"
        |    TAIL
#line 846 "oxout.y"

{if(yyyYok){
yyyGenIntNode(35,1,0,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyAdjustINRC(35,1,177,177,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyReclaimSemStkEls(1,&$<yyyOxAttrbs>1);}}
#line 314 "gram.y"
        |    ISLIST
#line 854 "oxout.y"

{if(yyyYok){
yyyGenIntNode(36,1,0,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyAdjustINRC(36,1,177,177,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyReclaimSemStkEls(1,&$<yyyOxAttrbs>1);}}
#line 315 "gram.y"
        |    NOT listexp
#line 862 "oxout.y"

{if(yyyYok){
yyyGenIntNode(37,2,0,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyAdjustINRC(37,2,177,177,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyReclaimSemStkEls(2,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);}}
#line 316 "gram.y"
        |    HEAD listexp
#line 870 "oxout.y"

{if(yyyYok){
yyyGenIntNode(38,2,0,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyAdjustINRC(38,2,177,177,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyReclaimSemStkEls(2,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);}}
#line 317 "gram.y"
        |    TAIL listexp
#line 878 "oxout.y"

{if(yyyYok){
yyyGenIntNode(39,2,0,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyAdjustINRC(39,2,177,177,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyReclaimSemStkEls(2,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);}}
#line 318 "gram.y"
        |    ISLIST listexp
#line 886 "oxout.y"

{if(yyyYok){
yyyGenIntNode(40,2,0,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyAdjustINRC(40,2,177,177,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyReclaimSemStkEls(2,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);}}
#line 319 "gram.y"
        ;

addexp  :    '+' term addexp
#line 896 "oxout.y"

{if(yyyYok){
yyyGenIntNode(41,3,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyAdjustINRC(41,3,177,186,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyReclaimSemStkEls(3,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);}}
#line 326 "gram.y"

        |    '+' term
#line 905 "oxout.y"

{if(yyyYok){
yyyGenIntNode(42,2,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyAdjustINRC(42,2,186,192,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyReclaimSemStkEls(2,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);}}
#line 331 "gram.y"

        ;

mulexp  :    '*' term mulexp
#line 916 "oxout.y"

{if(yyyYok){
yyyGenIntNode(43,3,1,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyAdjustINRC(43,3,192,198,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyReclaimSemStkEls(3,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);}}
#line 338 "gram.y"

        |    '*' term
#line 925 "oxout.y"

{if(yyyYok){
yyyGenIntNode(44,2,1,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyAdjustINRC(44,2,198,201,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyReclaimSemStkEls(2,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);}}
#line 342 "gram.y"

        ;

dotexp  :    '.' term dotexp
#line 936 "oxout.y"

{if(yyyYok){
yyyGenIntNode(45,3,1,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyAdjustINRC(45,3,201,207,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyReclaimSemStkEls(3,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);}}
#line 349 "gram.y"

        |    '.' term
#line 945 "oxout.y"

{if(yyyYok){
yyyGenIntNode(46,2,1,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyAdjustINRC(46,2,207,210,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyReclaimSemStkEls(2,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);}}
#line 353 "gram.y"

        ;

orexp   :    OR term orexp
#line 956 "oxout.y"

{if(yyyYok){
yyyGenIntNode(47,3,1,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyAdjustINRC(47,3,210,216,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyReclaimSemStkEls(3,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);}}
#line 360 "gram.y"

        |    OR term
#line 965 "oxout.y"

{if(yyyYok){
yyyGenIntNode(48,2,1,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyAdjustINRC(48,2,216,219,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);
yyyReclaimSemStkEls(2,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2);}}
#line 364 "gram.y"

        ;

term    :    '(' expr ')'
#line 976 "oxout.y"

{if(yyyYok){
yyyGenIntNode(49,3,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyAdjustINRC(49,3,219,225,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyReclaimSemStkEls(3,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);}}
#line 371 "gram.y"

        |    NUM
#line 985 "oxout.y"

{if(yyyYok){
yyyGenIntNode(50,1,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);

#line 373 "gram.y"


#line 374 "gram.y"
NEW_OP_TREE_NODE(
#line 995 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb11.op_tree
#line 374 "gram.y"
, CONSTANT, NULL, NULL,
#line 999 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->cL[0]->yyyAttrbs.yyyAttrb2.val
#line 374 "gram.y"
, NULL);
#line 1003 "oxout.y"
yyyAdjustINRC(50,1,225,228,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyReclaimSemStkEls(1,&$<yyyOxAttrbs>1);}}
#line 375 "gram.y"

        |    ID
#line 1009 "oxout.y"

{if(yyyYok){
yyyGenIntNode(51,1,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);

#line 377 "gram.y"


#line 378 "gram.y"
NEW_OP_TREE_NODE(
#line 1019 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb11.op_tree
#line 378 "gram.y"
, VARUSE, NULL, NULL, 0,
#line 1023 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 378 "gram.y"
)

#line 1028 "oxout.y"
yyyAdjustINRC(51,1,228,231,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyReclaimSemStkEls(1,&$<yyyOxAttrbs>1);}}
#line 381 "gram.y"

        |    ID '(' ')'
#line 1034 "oxout.y"

{if(yyyYok){
yyyGenIntNode(52,3,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);

#line 383 "gram.y"


#line 1042 "oxout.y"
$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb11.op_tree
#line 384 "gram.y"
  = NULL;
#line 1046 "oxout.y"
yyyAdjustINRC(52,3,231,234,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyReclaimSemStkEls(3,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);}}
#line 385 "gram.y"

        |    ID '(' cargs ')'
#line 1052 "oxout.y"

{if(yyyYok){
yyyGenIntNode(53,4,2,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4);

$<yyyOxAttrbs>$.yyyOxStackItem->node->yyyAttrbs.yyyAttrb11.op_tree
#line 389 "gram.y"
  = NULL;
#line 1060 "oxout.y"
yyyAdjustINRC(53,4,234,240,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4);
yyyReclaimSemStkEls(4,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3,&$<yyyOxAttrbs>4);}}
#line 390 "gram.y"

        ;

cargs   :    cargs ',' expr
#line 1068 "oxout.y"

{if(yyyYok){
yyyGenIntNode(54,3,1,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyAdjustINRC(54,3,240,246,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);
yyyReclaimSemStkEls(3,&$<yyyOxAttrbs>1,&$<yyyOxAttrbs>2,&$<yyyOxAttrbs>3);}}
#line 397 "gram.y"

        |    expr
#line 1077 "oxout.y"

{if(yyyYok){
yyyGenIntNode(55,1,1,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyAdjustINRC(55,1,246,249,&$<yyyOxAttrbs>$,&$<yyyOxAttrbs>1);
yyyReclaimSemStkEls(1,&$<yyyOxAttrbs>1);}}
#line 401 "gram.y"

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
#line 1097 "oxout.y"
/* The maximum size of the Ready Set. */
static long yyyRSmaxSize =        0L;
/* The maximum size of the postdecoration-traversal stack; */
/* needed for a depth-first traversal of the parse tree. */
static long yyyTravStackMaxSize = 1000L;

struct yyySolvedSAlistCell {yyyWAT attrbNum;
                            struct yyySolvedSAlistCell *next;
                           };
typedef struct yyySolvedSAlistCell yyySSALC;

#define yyyLambdaSSAL (yyySSALC *) NULL
static yyySSALC *yyySSALCfreeList = yyyLambdaSSAL;



static yyyFT yyyRCIL[] = {
yyyR,0,0, 3,0,0, yyyR,0,1, 4,0,1, yyyR,0,1, yyyR,1,1,
yyyR,0,0, yyyR,1,0, yyyR,1,0, yyyR,1,1, 0,0,1, 1,0,2,
yyyR,1,2, 0,0,1, 1,0,2, yyyR,1,1, 1,0,1, yyyR,1,0,
0,1,1, yyyR,1,0, 2,0,1, yyyR,1,0, 3,0,1, yyyR,0,1,
2,0,2, yyyR,0,0, yyyR,0,0, 0,0,1, 1,0,1, 3,0,1,
5,0,1, 0,0,1, 2,0,1, 4,0,1, yyyR,1,1, 0,0,1,
yyyR,1,0, 1,0,1, yyyR,1,2, 0,0,1, 1,0,1, yyyR,1,0,
0,0,1, 1,0,1, yyyR,1,0, 0,0,1, 1,0,1, yyyR,1,0,
0,0,1, 1,0,1, yyyR,1,0, 0,0,1, 2,0,1, yyyR,1,0,
0,0,1, 2,0,1, yyyR,1,0, 0,0,1, 2,0,1, yyyR,1,2,
1,0,1, 2,0,1, yyyR,1,1, 1,0,1, 1,0,1, 2,0,1,
1,0,1, 1,0,1, 2,0,1, 1,0,1, 1,0,1, 2,0,1,
1,0,1, yyyR,1,1, 1,0,1, yyyR,1,0, yyyR,1,0, yyyR,1,0,
yyyR,1,0, 2,0,1, 0,0,1, 2,0,1, 0,0,1,
};

static short yyyIIIEL[] = {0,
0,1,5,11,18,22,24,25,29,33,
36,38,42,47,52,53,56,57,65,72,
73,75,77,79,81,84,87,90,93,96,
100,104,108,110,112,114,116,119,122,125,
128,132,135,139,142,146,149,153,156,160,
162,164,168,173,177,
};

static long yyyIIEL[] = {
0,0,0,0,1,1,2,3,3,3,5,5,
6,7,7,9,9,11,11,13,15,15,16,18,
19,21,23,25,27,27,29,31,33,33,35,35,
37,39,41,43,44,44,46,48,48,49,49,51,
53,54,54,55,55,56,57,58,58,59,60,61,
63,63,65,65,66,66,67,68,68,70,70,71,
71,72,73,74,74,74,74,74,76,78,80,80,
82,84,86,88,90,92,93,95,97,98,100,102,
103,105,107,107,109,111,113,113,115,117,119,119,
121,121,121,121,121,121,121,121,121,121,121,121,
121,121,121,121,121,121,121,121,121,123,123,125,
127,129,129,131,132,132,134,135,136,136,138,139,
139,141,142,143,143,145,146,146,148,149,150,150,
152,154,154,156,156,158,159,161,162,164,165,165,
165,167,168,168,169,169,170,171,171,173,174,
};

static long yyyIEL[] = {
0,0,0,0,0,0,2,2,
4,4,4,4,4,4,6,8,
12,12,12,16,16,16,20,22,
22,24,24,24,28,28,28,32,
32,34,36,36,36,38,40,40,
40,40,42,42,42,42,42,44,
44,46,46,46,48,50,52,52,
52,52,54,54,62,62,62,62,
62,62,62,68,68,68,68,68,
68,68,68,70,70,70,72,74,
74,74,74,78,78,78,80,80,
82,86,86,86,86,86,90,90,
90,90,90,94,94,94,94,94,
98,98,98,98,98,98,102,102,
102,102,102,102,106,106,106,106,
106,106,110,110,110,112,112,114,
116,116,116,118,122,122,122,122,
124,124,124,128,128,128,128,130,
130,130,134,134,134,134,136,136,
136,138,138,138,140,140,140,142,
142,142,144,144,144,144,146,146,
146,146,150,150,150,150,152,152,
152,
};

static yyyFT yyyEntL[] = {
5,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,
2,0,1,0,2,0,0,1,2,0,1,0,0,1,2,0,
0,1,2,0,0,1,1,1,3,0,4,0,0,1,3,0,
3,0,0,0,0,0,6,0,2,0,1,0,4,0,5,0,
1,0,3,0,1,0,0,1,2,0,2,0,1,0,0,1,
0,1,2,0,1,0,2,0,1,0,2,0,1,0,3,0,
1,0,3,0,1,0,3,0,1,0,2,0,3,0,0,1,
0,1,2,0,0,1,2,0,3,0,2,0,2,0,3,0,
2,0,2,0,3,0,2,0,2,0,0,1,0,1,0,1,
3,0,3,0,1,0,1,0,
};

#if defined(__GNUC__) || defined(__attribute__)
static void yyyfatal(const char *) __attribute__((noreturn));
#endif
static void yyyfatal(const char *msg)
{fputs(msg,stderr);exit(-1);}



static void yyySignalEnts(yyyGNT *node,long startP,long stopP)
  {yyyGNT *dumNode;

   while (startP < stopP)
     {
      if (!yyyEntL[startP]) dumNode = node;
      else dumNode = (node->cL)[yyyEntL[startP]-1];
      if (!(--((dumNode->refCountList)[yyyEntL[startP+1]]
              )
           )
         )
         {
          if (++yyyRSTop == yyyAfterRS)
             {/* reallocate 'yyyRS' data structure */
              yyyRSmaxSize += 500L;
              if ((yyyRS =
                   (struct yyyRSitem *)realloc(yyyRS,
                                               (size_t)((size_t)(yyyRSmaxSize+1)*sizeof(struct yyyRSitem)))
                  ) == (struct yyyRSitem *) NULL)
                 yyyfatal("malloc error in Ox Ready Set space allocation\n");
              yyyAfterRS = yyyRSmaxSize + 1;
             }
          yyyRS[yyyRSTop].node = dumNode;
          yyyRS[yyyRSTop].whichSym = yyyEntL[startP];
          yyyRS[yyyRSTop].wa = yyyEntL[startP+1];
         }
      startP += 2;
     }
  }



static void yyySolveAndSignal(void) {
static long yyyiDum;
static int yyyws,yyywa;
static yyyGNT *yyyRSTopN,*yyyRefN;
static yyyParent yyyRSTopNp;


yyyRSTopNp = (yyyRSTopN = yyyRS[yyyRSTop].node)->parent;
yyyRefN= (yyyws = (yyyRS[yyyRSTop].whichSym))?yyyRSTopNp.noderef:yyyRSTopN;
yyywa = yyyRS[yyyRSTop].wa;
yyyRSTop--;
switch(yyyRefN->prodNum) {
case 1:  /***Yacc rule 1***/
  switch (yyyws) {
  }
break;
case 2:  /***Yacc rule 2***/
  switch (yyyws) {
  case 2:  /**/

  break;
  }
break;
case 3:  /***Yacc rule 3***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/

  break;
  case 4:  /**/

  break;
  }
break;
case 4:  /***Yacc rule 4***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 0:

#line 137 "gram.y"


#line 1282 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb3.symbols_inh
#line 138 "gram.y"
 =
#line 1286 "oxout.y"
yyyRefN->cL[2]->yyyAttrbs.yyyAttrb4.symbols_inh
#line 138 "gram.y"
;
#line 1290 "oxout.y"
    yyySignalEnts(yyyRefN,0,2);
    break;
    }
  break;
  case 1:  /**/

  break;
  case 3:  /**/

  break;
  case 5:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb6.symbols_inh
#line 139 "gram.y"
 =
#line 1308 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb3.symbols_inh
#line 139 "gram.y"
;

#line 1313 "oxout.y"
    break;
    }
  break;
  }
break;
case 5:  /***Yacc rule 5***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 0:

#line 146 "gram.y"


#line 1328 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb4.symbols_inh
#line 147 "gram.y"
 = append_symbol_node(new_symbol_node(
#line 1332 "oxout.y"
yyyRefN->cL[2]->yyyAttrbs.yyyAttrb1.val
#line 147 "gram.y"
, VARIABLE),
#line 1336 "oxout.y"
yyyRefN->cL[0]->yyyAttrbs.yyyAttrb4.symbols_inh
#line 147 "gram.y"
);
#line 1340 "oxout.y"
    break;
    case 1:

#line 148 "gram.y"
NEW_OP_TREE_NODE(
#line 1346 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb4.op_tree
#line 148 "gram.y"
, VARDEF,
#line 1350 "oxout.y"
yyyRefN->cL[0]->yyyAttrbs.yyyAttrb4.op_tree
#line 148 "gram.y"
, NULL, 0,
#line 1354 "oxout.y"
yyyRefN->cL[2]->yyyAttrbs.yyyAttrb1.val
#line 148 "gram.y"
)

#line 1359 "oxout.y"
    break;
    }
  break;
  case 1:  /**/

  break;
  case 3:  /**/

  break;
  }
break;
case 6:  /***Yacc rule 6***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/

  break;
  }
break;
case 7:  /***Yacc rule 7***/
  switch (yyyws) {
  case 0:  /**/

  break;
  }
break;
case 8:  /***Yacc rule 8***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 1:

#line 167 "gram.y"


#line 1397 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb6.symbols
#line 168 "gram.y"
 =
#line 1401 "oxout.y"
yyyRefN->cL[0]->yyyAttrbs.yyyAttrb6.symbols
#line 168 "gram.y"
;
#line 1405 "oxout.y"
    yyySignalEnts(yyyRefN,20,22);
    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb6.symbols_inh
#line 169 "gram.y"
 =
#line 1417 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb6.symbols_inh
#line 169 "gram.y"
;

#line 1422 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb9.symbols_inh
#line 171 "gram.y"
 = symbols_merge(
#line 1433 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb6.symbols_inh
#line 171 "gram.y"
,
#line 1437 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb6.symbols
#line 171 "gram.y"
);
#line 1441 "oxout.y"
    break;
    }
  break;
  }
break;
case 9:  /***Yacc rule 9***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 1:

#line 174 "gram.y"


#line 1456 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb6.symbols
#line 175 "gram.y"
 = append_symbol_node(
#line 1460 "oxout.y"
yyyRefN->cL[1]->yyyAttrbs.yyyAttrb5.symbols
#line 175 "gram.y"
,
#line 1464 "oxout.y"
yyyRefN->cL[0]->yyyAttrbs.yyyAttrb6.symbols
#line 175 "gram.y"
);
#line 1468 "oxout.y"
    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb6.symbols_inh
#line 176 "gram.y"
 =
#line 1479 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb6.symbols_inh
#line 176 "gram.y"
;
#line 1483 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb5.symbols_inh
#line 177 "gram.y"
 = symbols_merge(
#line 1494 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb6.symbols_inh
#line 177 "gram.y"
,
#line 1498 "oxout.y"
yyyRefN->cL[0]->yyyAttrbs.yyyAttrb6.symbols
#line 177 "gram.y"
);
#line 1502 "oxout.y"
    break;
    }
  break;
  }
break;
case 10:  /***Yacc rule 10***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 1:

#line 184 "gram.y"
NEW_OP_TREE_NODE(
#line 1516 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb9.op_tree
#line 184 "gram.y"
, RET,
#line 1520 "oxout.y"
yyyRefN->cL[1]->yyyAttrbs.yyyAttrb12.op_tree
#line 184 "gram.y"
, NULL, 0, NULL);

#line 1525 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

#line 182 "gram.y"


#line 1536 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 183 "gram.y"
 =
#line 1540 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb9.symbols_inh
#line 183 "gram.y"
;
#line 1544 "oxout.y"
    break;
    }
  break;
  }
break;
case 11:  /***Yacc rule 11***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/
    switch (yyywa) {
    case 1:

#line 189 "gram.y"


#line 1562 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb7.symbols_inh
#line 190 "gram.y"
 =
#line 1566 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb9.symbols_inh
#line 190 "gram.y"
;
#line 1570 "oxout.y"
    break;
    }
  break;
  }
break;
case 12:  /***Yacc rule 12***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/

  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:

#line 194 "gram.y"


#line 1591 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 195 "gram.y"
 =
#line 1595 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb9.symbols_inh
#line 195 "gram.y"
;
#line 1599 "oxout.y"
    break;
    }
  break;
  }
break;
case 13:  /***Yacc rule 13***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 2:  /**/

  break;
  case 4:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 205 "gram.y"
 =
#line 1620 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb5.symbols_inh
#line 205 "gram.y"
;

#line 1625 "oxout.y"
    break;
    }
  break;
  }
break;
case 14:  /***Yacc rule 14***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 0:

#line 212 "gram.y"


#line 1640 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb7.label
#line 213 "gram.y"
 =
#line 1644 "oxout.y"
yyyRefN->cL[0]->yyyAttrbs.yyyAttrb8.label
#line 213 "gram.y"
;
#line 1648 "oxout.y"
    yyySignalEnts(yyyRefN,46,48);
    break;
    }
  break;
  case 1:  /**/

  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb10.symbols_inh
#line 214 "gram.y"
 =
#line 1663 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb7.label
#line 214 "gram.y"
 == NULL
                        ?
#line 1668 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb7.symbols_inh
#line 215 "gram.y"

                        : append_symbol_node(
#line 1673 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb7.label
#line 216 "gram.y"
,
#line 1677 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb7.symbols_inh
#line 216 "gram.y"
);

#line 1682 "oxout.y"
    break;
    }
  break;
  }
break;
case 15:  /***Yacc rule 15***/
  switch (yyyws) {
  case 0:  /**/

  break;
  }
break;
case 16:  /***Yacc rule 16***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/

  break;
  }
break;
case 17:  /***Yacc rule 17***/
  switch (yyyws) {
  case 0:  /**/

  break;
  }
break;
case 18:  /***Yacc rule 18***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb10.symbols_inh
#line 236 "gram.y"
 =
#line 1724 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb10.symbols_inh
#line 236 "gram.y"
;
#line 1728 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 237 "gram.y"
 =
#line 1739 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb10.symbols_inh
#line 237 "gram.y"
;
#line 1743 "oxout.y"
    break;
    }
  break;
  case 4:  /**/
    switch (yyywa) {
    case 0:

#line 234 "gram.y"


#line 1754 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb6.symbols_inh
#line 235 "gram.y"
 =
#line 1758 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb10.symbols_inh
#line 235 "gram.y"
;
#line 1762 "oxout.y"
    break;
    }
  break;
  case 6:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb18.symbols_inh
#line 238 "gram.y"
 =
#line 1773 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb10.symbols_inh
#line 238 "gram.y"
;
#line 1777 "oxout.y"
    break;
    }
  break;
  }
break;
case 19:  /***Yacc rule 19***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb10.symbols_inh
#line 243 "gram.y"
 =
#line 1795 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb10.symbols_inh
#line 243 "gram.y"
;
#line 1799 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:

#line 241 "gram.y"


#line 1810 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb6.symbols_inh
#line 242 "gram.y"
 =
#line 1814 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb10.symbols_inh
#line 242 "gram.y"
;
#line 1818 "oxout.y"
    break;
    }
  break;
  case 5:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb18.symbols_inh
#line 244 "gram.y"
 =
#line 1829 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb10.symbols_inh
#line 244 "gram.y"
;
#line 1833 "oxout.y"
    break;
    }
  break;
  }
break;
case 20:  /***Yacc rule 20***/
  switch (yyyws) {
  case 0:  /**/

  break;
  }
break;
case 21:  /***Yacc rule 21***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/

  break;
  }
break;
case 22:  /***Yacc rule 22***/
  switch (yyyws) {
  }
break;
case 23:  /***Yacc rule 23***/
  switch (yyyws) {
  }
break;
case 24:  /***Yacc rule 24***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 1:

yyyRSTopN->yyyAttrbs.yyyAttrb12.op_tree
#line 259 "gram.y"
  =
#line 1873 "oxout.y"
yyyRefN->cL[0]->yyyAttrbs.yyyAttrb11.op_tree
#line 259 "gram.y"
;
#line 1877 "oxout.y"
    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:

#line 257 "gram.y"


#line 1888 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 258 "gram.y"
 =
#line 1892 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 258 "gram.y"
;
#line 1896 "oxout.y"
    break;
    }
  break;
  }
break;
case 25:  /***Yacc rule 25***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

#line 262 "gram.y"


#line 1914 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 263 "gram.y"
 =
#line 1918 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 263 "gram.y"
;
#line 1922 "oxout.y"
    break;
    }
  break;
  }
break;
case 26:  /***Yacc rule 26***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 1:

#line 271 "gram.y"
NEW_OP_TREE_NODE(
#line 1936 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb12.op_tree
#line 271 "gram.y"
, ADD,
#line 1940 "oxout.y"
yyyRefN->cL[0]->yyyAttrbs.yyyAttrb11.op_tree
#line 271 "gram.y"
,
#line 1944 "oxout.y"
yyyRefN->cL[1]->yyyAttrbs.yyyAttrb13.op_tree
#line 271 "gram.y"
, 0, NULL);
#line 1948 "oxout.y"
    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:

#line 267 "gram.y"


#line 1959 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 268 "gram.y"
 =
#line 1963 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 268 "gram.y"
;
#line 1967 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb13.symbols_inh
#line 269 "gram.y"
 =
#line 1978 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 269 "gram.y"
;

#line 1983 "oxout.y"
    break;
    }
  break;
  }
break;
case 27:  /***Yacc rule 27***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:

#line 274 "gram.y"


#line 2001 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 275 "gram.y"
 =
#line 2005 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 275 "gram.y"
;
#line 2009 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb14.symbols_inh
#line 276 "gram.y"
 =
#line 2020 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 276 "gram.y"
;
#line 2024 "oxout.y"
    break;
    }
  break;
  }
break;
case 28:  /***Yacc rule 28***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:

#line 280 "gram.y"


#line 2042 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 281 "gram.y"
 =
#line 2046 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 281 "gram.y"
;
#line 2050 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb15.symbols_inh
#line 282 "gram.y"
 =
#line 2061 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 282 "gram.y"
;
#line 2065 "oxout.y"
    break;
    }
  break;
  }
break;
case 29:  /***Yacc rule 29***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:

#line 286 "gram.y"


#line 2083 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 287 "gram.y"
 =
#line 2087 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 287 "gram.y"
;
#line 2091 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb16.symbols_inh
#line 288 "gram.y"
 =
#line 2102 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 288 "gram.y"
;
#line 2106 "oxout.y"
    break;
    }
  break;
  }
break;
case 30:  /***Yacc rule 30***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:

#line 292 "gram.y"


#line 2124 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 293 "gram.y"
 =
#line 2128 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 293 "gram.y"
;
#line 2132 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 294 "gram.y"
 =
#line 2143 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 294 "gram.y"
;
#line 2147 "oxout.y"
    break;
    }
  break;
  }
break;
case 31:  /***Yacc rule 31***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:

#line 298 "gram.y"


#line 2165 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 299 "gram.y"
 =
#line 2169 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 299 "gram.y"
;
#line 2173 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 300 "gram.y"
 =
#line 2184 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 300 "gram.y"
;
#line 2188 "oxout.y"
    break;
    }
  break;
  }
break;
case 32:  /***Yacc rule 32***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:

#line 304 "gram.y"


#line 2206 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 305 "gram.y"
 =
#line 2210 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 305 "gram.y"
;
#line 2214 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 306 "gram.y"
 =
#line 2225 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 306 "gram.y"
;
#line 2229 "oxout.y"
    break;
    }
  break;
  }
break;
case 33:  /***Yacc rule 33***/
  switch (yyyws) {
  }
break;
case 34:  /***Yacc rule 34***/
  switch (yyyws) {
  }
break;
case 35:  /***Yacc rule 35***/
  switch (yyyws) {
  }
break;
case 36:  /***Yacc rule 36***/
  switch (yyyws) {
  }
break;
case 37:  /***Yacc rule 37***/
  switch (yyyws) {
  }
break;
case 38:  /***Yacc rule 38***/
  switch (yyyws) {
  }
break;
case 39:  /***Yacc rule 39***/
  switch (yyyws) {
  }
break;
case 40:  /***Yacc rule 40***/
  switch (yyyws) {
  }
break;
case 41:  /***Yacc rule 41***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 1:

#line 325 "gram.y"
NEW_OP_TREE_NODE(
#line 2275 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb13.op_tree
#line 325 "gram.y"
, ADD,
#line 2279 "oxout.y"
yyyRefN->cL[1]->yyyAttrbs.yyyAttrb11.op_tree
#line 325 "gram.y"
,
#line 2283 "oxout.y"
yyyRefN->cL[2]->yyyAttrbs.yyyAttrb13.op_tree
#line 325 "gram.y"
, 0, NULL);
#line 2287 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 324 "gram.y"
 =
#line 2298 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb13.symbols_inh
#line 324 "gram.y"
;
#line 2302 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:

#line 322 "gram.y"


#line 2313 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb13.symbols_inh
#line 323 "gram.y"
 =
#line 2317 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb13.symbols_inh
#line 323 "gram.y"
;
#line 2321 "oxout.y"
    break;
    }
  break;
  }
break;
case 42:  /***Yacc rule 42***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 1:

yyyRSTopN->yyyAttrbs.yyyAttrb13.op_tree
#line 330 "gram.y"
 =
#line 2336 "oxout.y"
yyyRefN->cL[1]->yyyAttrbs.yyyAttrb11.op_tree
#line 330 "gram.y"
;
#line 2340 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

#line 328 "gram.y"


#line 2351 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 329 "gram.y"
 =
#line 2355 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb13.symbols_inh
#line 329 "gram.y"
;
#line 2359 "oxout.y"
    break;
    }
  break;
  }
break;
case 43:  /***Yacc rule 43***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 337 "gram.y"
 =
#line 2377 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb14.symbols_inh
#line 337 "gram.y"
;
#line 2381 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:

#line 335 "gram.y"


#line 2392 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb14.symbols_inh
#line 336 "gram.y"
 =
#line 2396 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb14.symbols_inh
#line 336 "gram.y"
;
#line 2400 "oxout.y"
    break;
    }
  break;
  }
break;
case 44:  /***Yacc rule 44***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

#line 340 "gram.y"


#line 2418 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 341 "gram.y"
 =
#line 2422 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb14.symbols_inh
#line 341 "gram.y"
;
#line 2426 "oxout.y"
    break;
    }
  break;
  }
break;
case 45:  /***Yacc rule 45***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 348 "gram.y"
 =
#line 2444 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb15.symbols_inh
#line 348 "gram.y"
;
#line 2448 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:

#line 346 "gram.y"


#line 2459 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb15.symbols_inh
#line 347 "gram.y"
 =
#line 2463 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb15.symbols_inh
#line 347 "gram.y"
;
#line 2467 "oxout.y"
    break;
    }
  break;
  }
break;
case 46:  /***Yacc rule 46***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

#line 351 "gram.y"


#line 2485 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 352 "gram.y"
 =
#line 2489 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb15.symbols_inh
#line 352 "gram.y"
;
#line 2493 "oxout.y"
    break;
    }
  break;
  }
break;
case 47:  /***Yacc rule 47***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 359 "gram.y"
 =
#line 2511 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb16.symbols_inh
#line 359 "gram.y"
;
#line 2515 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:

#line 357 "gram.y"


#line 2526 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb16.symbols_inh
#line 358 "gram.y"
 =
#line 2530 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb16.symbols_inh
#line 358 "gram.y"
;
#line 2534 "oxout.y"
    break;
    }
  break;
  }
break;
case 48:  /***Yacc rule 48***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

#line 362 "gram.y"


#line 2552 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 363 "gram.y"
 =
#line 2556 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb16.symbols_inh
#line 363 "gram.y"
;
#line 2560 "oxout.y"
    break;
    }
  break;
  }
break;
case 49:  /***Yacc rule 49***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 1:

yyyRSTopN->yyyAttrbs.yyyAttrb11.op_tree
#line 370 "gram.y"
  =
#line 2575 "oxout.y"
yyyRefN->cL[1]->yyyAttrbs.yyyAttrb12.op_tree
#line 370 "gram.y"
;
#line 2579 "oxout.y"
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:

#line 368 "gram.y"


#line 2590 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 369 "gram.y"
 =
#line 2594 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 369 "gram.y"
;
#line 2598 "oxout.y"
    break;
    }
  break;
  }
break;
case 50:  /***Yacc rule 50***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/

  break;
  }
break;
case 51:  /***Yacc rule 51***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/

  break;
  }
break;
case 52:  /***Yacc rule 52***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/

  break;
  }
break;
case 53:  /***Yacc rule 53***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/

  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:

#line 387 "gram.y"


#line 2649 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb17.symbols_inh
#line 388 "gram.y"
 =
#line 2653 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb11.symbols_inh
#line 388 "gram.y"
;
#line 2657 "oxout.y"
    break;
    }
  break;
  }
break;
case 54:  /***Yacc rule 54***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:

#line 394 "gram.y"


#line 2675 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb17.symbols_inh
#line 395 "gram.y"
 =
#line 2679 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb17.symbols_inh
#line 395 "gram.y"
;
#line 2683 "oxout.y"
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:

yyyRSTopN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 396 "gram.y"
 =
#line 2694 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb17.symbols_inh
#line 396 "gram.y"
;
#line 2698 "oxout.y"
    break;
    }
  break;
  }
break;
case 55:  /***Yacc rule 55***/
  switch (yyyws) {
  case 0:  /**/

  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:

#line 399 "gram.y"


#line 2716 "oxout.y"
yyyRSTopN->yyyAttrbs.yyyAttrb12.symbols_inh
#line 400 "gram.y"
 =
#line 2720 "oxout.y"
yyyRefN->yyyAttrbs.yyyAttrb17.symbols_inh
#line 400 "gram.y"
;
#line 2724 "oxout.y"
    break;
    }
  break;
  }
break;
} /* switch */

if (yyyws)  /* the just-solved instance was inherited. */
   {if (yyyRSTopN->prodNum)
       {yyyiDum = yyyIIEL[yyyIIIEL[yyyRSTopN->prodNum]] + yyywa;
        yyySignalEnts(yyyRSTopN,yyyIEL[yyyiDum],
                                yyyIEL[yyyiDum+1]
                     );
       }
   }
else     /* the just-solved instance was synthesized. */
   {if (!(yyyRSTopN->parentIsStack)) /* node has a parent. */
       {yyyiDum = yyyIIEL[yyyIIIEL[yyyRSTopNp.noderef->prodNum] +
                          yyyRSTopN->whichSym
                         ] +
                  yyywa;
        yyySignalEnts(yyyRSTopNp.noderef,
                      yyyIEL[yyyiDum],
                      yyyIEL[yyyiDum+1]
                     );
       }
    else   /* node is still on the stack--it has no parent yet. */
       {yyySSALC **yyypL = &(yyyRSTopNp.stackref->solvedSAlist);
        yyySSALC *yyyiDum;
        if (yyySSALCfreeList == yyyLambdaSSAL)
           {yyyiDum = (yyySSALC *) malloc((size_t)sizeof(yyySSALC));
            if (yyyiDum == yyyLambdaSSAL)
               yyyfatal("malloc error in Ox Stack Solved List space allocation\n");
           }
        else
           {yyyiDum = yyySSALCfreeList;
            yyySSALCfreeList = yyySSALCfreeList->next;
           }
        yyyiDum->next = *yyypL;
        yyyiDum->attrbNum = (yyyWAT)yyywa;
        *yyypL = yyyiDum;
       }
   }

} /* yyySolveAndSignal */



#define condStg unsigned int conds;
#define yyyClearConds {yyyTravStack[yyyTST].conds = 0;}
#define yyySetCond(n) {yyyTravStack[yyyTST].conds += (1<<(n));}
#define yyyCond(n) ((yyyTravStack[yyyTST].conds & (1<<(n)))?1:0)



struct yyyTravStackItem {yyyGNT *node;
                         char isReady;
                         condStg
                        };



static void yyyDoTraversals(yyyGNT *rootNode)
{struct yyyTravStackItem *yyyTravStack;
 long yyyTST,yyyAfterTravStack;
 yyyGNT *yyyTSTn,**yyyCLptr2;
 int yyyRL=0,yyyPass;
 int i;

 if (!yyyYok) return;
 if ((yyyTravStack =
                 ((struct yyyTravStackItem *)
                  calloc((size_t)yyyTravStackMaxSize,
                         (size_t)sizeof(struct yyyTravStackItem)
                        )
                 )
     )
     ==
     (struct yyyTravStackItem *) NULL
    )
    yyyfatal("malloc error in Ox Traversal Stack allocation\n");

yyyAfterTravStack = yyyTravStackMaxSize;
#define yyyTSBottom 1L


for (int yyyi=0; yyyi<3; yyyi++) {
yyyTST = 1L;
yyyTravStack[yyyTST].node = rootNode;
yyyTravStack[yyyTST].isReady = 0;
yyyClearConds

while(yyyTST >= yyyTSBottom)
  {yyyTSTn = yyyTravStack[yyyTST].node;
   if (yyyTravStack[yyyTST].isReady)
      {yyyPass = 1;
       goto yyyTravSwitch;
yyyTpop:
       yyyTST--;
      }
   else
      {yyyPass = 0;
       goto yyyTravSwitch;
yyyTpush:
       yyyTravStack[yyyTST].isReady = 1;
       if (yyyTSTn->prodNum)
          {if (yyyRL)
             {yyyCLptr2 = yyyTSTn->cL;
              i = yyyTSTn->cLlen;
              while (i--)
                {if (++yyyTST == yyyAfterTravStack)
                    {/* realloc `yyyTravStack' data structure */
                     yyyTravStackMaxSize += 500L;
                     if ((yyyTravStack = (struct yyyTravStackItem *)
                          realloc(yyyTravStack,
                                  (size_t)((size_t)yyyTravStackMaxSize*sizeof(struct yyyTravStackItem)))
                         ) == (struct yyyTravStackItem *) NULL)
                        yyyfatal("malloc error in Ox Traversal Stack allocation\n");
                     yyyAfterTravStack = yyyTravStackMaxSize;
                    }
                 yyyTravStack[yyyTST].node = *yyyCLptr2;
                 yyyTravStack[yyyTST].isReady = 0;
                 yyyClearConds
                 yyyCLptr2++;
                }
             } /* right to left */
          else  /* left to right */
             {i = yyyTSTn->cLlen;
              yyyCLptr2 = yyyTSTn->cL + i;
              while (i--)
                {yyyCLptr2--;
                 if (++yyyTST == yyyAfterTravStack)
                    {/* realloc `yyyTravStack' data structure */
                     yyyTravStackMaxSize += 500L;
                     if ((yyyTravStack = (struct yyyTravStackItem *)
                          realloc(yyyTravStack,
                                  (size_t)((size_t)yyyTravStackMaxSize*sizeof(struct yyyTravStackItem)))
                         ) == (struct yyyTravStackItem *) NULL)
                        yyyfatal("malloc error in Ox Traversal Stack allocation\n");
                     yyyAfterTravStack = yyyTravStackMaxSize;
                    }
                  yyyTravStack[yyyTST].node = *yyyCLptr2;
                  yyyTravStack[yyyTST].isReady = 0;
                  yyyClearConds
                }
             } /* left to right */
          }
      } /* else */
   continue;
yyyTravSwitch:
				switch(yyyTSTn->prodNum)	{
case 1:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 2:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 3:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) {
#line 134 "gram.y"
 printf(".text\n.globl %s\n.globl _%s\n%s:\n_%s:\n",
#line 2961 "oxout.y"
yyyTSTn->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 134 "gram.y"
,
#line 2965 "oxout.y"
yyyTSTn->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 134 "gram.y"
,
#line 2969 "oxout.y"
yyyTSTn->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 134 "gram.y"
,
#line 2973 "oxout.y"
yyyTSTn->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 134 "gram.y"
);
#line 2977 "oxout.y"
}
				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 4:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) {
#line 141 "gram.y"
 printf(".text\n.globl %s\n.globl _%s\n%s:\n_%s:\n",
#line 3015 "oxout.y"
yyyTSTn->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 141 "gram.y"
,
#line 3019 "oxout.y"
yyyTSTn->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 141 "gram.y"
,
#line 3023 "oxout.y"
yyyTSTn->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 141 "gram.y"
,
#line 3027 "oxout.y"
yyyTSTn->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 141 "gram.y"
);
#line 3031 "oxout.y"
}
				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 5:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) {
#line 150 "gram.y"
 check_symbol_def(
#line 3060 "oxout.y"
yyyTSTn->cL[2]->yyyAttrbs.yyyAttrb1.val
#line 150 "gram.y"
,
#line 3064 "oxout.y"
yyyTSTn->cL[0]->yyyAttrbs.yyyAttrb4.symbols_inh
#line 150 "gram.y"
);
#line 3068 "oxout.y"
}
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) {
#line 151 "gram.y"
 CALL_CODEGEN(
#line 3091 "oxout.y"
yyyTSTn->yyyAttrbs.yyyAttrb4.op_tree
#line 151 "gram.y"
);
#line 3095 "oxout.y"
}
				break;
					}
		break;
			}

break;
case 6:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) {
#line 158 "gram.y"
 CALL_CODEGEN(
#line 3132 "oxout.y"
yyyTSTn->yyyAttrbs.yyyAttrb4.op_tree
#line 158 "gram.y"
);
#line 3136 "oxout.y"
}
				break;
					}
		break;
			}

break;
case 7:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 8:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 9:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 10:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) {
#line 186 "gram.y"
 CALL_CODEGEN(
#line 3269 "oxout.y"
yyyTSTn->yyyAttrbs.yyyAttrb9.op_tree
#line 186 "gram.y"
);
#line 3273 "oxout.y"
}
				break;
					}
		break;
			}

break;
case 11:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 12:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) {
#line 198 "gram.y"
 check_symbol_usage(
#line 3325 "oxout.y"
yyyTSTn->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 198 "gram.y"
, VARIABLE,
#line 3329 "oxout.y"
yyyTSTn->yyyAttrbs.yyyAttrb9.symbols_inh
#line 198 "gram.y"
);
#line 3333 "oxout.y"
}
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 13:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) {
#line 207 "gram.y"
 check_symbol_def(
#line 3371 "oxout.y"
yyyTSTn->cL[1]->yyyAttrbs.yyyAttrb1.val
#line 207 "gram.y"
,
#line 3375 "oxout.y"
yyyTSTn->yyyAttrbs.yyyAttrb5.symbols_inh
#line 207 "gram.y"
);
#line 3379 "oxout.y"
}
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 14:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) {
#line 218 "gram.y"
 if(
#line 3417 "oxout.y"
yyyTSTn->yyyAttrbs.yyyAttrb7.label
#line 218 "gram.y"
 != NULL) check_symbol_def(
#line 3421 "oxout.y"
yyyTSTn->yyyAttrbs.yyyAttrb7.label
#line 218 "gram.y"
->name,
#line 3425 "oxout.y"
yyyTSTn->yyyAttrbs.yyyAttrb7.symbols_inh
#line 218 "gram.y"
);
#line 3429 "oxout.y"
}
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 15:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 16:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 17:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 18:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 19:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 20:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 21:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) {
#line 249 "gram.y"
 check_symbol_usage(
#line 3659 "oxout.y"
yyyTSTn->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 249 "gram.y"
, LABEL,
#line 3663 "oxout.y"
yyyTSTn->yyyAttrbs.yyyAttrb18.symbols_inh
#line 249 "gram.y"
);
#line 3667 "oxout.y"
}
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 22:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 23:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 24:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 25:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 26:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 27:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 28:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 29:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 30:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 31:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 32:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 33:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 34:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 35:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 36:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 37:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 38:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 39:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 40:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 41:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 42:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 43:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 44:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 45:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 46:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 47:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 48:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 49:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 50:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 51:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) {
#line 380 "gram.y"
 check_symbol_usage(
#line 4633 "oxout.y"
yyyTSTn->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 380 "gram.y"
, VARIABLE,
#line 4637 "oxout.y"
yyyTSTn->yyyAttrbs.yyyAttrb11.symbols_inh
#line 380 "gram.y"
);
#line 4641 "oxout.y"
}
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 52:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 53:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 54:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 55:
	switch(yyyi)	{
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
								} /* switch */
   if (yyyPass) goto yyyTpop; else goto yyyTpush;
  } /* while */
 } /* for */
} /* yyyDoTraversals */

static void yyyExecuteRRsection(yyyGNT *rootNode)  {
   long cycleSum = 0;
   long nNZrc = 0;

   if (!yyyYok) return;
   yyyCheckUnsolvedInstTrav(rootNode,&nNZrc,&cycleSum);
   if (nNZrc)
      {
       fputs("\n\n\n**********\n",stderr);
       fputs("cycle detected in completed parse tree",stderr);
       fputs(" after decoration.\n",stderr);
#if CYCLE_VERBOSE
       fprintf(stderr,
               "number of unsolved attribute instances == %ld.\n",
               nNZrc
              );
       fprintf(stderr,
               "total number of remaining dependencies == %ld.\n",
               cycleSum
              );
       fputs("average number of remaining dependencies\n",stderr);
       fprintf(stderr,"  per unsolved instance == %f.\n",
               ((float)(cycleSum)/(float)(nNZrc))
              );
#endif
       fprintf(stderr,
         "searching parse tree for %ld unsolved instances:\n",
               nNZrc
              );
       yyyUnsolvedInstSearchTravAux(rootNode);
      }
   yyyDoTraversals(rootNode);
} /* yyyExecuteRRsection */



static yyyWAT yyyLRCIL[2] = {0,0,
};



static void yyyDecorate(void)
  {
   while (yyyRSTop >= yyyRSBottom)
      yyySolveAndSignal();
  }



static void yyyGenIntNode(long yyyProdNum, int yyyRHSlength, int yyyNattrbs, __YYYSTRUCT yyyOxAttrbsT *yyval_OxAttrbs, ...)
  {
   yyySIT **yyyOxStackItem = &yyval_OxAttrbs->yyyOxStackItem;
   va_list ap;

   *yyyOxStackItem = (yyySIT *) malloc((size_t)sizeof(yyySIT));
   if (*yyyOxStackItem == (yyySIT *) NULL)
      yyyfatal("malloc error in Ox/Yacc semantic stack space allocation\n");
   (*yyyOxStackItem)->node =
                                (yyyGNT *) malloc((size_t)sizeof(yyyGNT));
   if ((*yyyOxStackItem)->node == (yyyGNT *) NULL)
      yyyfatal("malloc error in Ox Semantic Node space allocation\n");
   (*yyyOxStackItem)->solvedSAlist = yyyLambdaSSAL;
   (*yyyOxStackItem)->node->parent.stackref = *yyyOxStackItem;
   (*yyyOxStackItem)->node->parentIsStack = 1;
   (*yyyOxStackItem)->node->cLlen  = yyyRHSlength;
   (*yyyOxStackItem)->node->cL =
            (yyyGNT **) calloc((size_t)yyyRHSlength, (size_t)sizeof(yyyGNT *));
   if ((*yyyOxStackItem)->node->cL == (yyyGNT **) NULL)
      yyyfatal("malloc error in Ox Child List space allocation\n");
   (*yyyOxStackItem)->node->refCountListLen = yyyNattrbs;
   (*yyyOxStackItem)->node->refCountList =
            (yyyRCT *) calloc((size_t)yyyNattrbs, (size_t)sizeof(yyyRCT));
   if ((*yyyOxStackItem)->node->refCountList == (yyyRCT *) NULL)
      yyyfatal("malloc error in Ox Reference Count List space allocation\n");
   (*yyyOxStackItem)->node->prodNum = (yyyPNT)yyyProdNum;
   va_start(ap, yyval_OxAttrbs);
   for (yyyWST i=1;i<=yyyRHSlength;i++)
     {yyySIT *yaccStDum = va_arg(ap,__YYYSTRUCT yyyOxAttrbsT *)->yyyOxStackItem;
      yyyGNT *gnpDum = (*yyyOxStackItem)->node->cL[i-1] = yaccStDum->node;
      gnpDum->whichSym = i;
      gnpDum->parent.noderef = (*yyyOxStackItem)->node;
      gnpDum->parentIsStack = 0;
     }
   va_end(ap);
  }



static void yyyReclaimSemStkEls(int yyyRHSlength, ...)
  {
   va_list ap;

   va_start(ap, yyyRHSlength);
   for (yyyWST i=1;i<=yyyRHSlength;i++)
     {yyySIT *yaccStDum = va_arg(ap,__YYYSTRUCT yyyOxAttrbsT *)->yyyOxStackItem;
      yaccStDum->node = (yyyGNT *) NULL;
      free(yaccStDum);
     }
   va_end(ap);
  }



#define yyyDECORfREQ 50



static void yyyAdjustINRC(long yyyProdNum, int yyyRHSlength, long startP, long stopP, __YYYSTRUCT yyyOxAttrbsT *yyval_OxAttrbs, ...)
  {
   yyySIT *yyyOxStackItem = yyval_OxAttrbs->yyyOxStackItem;
   yyySSALC *SSALptr,*SSALptrHead,**cPtrPtr;
   long *pL;
   yyyGNT *gnpDum;
   long iTemp;
   long nextP;
   static unsigned short intNodeCount = yyyDECORfREQ;
   va_list ap;

   nextP = startP;
   while (nextP < stopP)
     {if (yyyRCIL[nextP] == yyyR)
         {(yyyOxStackItem->node->refCountList)[yyyRCIL[nextP+1]] = yyyRCIL[nextP+2];
         }
      else
         {(((yyyOxStackItem->node->cL)[yyyRCIL[nextP]])->refCountList)[yyyRCIL[nextP+1]] = yyyRCIL[nextP+2];
         }
      nextP += 3;
     }
   pL = yyyIIEL + yyyIIIEL[yyyProdNum];
   va_start(ap, yyval_OxAttrbs);
   for (yyyWST i=1;i<=yyyRHSlength;i++)
     {yyySIT *yaccStDum = va_arg(ap,__YYYSTRUCT yyyOxAttrbsT *)->yyyOxStackItem;
      pL++;
      SSALptrHead = SSALptr = *(cPtrPtr = &(yaccStDum->solvedSAlist));
      if (SSALptr != yyyLambdaSSAL)
         {*cPtrPtr = yyyLambdaSSAL;
          do
            {
             iTemp = (*pL+SSALptr->attrbNum);
             yyySignalEnts(yyyOxStackItem->node,
                           yyyIEL[iTemp],
                           yyyIEL[iTemp+1]
                          );
             SSALptr = *(cPtrPtr = &(SSALptr->next));
            }
            while (SSALptr != yyyLambdaSSAL);
          *cPtrPtr = yyySSALCfreeList;
          yyySSALCfreeList = SSALptrHead;
         }
     }
   va_end(ap);
   nextP = startP + 2;
   while (nextP < stopP)
     {if (!yyyRCIL[nextP])
         {if (yyyRCIL[nextP-2] == yyyR)
             {yyySSALC **pL = &(yyyOxStackItem->solvedSAlist);
              yyySSALC *iTemp;
              if (yyySSALCfreeList == yyyLambdaSSAL)
                 {iTemp = (yyySSALC *) malloc((size_t)sizeof(yyySSALC));
                  if (iTemp == yyyLambdaSSAL)
                     yyyfatal("malloc error in Ox Stack Solved List space allocation\n");
                 }
              else
                 {iTemp = yyySSALCfreeList;
                  yyySSALCfreeList = yyySSALCfreeList->next;
                 }
              iTemp->next = *pL;
              iTemp->attrbNum = yyyRCIL[nextP-1];
              *pL = iTemp;
             }
          else
             {if ((gnpDum = (yyyOxStackItem->node->cL)[yyyRCIL[nextP-2]])->prodNum != 0)
                 {iTemp = yyyIIEL[yyyIIIEL[gnpDum->prodNum]] + yyyRCIL[nextP-1];
                  yyySignalEnts(gnpDum,
                                yyyIEL[iTemp],
                                yyyIEL[iTemp+1]
                               );
                 }
             }
         }
      nextP += 3;
     }
   if (!--intNodeCount)
      {intNodeCount = yyyDECORfREQ;
       yyyDecorate();
      }
  }



void yyyGenLeaf(int nAttrbs,int typeNum,long startP,long stopP,YYSTYPE *yyylval)
  {yyyRCT *rcPdum;
   yyySIT **yyyOxStackItem = &yyylval->yyyOxAttrbs.yyyOxStackItem;
   (*yyyOxStackItem) = (yyySIT *) malloc((size_t)sizeof(yyySIT));
   if ((*yyyOxStackItem) == (yyySIT *) NULL)
      yyyfatal("malloc error in Ox/Yacc semantic stack space allocation\n");
   (*yyyOxStackItem)->node =
                          (yyyGNT *) malloc((size_t)sizeof(yyyGNT))
                         ;
   if ((*yyyOxStackItem)->node == (yyyGNT *) NULL)
      yyyfatal("malloc error in Ox Semantic Node space allocation\n");
   (*yyyOxStackItem)->solvedSAlist = yyyLambdaSSAL;
   (*yyyOxStackItem)->node->parent.stackref = *yyyOxStackItem;
   (*yyyOxStackItem)->node->parentIsStack = 1;
   (*yyyOxStackItem)->node->cLlen = 0;
   (*yyyOxStackItem)->node->cL = (yyyGNT **) NULL;
   (*yyyOxStackItem)->node->refCountListLen = nAttrbs;
   rcPdum = (*yyyOxStackItem)->node->refCountList =
            (yyyRCT *) calloc((size_t)nAttrbs, (size_t)sizeof(yyyRCT));
   if (rcPdum == (yyyRCT *) NULL)
      yyyfatal("malloc error in Ox Reference Count List space allocation\n");
   while (startP < stopP) rcPdum[yyyLRCIL[startP++]] = 0;
   (*yyyOxStackItem)->node->prodNum = 0;
   (*yyyOxStackItem)->node->whichSym = 0;
  }



void yyyabort(void)
  {yyyYok = 0;
  }



#define yyyLastProdNum 55


static int yyyProdsInd[] = {
   0,
   0,   1,   5,  11,  18,  22,  24,  25,  29,  33,
  36,  38,  42,  47,  52,  53,  56,  57,  65,  72,
  73,  75,  77,  79,  81,  84,  87,  90,  93,  96,
 100, 104, 108, 110, 112, 114, 116, 119, 122, 125,
 128, 132, 135, 139, 142, 146, 149, 153, 156, 160,
 162, 164, 168, 173, 177,
 179,
};


static int yyyProds[][2] = {
{1045,   0},{1045,   0},{1045,   0},{ 197,   3},{ 548,   0},
{ 197,   3},{ 619,   1},{ 396,   0},{ 404,   0},{  95,   6},
{ 124,   0},{ 197,   3},{ 619,   1},{ 396,   0},{ 146,   4},
{ 404,   0},{  95,   6},{ 124,   0},{ 146,   4},{ 146,   4},
{ 428,   0},{ 619,   1},{ 146,   4},{ 619,   1},{  95,   6},
{  95,   6},{  95,   6},{ 278,   9},{ 548,   0},{  95,   6},
{  95,   6},{  52,   5},{ 548,   0},{ 278,   9},{ 838,   0},
{ 462,  12},{ 278,   9},{ 930,   7},{ 278,   9},{ 619,   1},
{ 564,   0},{ 462,  12},{  52,   5},{ 933,   0},{ 619,   1},
{ 564,   0},{ 462,  12},{ 930,   7},{ 304,   8},{ 675,   0},
{  70,  10},{ 124,   0},{ 304,   8},{ 304,   8},{ 619,   1},
{ 540,   0},{  70,  10},{  70,  10},{  70,  10},{ 462,  12},
{ 604,   0},{  95,   6},{ 667,   0},{ 281,  18},{ 548,   0},
{  70,  10},{  70,  10},{ 604,   0},{  95,   6},{ 667,   0},
{ 281,  18},{ 548,   0},{ 281,  18},{ 281,  18},{ 619,   1},
{ 667,   0},{ 634,   0},{ 667,   0},{ 646,   0},{ 462,  12},
{1029,  11},{ 462,  12},{ 627,   0},{1029,  11},{ 462,  12},
{1029,  11},{ 575,  13},{ 462,  12},{1029,  11},{ 723,  14},
{ 462,  12},{1029,  11},{ 666,  15},{ 462,  12},{1029,  11},
{ 700,  16},{ 462,  12},{1029,  11},{ 636,   0},{1029,  11},
{ 462,  12},{1029,  11},{ 564,   0},{1029,  11},{ 462,  12},
{1029,  11},{ 436,   0},{1029,  11},{ 627,   0},{1165,   0},
{ 627,   0},{  99,   0},{ 627,   0},{ 994,   0},{ 627,   0},
{ 606,   0},{ 627,   0},{1165,   0},{ 627,   0},{ 627,   0},
{  99,   0},{ 627,   0},{ 627,   0},{ 994,   0},{ 627,   0},
{ 627,   0},{ 606,   0},{ 627,   0},{ 575,  13},{ 420,   0},
{1029,  11},{ 575,  13},{ 575,  13},{ 420,   0},{1029,  11},
{ 723,  14},{ 412,   0},{1029,  11},{ 723,  14},{ 723,  14},
{ 412,   0},{1029,  11},{ 666,  15},{ 444,   0},{1029,  11},
{ 666,  15},{ 666,  15},{ 444,   0},{1029,  11},{ 700,  16},
{ 737,   0},{1029,  11},{ 700,  16},{ 700,  16},{ 737,   0},
{1029,  11},{1029,  11},{ 396,   0},{ 462,  12},{ 404,   0},
{1029,  11},{ 765,   2},{1029,  11},{ 619,   1},{1029,  11},
{ 619,   1},{ 396,   0},{ 404,   0},{1029,  11},{ 619,   1},
{ 396,   0},{ 657,  17},{ 404,   0},{ 657,  17},{ 657,  17},
{ 428,   0},{ 462,  12},{ 657,  17},{ 462,  12},
};


static int yyySortsInd[] = {
  0,
  0,  1,  2,  3,  5,  7,  9, 11, 12, 14,
 15, 17, 19, 21, 22, 23, 24, 25,
 26,
};


static int yyySorts[] = {
  423,  423,   58,   58,  102,   58,  965,   58,  965,  425,
   58,  425,   58,  102,   58,   58,  102,   58,  102,   58,
  102,   58,   58,   58,   58,   58,
};



static const char *yyyStringTab[] = {
0,0,0,0,0,
0,0,0,0,0,
0,"preamble",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"ADD",0,0,0,0,
0,0,0,0,0,
0,0,"vardef",0,0,
0,0,0,"symbols_inh",0,
0,0,0,0,0,
0,0,0,0,0,
"guarded",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"stats",0,0,0,"HEAD",
"check_symbol_def",0,"op_tree",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"y",0,"END",
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"pars",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"LABEL",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"funcdef",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"NULL",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"stat",0,
0,"glab",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"CALL_CODEGEN",0,0,0,
0,0,0,0,"condlab",
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"name",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"'('",0,0,0,
0,0,0,0,"')'",
0,0,0,0,0,
0,0,"'*'","lexeme",0,
0,0,0,0,0,
"'+'",0,0,"val",0,
"label",0,0,"','",0,
0,0,0,0,0,
0,"'-'",0,0,0,
0,0,0,0,"'.'",
0,0,0,0,0,
0,0,0,0,"op_tree_t",
0,0,0,0,0,
0,0,"expr",0,0,
0,0,0,0,0,
0,0,"CONSTANT",0,0,
0,"printf",0,0,0,
0,0,0,0,0,
0,"NEW_OP_TREE_NODE",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"symbol_t",
0,0,0,0,0,
0,0,0,0,0,
"':'",0,0,0,0,
0,0,0,"';'",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"'='",
0,0,0,0,0,
0,0,0,0,0,
"addexp",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"RA",
0,"ISLIST",0,0,0,
0,0,0,0,0,
"check",0,0,0,"ID",
0,0,0,0,0,
0,0,"listexp",0,0,
0,0,0,0,"CONTINUE",
0,"GTEQ",0,0,0,
0,0,0,0,0,
0,"BREAK",0,0,0,
0,0,0,0,0,
0,0,"cargs","codegen",0,
0,0,0,0,0,
0,"dotexp","contexp",0,0,
0,0,0,0,0,
"COND",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"orexp",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"mulexp",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"OR",0,0,
"new_symbol_node",0,0,0,0,
0,"VARUSE",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"NUM",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"strtol",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"append_symbol_node",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"RETURN",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"VARIABLE",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"if",0,
0,0,0,0,0,
"cond",0,0,"VAR",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"symbols",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"TAIL",
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"yytext",0,
0,0,0,"VARDEF","term",
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"program",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"check_symbol_usage",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"RET",
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"NOT",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"symbols_merge",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,
};



#define yyySizeofProd(num) (yyyProdsInd[(num)+1] - yyyProdsInd[(num)])

#define yyyGSoccurStr(prodNum,symPos) \
   (yyyStringTab[yyyProds[yyyProdsInd[(prodNum)] + (symPos)][0]])

#define yyySizeofSort(num) (yyySortsInd[(num)+1] - yyySortsInd[(num)])

#define yyySortOf(prodNum,symPos) \
  (yyyProds[yyyProdsInd[(prodNum)] + (symPos)][1])

#define yyyAttrbStr(prodNum,symPos,attrbNum)                      \
  (yyyStringTab[yyySorts[yyySortsInd[yyySortOf(prodNum,symPos)] + \
                         (attrbNum)                               \
                        ]                                         \
               ]                                                  \
  )



static void yyyShowProd(int i)
  {int nSyms;

   nSyms = yyySizeofProd(i);
   for (int j=0; j<nSyms; j++)
     {
      fprintf(stderr,"%s",yyyGSoccurStr(i,j));
      if (j == 0) fputs(" : ",stderr); else putc(' ',stderr);
     }
   fputs(";\n",stderr);
  }



static void yyyCheckNodeInstancesSolved(yyyGNT *np)
  {int mysort,sortSize,prodNum,symPos,inTerminalNode;
   int nUnsolvedInsts = 0;

   if (np->prodNum != 0)
     {inTerminalNode = 0;
      prodNum = np->prodNum;
      symPos = 0;
     }
   else
     {inTerminalNode = 1;
      prodNum = np->parent.noderef->prodNum;
      symPos = np->whichSym;
     }
   mysort = yyySortOf(prodNum,symPos);
   sortSize = yyySizeofSort(mysort);
   for (int i=0; i<sortSize; i++)
     if ((np->refCountList)[i] != 0) nUnsolvedInsts += 1;
   if (nUnsolvedInsts)
     {fprintf(stderr,
      "\nFound node that has %d unsolved attribute instance(s).\n",
              nUnsolvedInsts
             );
      fprintf(stderr,"Node is labeled \"%s\".\n",
             yyyGSoccurStr(prodNum,symPos));
      if (inTerminalNode)
        {fputs("Node is terminal.  Its parent production is:\n  ",stderr);
         yyyShowProd(prodNum);
        }
      else
        {fputs("Node is nonterminal.  ",stderr);
         if (!(np->parentIsStack))
           {fprintf(stderr,
                    "Node is %dth child in its parent production:\n  ",
                   np->whichSym
                  );
            yyyShowProd(np->parent.noderef->prodNum);
           }
         fputs("Node is on left hand side of this production:\n  ",stderr);
         yyyShowProd(np->prodNum);
        }
      fputs("The following instances are unsolved:\n",stderr);
      for (int i=0; i<sortSize; i++)
        if ((np->refCountList)[i] != 0)
          fprintf(stderr,"     %-16s still has %1d dependencies.\n",
                  yyyAttrbStr(prodNum,symPos,i),(np->refCountList)[i]);
     }
  }



static void yyyCheckUnsolvedInstTrav(yyyGNT *pNode,long *nNZrc,long *cycleSum)
  {yyyGNT **yyyCLpdum;
   yyyRCT *rcp;
   int i;

   /* visit the refCountList of each node in the tree, and sum the non-zero refCounts */
   rcp = pNode->refCountList;
   i = pNode->refCountListLen;
   while (i--)
      if (*rcp++) {*cycleSum += *(rcp - 1); (*nNZrc)++;}
   yyyCLpdum = pNode->cL;
   i = pNode->cLlen;
   while (i--)
     {
      yyyCheckUnsolvedInstTrav(*yyyCLpdum,nNZrc,cycleSum);
      yyyCLpdum++;
     }
  }



static void yyyUnsolvedInstSearchTravAux(yyyGNT *pNode)
  {yyyGNT **yyyCLpdum;
   int i;

   yyyCheckNodeInstancesSolved(pNode);
   yyyCLpdum = pNode->cL;
   i = pNode->cLlen;
   while (i--)
     {
      yyyUnsolvedInstSearchTravAux(*yyyCLpdum);
      yyyCLpdum++;
     }
  }



