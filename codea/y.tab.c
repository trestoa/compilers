/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OR = 258,
     END = 259,
     ID = 260,
     COND = 261,
     RETURN = 262,
     HEAD = 263,
     TAIL = 264,
     ISLIST = 265,
     BREAK = 266,
     CONTINUE = 267,
     VAR = 268,
     NOT = 269,
     RA = 270,
     NUM = 271,
     GTEQ = 272
   };
#endif
/* Tokens.  */
#define OR 258
#define END 259
#define ID 260
#define COND 261
#define RETURN 262
#define HEAD 263
#define TAIL 264
#define ISLIST 265
#define BREAK 266
#define CONTINUE 267
#define VAR 268
#define NOT 269
#define RA 270
#define NUM 271
#define GTEQ 272




/* Copy the first part of user declarations.  */
#line 29 "oxout.y"

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
#line 1 "gram.y"

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
#line 152 "oxout.y"

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

#line 337 "oxout.y"

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


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 352 "oxout.y"
{
struct yyyOxAttrbsT {
struct yyyStackItem *yyyOxStackItem;
} yyyOxAttrbs;
}
/* Line 193 of yacc.c.  */
#line 446 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 358 "oxout.y"

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



/* Line 216 of yacc.c.  */
#line 477 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   105

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNRULES -- Number of states.  */
#define YYNSTATES  96

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   272

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      18,    19,    27,    26,    24,    21,    22,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    23,    16,
       2,    20,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    17,    25
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,    10,    16,    23,    27,    29,
      30,    34,    38,    41,    43,    47,    52,    57,    58,    61,
      62,    70,    77,    78,    80,    82,    84,    86,    89,    92,
      95,    98,   101,   105,   109,   113,   115,   117,   119,   121,
     124,   127,   130,   133,   137,   140,   144,   147,   151,   154,
     158,   161,   165,   167,   169,   173,   178,   182
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      29,     0,    -1,    30,    -1,    -1,    30,    31,    16,    -1,
       5,    18,    19,    33,     4,    -1,     5,    18,    32,    19,
      33,     4,    -1,    32,    24,     5,    -1,     5,    -1,    -1,
      33,    34,    16,    -1,    33,    35,    16,    -1,     7,    41,
      -1,    36,    -1,     5,    20,    41,    -1,    13,     5,    20,
      41,    -1,    37,     6,    38,     4,    -1,    -1,     5,    23,
      -1,    -1,    38,    41,    15,    33,    40,    39,    16,    -1,
      38,    15,    33,    40,    39,    16,    -1,    -1,     5,    -1,
      12,    -1,    11,    -1,    47,    -1,    42,    47,    -1,    47,
      43,    -1,    47,    44,    -1,    47,    45,    -1,    47,    46,
      -1,    47,    25,    47,    -1,    47,    20,    47,    -1,    47,
      21,    47,    -1,    14,    -1,     8,    -1,     9,    -1,    10,
      -1,    14,    42,    -1,     8,    42,    -1,     9,    42,    -1,
      10,    42,    -1,    26,    47,    43,    -1,    26,    47,    -1,
      27,    47,    44,    -1,    27,    47,    -1,    22,    47,    45,
      -1,    22,    47,    -1,     3,    47,    46,    -1,     3,    47,
      -1,    18,    41,    19,    -1,    17,    -1,     5,    -1,     5,
      18,    19,    -1,     5,    18,    48,    19,    -1,    48,    24,
      41,    -1,    41,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   382,   382,   391,   126,   129,   136,   145,   153,   493,
     166,   173,   181,   188,   193,   202,   211,   606,   226,   648,
     233,   240,   676,   249,   252,   253,   256,   261,   266,   273,
     279,   285,   291,   297,   303,   311,   312,   313,   314,   315,
     316,   317,   318,   321,   327,   334,   339,   345,   350,   356,
     361,   367,   372,   376,   382,   386,   393,   398
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OR", "END", "ID", "COND", "RETURN",
  "HEAD", "TAIL", "ISLIST", "BREAK", "CONTINUE", "VAR", "NOT", "RA", "';'",
  "NUM", "'('", "')'", "'='", "'-'", "'.'", "':'", "','", "GTEQ", "'+'",
  "'*'", "$accept", "yyyAugNonterm", "program", "funcdef", "pars", "stats",
  "stat", "vardef", "cond", "condlab", "guarded", "glab", "contexp",
  "expr", "listexp", "addexp", "mulexp", "dotexp", "orexp", "term",
  "cargs", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    59,   271,    40,    41,
      61,    45,    46,    58,    44,   272,    43,    42
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    28,    29,    30,    30,    31,    31,    32,    32,    33,
      33,    33,    34,    34,    34,    35,    36,    37,    37,    38,
      38,    38,    39,    39,    40,    40,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    42,    42,    42,    42,    42,
      42,    42,    42,    43,    43,    44,    44,    45,    45,    46,
      46,    47,    47,    47,    47,    47,    48,    48
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     3,     5,     6,     3,     1,     0,
       3,     3,     2,     1,     3,     4,     4,     0,     2,     0,
       7,     6,     0,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     3,     3,     3,     1,     1,     1,     1,     2,
       2,     2,     2,     3,     2,     3,     2,     3,     2,     3,
       2,     3,     1,     1,     3,     4,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     4,     8,     9,
       0,    17,     9,     0,     5,     0,     0,     0,     0,     0,
      13,     0,    17,     7,     0,    18,    53,    36,    37,    38,
      35,    52,     0,    12,     0,    26,     0,    10,    11,    19,
       6,    14,     0,    40,    41,    42,    39,     0,    27,     0,
       0,     0,     0,     0,     0,     0,    28,    29,    30,    31,
       0,     0,    54,    57,     0,    51,    50,    33,    34,    48,
      32,    44,    46,    15,    16,     9,     0,    55,     0,    49,
      47,    43,    45,    17,     9,    56,    25,    24,    22,    17,
      23,     0,    22,    21,     0,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     5,    10,    11,    18,    19,    20,    21,
      61,    91,    88,    33,    34,    56,    57,    58,    59,    35,
      64
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -24
static const yytype_int8 yypact[] =
{
     -24,     8,     5,   -24,     6,     7,    -1,   -24,   -24,   -24,
      -7,    57,   -24,    37,   -24,    34,    42,    38,    28,    51,
     -24,    52,    64,   -24,    42,   -24,    56,    74,    74,    74,
      74,   -24,    42,   -24,    48,     0,    58,   -24,   -24,   -24,
     -24,   -24,    -3,   -24,   -24,   -24,   -24,    67,   -24,    48,
      48,    48,    48,    48,    48,    48,   -24,   -24,   -24,   -24,
      42,    31,   -24,   -24,    66,   -24,    73,   -24,   -24,    69,
     -24,    61,    62,   -24,   -24,   -24,    81,   -24,    42,   -24,
     -24,   -24,   -24,    68,   -24,   -24,   -24,   -24,    92,    68,
     -24,    82,    92,   -24,    83,   -24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -24,   -24,   -24,   -24,   -24,   -12,   -24,   -24,   -24,   -24,
     -24,     9,    11,   -23,    65,    32,    30,    35,    39,   -21,
     -24
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      22,    41,    26,    49,     8,    27,    28,    29,     3,    47,
       4,    30,    12,    48,    31,    32,    62,    13,     9,    63,
      50,    51,    52,     7,     6,    53,    54,    55,    66,    67,
      68,    69,    70,    71,    72,    74,    26,    73,    76,    27,
      28,    29,    23,    36,    37,    30,    75,    26,    31,    32,
      27,    28,    29,    26,    24,    85,    30,    25,    39,    31,
      32,    14,    15,    83,    16,    31,    32,    38,    40,    15,
      17,    16,    89,    15,    42,    16,    49,    17,    60,    86,
      87,    17,    27,    28,    29,    77,    65,    54,    30,    55,
      78,    52,    43,    44,    45,    46,    84,    90,    93,    95,
      92,    94,    82,    81,    80,    79
};

