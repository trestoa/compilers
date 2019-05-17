%{
/* output from Ox version 1.5.1 */
%}
%{
/* Ox-generated Attribute-Grammar evaluator lexer specification
   for Lex-compatible lexer generators

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
   lexer specification skeleton and distribute that work under terms of
   your own choice, so long as that work isn't itself an
   Attribute-Grammar evaluator generator using the skeleton or a
   modified version thereof as an evaluator lexer specification
   skeleton.  */

/* Identify Ox output. */
#define YYYOX 1

%}
 #line 1 "scanner.l"
%option noyywrap
%{
#include "y.tab.h"
#include "ag.h"
#include "codegen.h"

#include <string.h>

#define lexeme strcpy((char *) malloc(yyleng+1), yytext)
%}

whitespace  [\n\t ]
comment     "{".*"}"
identifier  [A-Za-z][A-Za-z0-9]*
decdigit    [0-9]+
hexdigit    \$[a-fA-F0-9]+

 #line 54 "oxout.l"

%{
#define yyyinit()


struct yyyT1
#line 99 "gram.y"
 { char *val; }
 #line 63 "oxout.l"
;


struct yyyT2
#line 100 "gram.y"
 { long val; }
 #line 70 "oxout.l"
;


struct yyyT3
#line 101 "gram.y"
 { symbol_t *symbols_inh; }
 #line 77 "oxout.l"
;


struct yyyT4
#line 102 "gram.y"
 { symbol_t *symbols_inh; op_tree_t *op_tree; }
 #line 84 "oxout.l"
;


struct yyyT5
#line 104 "gram.y"
 { symbol_t *symbols_inh; symbol_t *symbols; }
 #line 91 "oxout.l"
;


struct yyyT6
#line 105 "gram.y"
 { symbol_t *symbols_inh; symbol_t *symbols; }
 #line 98 "oxout.l"
;


struct yyyT7
#line 106 "gram.y"
 { symbol_t *label; symbol_t *symbols_inh; }
 #line 105 "oxout.l"
;


struct yyyT8
#line 107 "gram.y"
 { symbol_t *label; }
 #line 112 "oxout.l"
;


struct yyyT9
#line 108 "gram.y"
 { symbol_t *symbols_inh; op_tree_t *op_tree; }
 #line 119 "oxout.l"
;


struct yyyT10
#line 109 "gram.y"
 { symbol_t *symbols_inh; }
 #line 126 "oxout.l"
;


struct yyyT11
#line 111 "gram.y"
 { symbol_t *symbols_inh; op_tree_t *op_tree; }
 #line 133 "oxout.l"
;


struct yyyT12
#line 112 "gram.y"
 { symbol_t *symbols_inh; op_tree_t *op_tree; }
 #line 140 "oxout.l"
;


struct yyyT13
#line 113 "gram.y"
 { symbol_t *symbols_inh; op_tree_t *op_tree; }
 #line 147 "oxout.l"
;


struct yyyT14
#line 114 "gram.y"
 { symbol_t *symbols_inh; }
 #line 154 "oxout.l"
;


struct yyyT15
#line 115 "gram.y"
 { symbol_t *symbols_inh; }
 #line 161 "oxout.l"
;


struct yyyT16
#line 116 "gram.y"
 { symbol_t *symbols_inh; }
 #line 168 "oxout.l"
;


struct yyyT17
#line 117 "gram.y"
 { symbol_t *symbols_inh; }
 #line 175 "oxout.l"
;


struct yyyT18
#line 118 "gram.y"
 { symbol_t *symbols_inh; }
 #line 182 "oxout.l"
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
extern void yyyGenLeaf(int nAttrbs,int typeNum,
                       long startP,long stopP
                       ,YYSTYPE *yyylval
                      );
%}
 #line 18 "scanner.l"
%%
	{yyyinit();} /* initialize Ox */
 #line 18 "scanner.l"


end             {
 #line 250 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 20 "scanner.l"
return (END);}
return          {
 #line 255 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 21 "scanner.l"
return (RETURN);}
var             {
 #line 260 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 22 "scanner.l"
return (VAR);}
cond            {
 #line 265 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 23 "scanner.l"
return (COND);}
continue        {
 #line 270 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 24 "scanner.l"
return (CONTINUE);}
break           {
 #line 275 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 25 "scanner.l"
return (BREAK);}
not             {
 #line 280 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 26 "scanner.l"
return (NOT);}
head            {
 #line 285 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 27 "scanner.l"
return (HEAD);}
tail            {
 #line 290 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 28 "scanner.l"
return (TAIL);}
islist          {
 #line 295 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 29 "scanner.l"
return (ISLIST);}
or              {
 #line 300 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 30 "scanner.l"
return (OR);}
"->"            {
 #line 305 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 31 "scanner.l"
return (RA);}
";"             {
 #line 310 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 32 "scanner.l"
return (';');}
"("             {
 #line 315 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 33 "scanner.l"
return ('(');}
")"             {
 #line 320 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 34 "scanner.l"
return (')');}
"+"             {
 #line 325 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 35 "scanner.l"
return ('+');}
"*"             {
 #line 330 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 36 "scanner.l"
return ('*');}
"="             {
 #line 335 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 37 "scanner.l"
return ('=');}
"-"             {
 #line 340 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 38 "scanner.l"
return ('-');}
"."             {
 #line 345 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 39 "scanner.l"
return ('.');}
":"             {
 #line 350 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 40 "scanner.l"
return (':');}
","             {
 #line 355 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 41 "scanner.l"
return (',');}
">="            {
 #line 360 "oxout.l"
yyyGenLeaf(0,0,0,0,&yylval);
 #line 42 "scanner.l"
return (GTEQ);}
{identifier}    {
 #line 365 "oxout.l"
yyyGenLeaf(1,1,0,1,&yylval);
 #line 43 "scanner.l"
 #line 368 "oxout.l"
yylval.yyyOxAttrbs.yyyOxStackItem->node->yyyAttrbs.yyyAttrb1.val
 #line 43 "scanner.l"
 = lexeme;return (ID);}
{decdigit}      {
 #line 373 "oxout.l"
yyyGenLeaf(1,2,1,2,&yylval);
 #line 44 "scanner.l"
 #line 376 "oxout.l"
yylval.yyyOxAttrbs.yyyOxStackItem->node->yyyAttrbs.yyyAttrb2.val
 #line 44 "scanner.l"
 = strtol(yytext, NULL, 10);return (NUM);}
{hexdigit}      {
 #line 381 "oxout.l"
yyyGenLeaf(1,2,1,2,&yylval);
 #line 45 "scanner.l"
 #line 384 "oxout.l"
yylval.yyyOxAttrbs.yyyOxStackItem->node->yyyAttrbs.yyyAttrb2.val
 #line 45 "scanner.l"
 = strtol(yytext+1, NULL, 16);return (NUM);}
{whitespace}+   ;
{comment}       ;
.               {
                    fprintf(stderr, "Invalid token: %s", yytext);
                    exit(EXIT_FAILURE);
                }
