    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
    #include <string.h>
    #include "codegen.h"

    #define CHECK_NUM "test $1, %s\njnz raisesig\n"

    registers_t registers = { .regnames = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"}, .regs_used = 0, .varnames = {NULL, NULL, NULL, NULL, NULL, NULL}};
#include <limits.h>
#include <stdlib.h>
#ifndef STATE_TYPE
#define STATE_TYPE int
#endif
#ifndef ALLOC
#define ALLOC(n) malloc(n)
#endif
#ifndef burm_assert
#define burm_assert(x,y) if (!(x)) { y; abort(); }
#endif

#define burm_reg_NT 1
#define burm_con_NT 2
int burm_max_nt = 2;

struct burm_state {
	int op;
	struct burm_state *left, *right;
	short cost[3];
	struct {
		unsigned burm_reg:3;
		unsigned burm_con:1;
	} rule;
};

static short burm_nts_0[] = { 0 };
static short burm_nts_1[] = { burm_con_NT, 0 };
static short burm_nts_2[] = { burm_reg_NT, 0 };
static short burm_nts_3[] = { burm_reg_NT, burm_reg_NT, 0 };

short *burm_nts[] = {
	0,	/* 0 */
	burm_nts_0,	/* 1 */
	burm_nts_0,	/* 2 */
	burm_nts_0,	/* 3 */
	burm_nts_1,	/* 4 */
	burm_nts_1,	/* 5 */
	burm_nts_2,	/* 6 */
	burm_nts_3,	/* 7 */
};

char burm_arity[] = {
	0,	/* 0 */
	0,	/* 1=ASSIGN */
	0,	/* 2=CONSTANT */
	0,	/* 3=VARDEF */
	1,	/* 4=RET */
	2,	/* 5=ADD */
	0,	/* 6=MUL */
	0,	/* 7=VARUSE */
};

static short burm_decode_reg[] = {
	0,
	2,
	3,
	4,
	5,
	6,
	7,
};

static short burm_decode_con[] = {
	0,
	1,
};

int burm_rule(STATE_TYPE state, int goalnt) {
	burm_assert(goalnt >= 1 && goalnt <= 2, PANIC("Bad goal nonterminal %d in burm_rule\n", goalnt));
	if (!state)
		return 0;
	switch (goalnt) {
	case burm_reg_NT:	return burm_decode_reg[((struct burm_state *)state)->rule.burm_reg];
	case burm_con_NT:	return burm_decode_con[((struct burm_state *)state)->rule.burm_con];
	default:
		burm_assert(0, PANIC("Bad goal nonterminal %d in burm_rule\n", goalnt));
	}
	return 0;
}

static void burm_closure_con(struct burm_state *, int);

static void burm_closure_con(struct burm_state *p, int c) {
	if (c + 1 < p->cost[burm_reg_NT]) {
		p->cost[burm_reg_NT] = c + 1;
		p->rule.burm_reg = 3;
	}
}

STATE_TYPE burm_state(int op, STATE_TYPE left, STATE_TYPE right) {
	int c;
	struct burm_state *p, *l = (struct burm_state *)left,
		*r = (struct burm_state *)right;

	assert(sizeof (STATE_TYPE) >= sizeof (void *));
	if (burm_arity[op] > 0) {
		p = ALLOC(sizeof *p);
		burm_assert(p, PANIC("ALLOC returned NULL in burm_state\n"));
		p->op = op;
		p->left = l;
		p->right = r;
		p->rule.burm_reg = 0;
		p->cost[1] =
		p->cost[2] =
			32767;
	}
	switch (op) {
	case 1: /* ASSIGN */
		{
			static struct burm_state z = { 1, 0, 0,
				{	0,
					32767,
					32767,
				},{
					0,
					0,
				}
			};
			return (STATE_TYPE)&z;
		}
	case 2: /* CONSTANT */
		{
			static struct burm_state z = { 2, 0, 0,
				{	0,
					1,	/* reg: con */
					0,	/* con: CONSTANT */
				},{
					3,	/* reg: con */
					1,	/* con: CONSTANT */
				}
			};
			return (STATE_TYPE)&z;
		}
	case 3: /* VARDEF */
		{
			static struct burm_state z = { 3, 0, 0,
				{	0,
					0,	/* reg: VARDEF */
					32767,
				},{
					1,	/* reg: VARDEF */
					0,
				}
			};
			return (STATE_TYPE)&z;
		}
	case 4: /* RET */
		assert(l);
		{	/* reg: RET(reg) */
			c = l->cost[burm_reg_NT] + 1;
			if (c + 0 < p->cost[burm_reg_NT]) {
				p->cost[burm_reg_NT] = c + 0;
				p->rule.burm_reg = 5;
			}
		}
		{	/* reg: RET(con) */
			c = l->cost[burm_con_NT] + 1;
			if (c + 0 < p->cost[burm_reg_NT]) {
				p->cost[burm_reg_NT] = c + 0;
				p->rule.burm_reg = 4;
			}
		}
		break;
	case 5: /* ADD */
		assert(l && r);
		{	/* reg: ADD(reg,reg) */
			c = l->cost[burm_reg_NT] + r->cost[burm_reg_NT] + 2;
			if (c + 0 < p->cost[burm_reg_NT]) {
				p->cost[burm_reg_NT] = c + 0;
				p->rule.burm_reg = 6;
			}
		}
		break;
	case 6: /* MUL */
		{
			static struct burm_state z = { 6, 0, 0,
				{	0,
					32767,
					32767,
				},{
					0,
					0,
				}
			};
			return (STATE_TYPE)&z;
		}
	case 7: /* VARUSE */
		{
			static struct burm_state z = { 7, 0, 0,
				{	0,
					0,	/* reg: VARUSE */
					32767,
				},{
					2,	/* reg: VARUSE */
					0,
				}
			};
			return (STATE_TYPE)&z;
		}
	default:
		burm_assert(0, PANIC("Bad operator %d in burm_state\n", op));
	}
	return (STATE_TYPE)p;
}

#ifdef STATE_LABEL
static void burm_label1(NODEPTR_TYPE p) {
	burm_assert(p, PANIC("NULL tree in burm_label\n"));
	switch (burm_arity[OP_LABEL(p)]) {
	case 0:
		STATE_LABEL(p) = burm_state(OP_LABEL(p), 0, 0);
		break;
	case 1:
		burm_label1(LEFT_CHILD(p));
		STATE_LABEL(p) = burm_state(OP_LABEL(p),
			STATE_LABEL(LEFT_CHILD(p)), 0);
		break;
	case 2:
		burm_label1(LEFT_CHILD(p));
		burm_label1(RIGHT_CHILD(p));
		STATE_LABEL(p) = burm_state(OP_LABEL(p),
			STATE_LABEL(LEFT_CHILD(p)),
			STATE_LABEL(RIGHT_CHILD(p)));
		break;
	}
}

STATE_TYPE burm_label(NODEPTR_TYPE p) {
	burm_label1(p);
	return ((struct burm_state *)STATE_LABEL(p))->rule.burm_reg ? STATE_LABEL(p) : 0;
}

NODEPTR_TYPE *burm_kids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	burm_assert(p, PANIC("NULL tree in burm_kids\n"));
	burm_assert(kids, PANIC("NULL kids in burm_kids\n"));
	switch (eruleno) {
	case 3: /* reg: VARUSE */
	case 2: /* reg: VARDEF */
	case 1: /* con: CONSTANT */
		break;
	case 4: /* reg: con */
		kids[0] = p;
		break;
	case 6: /* reg: RET(reg) */
	case 5: /* reg: RET(con) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 7: /* reg: ADD(reg,reg) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	default:
		burm_assert(0, PANIC("Bad external rule number %d in burm_kids\n", eruleno));
	}
	return kids;
}

int burm_op_label(NODEPTR_TYPE p) {
	burm_assert(p, PANIC("NULL tree in burm_op_label\n"));
	return OP_LABEL(p);
}

STATE_TYPE burm_state_label(NODEPTR_TYPE p) {
	burm_assert(p, PANIC("NULL tree in burm_state_label\n"));
	return STATE_LABEL(p);
}

NODEPTR_TYPE burm_child(NODEPTR_TYPE p, int index) {
	burm_assert(p, PANIC("NULL tree in burm_child\n"));
	switch (index) {
	case 0:	return LEFT_CHILD(p);
	case 1:	return RIGHT_CHILD(p);
	}
	burm_assert(0, PANIC("Bad index %d in burm_child\n", index));
	return 0;
}

#endif
void burm_reduce(NODEPTR_TYPE bnode, int goalnt)
{
  int ruleNo = burm_rule (STATE_LABEL(bnode), goalnt);
  short *nts = burm_nts[ruleNo];
  NODEPTR_TYPE kids[100];
  int i;

  if (ruleNo==0) {
    fprintf(stderr, "tree cannot be derived from start symbol");
    exit(1);
  }
  burm_kids (bnode, ruleNo, kids);
  for (i = 0; nts[i]; i++)
    burm_reduce (kids[i], nts[i]);    /* reduce kids */

#if DEBUG
  printf ("%s", burm_string[ruleNo]);  /* display rule */
#endif

  switch (ruleNo) {
  case 1:

    break;
  case 2:
 NEWVAR(bnode);
    break;
  case 3:
 SET_VARREG(bnode)
    break;
  case 4:
 NEWREG(bnode) printf("movq $%u, %s\nshlq $1, %s\n", kids[0]->val, bnode->regname, bnode->regname);
    break;
  case 5:
 printf("movq $%u, %%rax\nshlq $1, %%rax\nret\n", kids[0]->val);
    break;
  case 6:
 printf("movq %s, %%rax\nret\n", kids[0]->regname); FREEREG(1)
    break;
  case 7:
 NEWREG(bnode) printf(CHECK_NUM CHECK_NUM "movq %s, %s\naddq %s, %s\n",kids[0]->regname, kids[1]->regname, kids[0]->regname, bnode->regname, kids[1]->regname, bnode->regname); FREEREG(2)
    break;
  default:    assert (0);
  }
}