static const yytype_uint8 yycheck[] =
{
      12,    24,     5,     3,     5,     8,     9,    10,     0,    32,
       5,    14,    19,    34,    17,    18,    19,    24,    19,    42,
      20,    21,    22,    16,    18,    25,    26,    27,    49,    50,
      51,    52,    53,    54,    55,     4,     5,    60,    61,     8,
       9,    10,     5,     5,    16,    14,    15,     5,    17,    18,
       8,     9,    10,     5,    20,    78,    14,    23,     6,    17,
      18,     4,     5,    75,     7,    17,    18,    16,     4,     5,
      13,     7,    84,     5,    18,     7,     3,    13,    20,    11,
      12,    13,     8,     9,    10,    19,    19,    26,    14,    27,
      24,    22,    27,    28,    29,    30,    15,     5,    16,    16,
      89,    92,    72,    71,    69,    66
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    30,     0,     5,    31,    18,    16,     5,    19,
      32,    33,    19,    24,     4,     5,     7,    13,    34,    35,
      36,    37,    33,     5,    20,    23,     5,     8,     9,    10,
      14,    17,    18,    41,    42,    47,     5,    16,    16,     6,
       4,    41,    18,    42,    42,    42,    42,    41,    47,     3,
      20,    21,    22,    25,    26,    27,    43,    44,    45,    46,
      20,    38,    19,    41,    48,    19,    47,    47,    47,    47,
      47,    47,    47,    41,     4,    15,    41,    19,    24,    46,
      45,    43,    44,    33,    15,    41,    11,    12,    40,    33,
       5,    39,    40,    16,    39,    16
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 383 "oxout.y"
    {
		 yyyDecorate(); yyyExecuteRRsection((yyvsp[(1) - (1)].yyyOxAttrbs).yyyOxStackItem->node);
		}
    break;

  case 3:
#line 391 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(1,0,0,&(yyval.yyyOxAttrbs));
yyyAdjustINRC(1,0,0,0,&(yyval.yyyOxAttrbs));
yyyReclaimSemStkEls(0);}}
    break;

  case 4:
#line 399 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(2,3,0,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyAdjustINRC(2,3,0,0,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyReclaimSemStkEls(3,&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));}}
    break;

  case 5:
#line 409 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(3,5,1,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (5)].yyyOxAttrbs),&(yyvsp[(2) - (5)].yyyOxAttrbs),&(yyvsp[(3) - (5)].yyyOxAttrbs),&(yyvsp[(4) - (5)].yyyOxAttrbs),&(yyvsp[(5) - (5)].yyyOxAttrbs));

#line 130 "gram.y"


#line 416 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb3.symbols_inh
#line 131 "gram.y"
 = NULL;

#line 421 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->cL[3]->yyyAttrbs.yyyAttrb6.symbols_inh
#line 132 "gram.y"
 =
#line 425 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb3.symbols_inh
#line 132 "gram.y"
;

#line 430 "oxout.y"
yyyAdjustINRC(3,5,0,6,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (5)].yyyOxAttrbs),&(yyvsp[(2) - (5)].yyyOxAttrbs),&(yyvsp[(3) - (5)].yyyOxAttrbs),&(yyvsp[(4) - (5)].yyyOxAttrbs),&(yyvsp[(5) - (5)].yyyOxAttrbs));
yyyReclaimSemStkEls(5,&(yyvsp[(1) - (5)].yyyOxAttrbs),&(yyvsp[(2) - (5)].yyyOxAttrbs),&(yyvsp[(3) - (5)].yyyOxAttrbs),&(yyvsp[(4) - (5)].yyyOxAttrbs),&(yyvsp[(5) - (5)].yyyOxAttrbs));}}
    break;

  case 6:
#line 437 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(4,6,1,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (6)].yyyOxAttrbs),&(yyvsp[(2) - (6)].yyyOxAttrbs),&(yyvsp[(3) - (6)].yyyOxAttrbs),&(yyvsp[(4) - (6)].yyyOxAttrbs),&(yyvsp[(5) - (6)].yyyOxAttrbs),&(yyvsp[(6) - (6)].yyyOxAttrbs));
yyyAdjustINRC(4,6,6,12,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (6)].yyyOxAttrbs),&(yyvsp[(2) - (6)].yyyOxAttrbs),&(yyvsp[(3) - (6)].yyyOxAttrbs),&(yyvsp[(4) - (6)].yyyOxAttrbs),&(yyvsp[(5) - (6)].yyyOxAttrbs),&(yyvsp[(6) - (6)].yyyOxAttrbs));
yyyReclaimSemStkEls(6,&(yyvsp[(1) - (6)].yyyOxAttrbs),&(yyvsp[(2) - (6)].yyyOxAttrbs),&(yyvsp[(3) - (6)].yyyOxAttrbs),&(yyvsp[(4) - (6)].yyyOxAttrbs),&(yyvsp[(5) - (6)].yyyOxAttrbs),&(yyvsp[(6) - (6)].yyyOxAttrbs));}}
    break;

  case 7:
#line 448 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(5,3,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyAdjustINRC(5,3,12,18,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyReclaimSemStkEls(3,&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));}}
    break;

  case 8:
#line 457 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(6,1,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));

#line 154 "gram.y"


#line 155 "gram.y"
NEW_OP_TREE_NODE(
#line 466 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb4.op_tree
#line 155 "gram.y"
, VARDEF, NULL, NULL, 0,
#line 470 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 155 "gram.y"
)

#line 475 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb4.symbols_inh
#line 156 "gram.y"
 = new_symbol_node(
#line 479 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 156 "gram.y"
, VARIABLE);

#line 484 "oxout.y"
yyyAdjustINRC(6,1,18,24,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyReclaimSemStkEls(1,&(yyvsp[(1) - (1)].yyyOxAttrbs));}}
    break;

  case 9:
#line 493 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(7,0,2,&(yyval.yyyOxAttrbs));

#line 163 "gram.y"


#line 500 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb6.symbols
#line 164 "gram.y"
 = NULL;
#line 504 "oxout.y"
yyyAdjustINRC(7,0,24,27,&(yyval.yyyOxAttrbs));
yyyReclaimSemStkEls(0);}}
    break;

  case 10:
#line 511 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(8,3,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyAdjustINRC(8,3,27,36,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyReclaimSemStkEls(3,&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));}}
    break;

  case 11:
#line 520 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(9,3,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyAdjustINRC(9,3,36,45,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyReclaimSemStkEls(3,&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));}}
    break;

  case 12:
#line 531 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(10,2,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyAdjustINRC(10,2,45,51,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyReclaimSemStkEls(2,&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));}}
    break;

  case 13:
#line 540 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(11,1,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));

(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb9.op_tree
#line 191 "gram.y"
=NULL;
#line 547 "oxout.y"
yyyAdjustINRC(11,1,51,57,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyReclaimSemStkEls(1,&(yyvsp[(1) - (1)].yyyOxAttrbs));}}
    break;

  case 14:
#line 554 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(12,3,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));

(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb9.op_tree
#line 196 "gram.y"
=NULL;

#line 562 "oxout.y"
yyyAdjustINRC(12,3,57,63,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyReclaimSemStkEls(3,&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));}}
    break;

  case 15:
#line 571 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(13,4,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (4)].yyyOxAttrbs),&(yyvsp[(2) - (4)].yyyOxAttrbs),&(yyvsp[(3) - (4)].yyyOxAttrbs),&(yyvsp[(4) - (4)].yyyOxAttrbs));

#line 203 "gram.y"


#line 578 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb5.symbols
#line 204 "gram.y"
 = new_symbol_node(
#line 582 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->cL[1]->yyyAttrbs.yyyAttrb1.val
#line 204 "gram.y"
, VARIABLE);
#line 586 "oxout.y"
yyyAdjustINRC(13,4,63,69,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (4)].yyyOxAttrbs),&(yyvsp[(2) - (4)].yyyOxAttrbs),&(yyvsp[(3) - (4)].yyyOxAttrbs),&(yyvsp[(4) - (4)].yyyOxAttrbs));
yyyReclaimSemStkEls(4,&(yyvsp[(1) - (4)].yyyOxAttrbs),&(yyvsp[(2) - (4)].yyyOxAttrbs),&(yyvsp[(3) - (4)].yyyOxAttrbs),&(yyvsp[(4) - (4)].yyyOxAttrbs));}}
    break;

  case 16:
#line 595 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(14,4,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (4)].yyyOxAttrbs),&(yyvsp[(2) - (4)].yyyOxAttrbs),&(yyvsp[(3) - (4)].yyyOxAttrbs),&(yyvsp[(4) - (4)].yyyOxAttrbs));
yyyAdjustINRC(14,4,69,75,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (4)].yyyOxAttrbs),&(yyvsp[(2) - (4)].yyyOxAttrbs),&(yyvsp[(3) - (4)].yyyOxAttrbs),&(yyvsp[(4) - (4)].yyyOxAttrbs));
yyyReclaimSemStkEls(4,&(yyvsp[(1) - (4)].yyyOxAttrbs),&(yyvsp[(2) - (4)].yyyOxAttrbs),&(yyvsp[(3) - (4)].yyyOxAttrbs),&(yyvsp[(4) - (4)].yyyOxAttrbs));}}
    break;

  case 17:
#line 606 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(15,0,1,&(yyval.yyyOxAttrbs));

#line 223 "gram.y"


#line 613 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb8.label
#line 224 "gram.y"
 = NULL;
#line 617 "oxout.y"
yyyAdjustINRC(15,0,75,78,&(yyval.yyyOxAttrbs));
yyyReclaimSemStkEls(0);}}
    break;

  case 18:
#line 624 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(16,2,1,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));

#line 227 "gram.y"


#line 631 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb8.label
#line 228 "gram.y"
 = new_symbol_node(
#line 635 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 228 "gram.y"
, LABEL);
#line 639 "oxout.y"
yyyAdjustINRC(16,2,78,81,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyReclaimSemStkEls(2,&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));}}
    break;

  case 19:
#line 648 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(17,0,1,&(yyval.yyyOxAttrbs));
yyyAdjustINRC(17,0,81,81,&(yyval.yyyOxAttrbs));
yyyReclaimSemStkEls(0);}}
    break;

  case 20:
#line 656 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(18,7,1,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (7)].yyyOxAttrbs),&(yyvsp[(2) - (7)].yyyOxAttrbs),&(yyvsp[(3) - (7)].yyyOxAttrbs),&(yyvsp[(4) - (7)].yyyOxAttrbs),&(yyvsp[(5) - (7)].yyyOxAttrbs),&(yyvsp[(6) - (7)].yyyOxAttrbs),&(yyvsp[(7) - (7)].yyyOxAttrbs));
yyyAdjustINRC(18,7,81,93,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (7)].yyyOxAttrbs),&(yyvsp[(2) - (7)].yyyOxAttrbs),&(yyvsp[(3) - (7)].yyyOxAttrbs),&(yyvsp[(4) - (7)].yyyOxAttrbs),&(yyvsp[(5) - (7)].yyyOxAttrbs),&(yyvsp[(6) - (7)].yyyOxAttrbs),&(yyvsp[(7) - (7)].yyyOxAttrbs));
yyyReclaimSemStkEls(7,&(yyvsp[(1) - (7)].yyyOxAttrbs),&(yyvsp[(2) - (7)].yyyOxAttrbs),&(yyvsp[(3) - (7)].yyyOxAttrbs),&(yyvsp[(4) - (7)].yyyOxAttrbs),&(yyvsp[(5) - (7)].yyyOxAttrbs),&(yyvsp[(6) - (7)].yyyOxAttrbs),&(yyvsp[(7) - (7)].yyyOxAttrbs));}}
    break;

  case 21:
#line 665 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(19,6,1,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (6)].yyyOxAttrbs),&(yyvsp[(2) - (6)].yyyOxAttrbs),&(yyvsp[(3) - (6)].yyyOxAttrbs),&(yyvsp[(4) - (6)].yyyOxAttrbs),&(yyvsp[(5) - (6)].yyyOxAttrbs),&(yyvsp[(6) - (6)].yyyOxAttrbs));
yyyAdjustINRC(19,6,93,102,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (6)].yyyOxAttrbs),&(yyvsp[(2) - (6)].yyyOxAttrbs),&(yyvsp[(3) - (6)].yyyOxAttrbs),&(yyvsp[(4) - (6)].yyyOxAttrbs),&(yyvsp[(5) - (6)].yyyOxAttrbs),&(yyvsp[(6) - (6)].yyyOxAttrbs));
yyyReclaimSemStkEls(6,&(yyvsp[(1) - (6)].yyyOxAttrbs),&(yyvsp[(2) - (6)].yyyOxAttrbs),&(yyvsp[(3) - (6)].yyyOxAttrbs),&(yyvsp[(4) - (6)].yyyOxAttrbs),&(yyvsp[(5) - (6)].yyyOxAttrbs),&(yyvsp[(6) - (6)].yyyOxAttrbs));}}
    break;

  case 22:
#line 676 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(20,0,1,&(yyval.yyyOxAttrbs));
yyyAdjustINRC(20,0,102,102,&(yyval.yyyOxAttrbs));
yyyReclaimSemStkEls(0);}}
    break;

  case 23:
#line 684 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(21,1,1,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyAdjustINRC(21,1,102,102,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyReclaimSemStkEls(1,&(yyvsp[(1) - (1)].yyyOxAttrbs));}}
    break;

  case 24:
#line 695 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(22,1,0,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyAdjustINRC(22,1,102,102,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyReclaimSemStkEls(1,&(yyvsp[(1) - (1)].yyyOxAttrbs));}}
    break;

  case 25:
#line 703 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(23,1,0,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyAdjustINRC(23,1,102,102,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyReclaimSemStkEls(1,&(yyvsp[(1) - (1)].yyyOxAttrbs));}}
    break;

  case 26:
#line 713 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(24,1,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyAdjustINRC(24,1,102,108,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyReclaimSemStkEls(1,&(yyvsp[(1) - (1)].yyyOxAttrbs));}}
    break;

  case 27:
#line 722 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(25,2,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));

(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb12.op_tree
#line 264 "gram.y"
  = NULL;
#line 729 "oxout.y"
yyyAdjustINRC(25,2,108,114,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyReclaimSemStkEls(2,&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));}}
    break;

  case 28:
#line 736 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(26,2,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyAdjustINRC(26,2,114,123,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyReclaimSemStkEls(2,&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));}}
    break;

  case 29:
#line 745 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(27,2,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));

(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb12.op_tree
#line 277 "gram.y"
  = NULL;
#line 752 "oxout.y"
yyyAdjustINRC(27,2,123,132,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyReclaimSemStkEls(2,&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));}}
    break;

  case 30:
#line 759 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(28,2,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));

(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb12.op_tree
#line 283 "gram.y"
  = NULL;
#line 766 "oxout.y"
yyyAdjustINRC(28,2,132,141,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyReclaimSemStkEls(2,&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));}}
    break;

  case 31:
#line 773 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(29,2,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));

(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb12.op_tree
#line 289 "gram.y"
  = NULL;
#line 780 "oxout.y"
yyyAdjustINRC(29,2,141,150,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyReclaimSemStkEls(2,&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));}}
    break;

  case 32:
#line 787 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(30,3,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));

(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb12.op_tree
#line 295 "gram.y"
  = NULL;
#line 794 "oxout.y"
yyyAdjustINRC(30,3,150,159,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyReclaimSemStkEls(3,&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));}}
    break;

  case 33:
#line 801 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(31,3,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));

(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb12.op_tree
#line 301 "gram.y"
  = NULL;
#line 808 "oxout.y"
yyyAdjustINRC(31,3,159,168,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyReclaimSemStkEls(3,&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));}}
    break;

  case 34:
#line 815 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(32,3,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));

(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb12.op_tree
#line 307 "gram.y"
  = NULL;
#line 822 "oxout.y"
yyyAdjustINRC(32,3,168,177,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyReclaimSemStkEls(3,&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));}}
    break;

  case 35:
#line 831 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(33,1,0,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyAdjustINRC(33,1,177,177,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyReclaimSemStkEls(1,&(yyvsp[(1) - (1)].yyyOxAttrbs));}}
    break;

  case 36:
#line 839 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(34,1,0,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyAdjustINRC(34,1,177,177,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyReclaimSemStkEls(1,&(yyvsp[(1) - (1)].yyyOxAttrbs));}}
    break;

  case 37:
#line 847 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(35,1,0,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyAdjustINRC(35,1,177,177,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyReclaimSemStkEls(1,&(yyvsp[(1) - (1)].yyyOxAttrbs));}}
    break;

  case 38:
#line 855 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(36,1,0,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyAdjustINRC(36,1,177,177,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyReclaimSemStkEls(1,&(yyvsp[(1) - (1)].yyyOxAttrbs));}}
    break;

  case 39:
#line 863 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(37,2,0,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyAdjustINRC(37,2,177,177,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyReclaimSemStkEls(2,&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));}}
    break;

  case 40:
#line 871 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(38,2,0,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyAdjustINRC(38,2,177,177,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyReclaimSemStkEls(2,&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));}}
    break;

  case 41:
#line 879 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(39,2,0,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyAdjustINRC(39,2,177,177,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyReclaimSemStkEls(2,&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));}}
    break;

  case 42:
#line 887 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(40,2,0,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyAdjustINRC(40,2,177,177,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyReclaimSemStkEls(2,&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));}}
    break;

  case 43:
#line 897 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(41,3,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyAdjustINRC(41,3,177,186,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyReclaimSemStkEls(3,&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));}}
    break;

  case 44:
#line 906 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(42,2,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyAdjustINRC(42,2,186,192,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyReclaimSemStkEls(2,&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));}}
    break;

  case 45:
#line 917 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(43,3,1,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyAdjustINRC(43,3,192,198,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyReclaimSemStkEls(3,&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));}}
    break;

  case 46:
#line 926 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(44,2,1,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyAdjustINRC(44,2,198,201,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyReclaimSemStkEls(2,&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));}}
    break;

  case 47:
#line 937 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(45,3,1,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyAdjustINRC(45,3,201,207,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyReclaimSemStkEls(3,&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));}}
    break;

  case 48:
#line 946 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(46,2,1,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyAdjustINRC(46,2,207,210,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyReclaimSemStkEls(2,&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));}}
    break;

  case 49:
#line 957 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(47,3,1,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyAdjustINRC(47,3,210,216,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyReclaimSemStkEls(3,&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));}}
    break;

  case 50:
#line 966 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(48,2,1,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyAdjustINRC(48,2,216,219,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));
yyyReclaimSemStkEls(2,&(yyvsp[(1) - (2)].yyyOxAttrbs),&(yyvsp[(2) - (2)].yyyOxAttrbs));}}
    break;

  case 51:
#line 977 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(49,3,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyAdjustINRC(49,3,219,225,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyReclaimSemStkEls(3,&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));}}
    break;

  case 52:
#line 986 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(50,1,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));

#line 373 "gram.y"


#line 374 "gram.y"
NEW_OP_TREE_NODE(
#line 995 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb11.op_tree
#line 374 "gram.y"
, CONSTANT, NULL, NULL,
#line 999 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->cL[0]->yyyAttrbs.yyyAttrb2.val
#line 374 "gram.y"
, NULL);
#line 1003 "oxout.y"
yyyAdjustINRC(50,1,225,228,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyReclaimSemStkEls(1,&(yyvsp[(1) - (1)].yyyOxAttrbs));}}
    break;

  case 53:
#line 1010 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(51,1,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));

#line 377 "gram.y"


#line 378 "gram.y"
NEW_OP_TREE_NODE(
#line 1019 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb11.op_tree
#line 378 "gram.y"
, VARUSE, NULL, NULL, 0,
#line 1023 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->cL[0]->yyyAttrbs.yyyAttrb1.val
#line 378 "gram.y"
)

#line 1028 "oxout.y"
yyyAdjustINRC(51,1,228,231,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyReclaimSemStkEls(1,&(yyvsp[(1) - (1)].yyyOxAttrbs));}}
    break;

  case 54:
#line 1035 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(52,3,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));

#line 383 "gram.y"


#line 1042 "oxout.y"
(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb11.op_tree
#line 384 "gram.y"
  = NULL;
#line 1046 "oxout.y"
yyyAdjustINRC(52,3,231,234,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyReclaimSemStkEls(3,&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));}}
    break;

  case 55:
#line 1053 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(53,4,2,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (4)].yyyOxAttrbs),&(yyvsp[(2) - (4)].yyyOxAttrbs),&(yyvsp[(3) - (4)].yyyOxAttrbs),&(yyvsp[(4) - (4)].yyyOxAttrbs));

(yyval.yyyOxAttrbs).yyyOxStackItem->node->yyyAttrbs.yyyAttrb11.op_tree
#line 389 "gram.y"
  = NULL;
#line 1060 "oxout.y"
yyyAdjustINRC(53,4,234,240,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (4)].yyyOxAttrbs),&(yyvsp[(2) - (4)].yyyOxAttrbs),&(yyvsp[(3) - (4)].yyyOxAttrbs),&(yyvsp[(4) - (4)].yyyOxAttrbs));
yyyReclaimSemStkEls(4,&(yyvsp[(1) - (4)].yyyOxAttrbs),&(yyvsp[(2) - (4)].yyyOxAttrbs),&(yyvsp[(3) - (4)].yyyOxAttrbs),&(yyvsp[(4) - (4)].yyyOxAttrbs));}}
    break;

  case 56:
#line 1069 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(54,3,1,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyAdjustINRC(54,3,240,246,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));
yyyReclaimSemStkEls(3,&(yyvsp[(1) - (3)].yyyOxAttrbs),&(yyvsp[(2) - (3)].yyyOxAttrbs),&(yyvsp[(3) - (3)].yyyOxAttrbs));}}
    break;

  case 57:
#line 1078 "oxout.y"
    {if(yyyYok){
yyyGenIntNode(55,1,1,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyAdjustINRC(55,1,246,249,&(yyval.yyyOxAttrbs),&(yyvsp[(1) - (1)].yyyOxAttrbs));
yyyReclaimSemStkEls(1,&(yyvsp[(1) - (1)].yyyOxAttrbs));}}
    break;


/* Line 1267 of yacc.c.  */
#line 2380 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 404 "gram.y"

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




