#ifndef CODEGEN_H
#define CODEGEN_H

typedef enum op {
    ASSIGN = 1,
    CONSTANT = 2,
    VARDEF = 3,
    RET = 4,
    ADD = 5,
    MUL = 6,
    VARUSE = 7,
    SUB = 8,
    MKLIST = 9,
    HEADOP = 10,
    TAILOP = 11,
    NOTOP = 12,
    ISLISTOP = 13,
    OROP = 14,
    EQOP = 15,
    GTEQOP = 16,
    VARSET = 17,
} op_t;

typedef struct burm_state *STATEPTR_TYPE;

typedef struct op_tree {
    op_t op;
    struct op_tree *kids[2];
    STATEPTR_TYPE state;
    char *regname;
    char *varname;
    long val;
} op_tree_t;
#define NODEPTR_TYPE op_tree_t*

#define REGCOUNT 6
typedef struct registers {
    char *regnames[REGCOUNT];
    char *varnames[REGCOUNT];
    int regs_used[REGCOUNT];
} registers_t;

#define PANIC printf
#define OP_LABEL(p) ((p)->op)
#define LEFT_CHILD(p) ((p)->kids[0])
#define RIGHT_CHILD(p) ((p)->kids[1])
#define STATE_LABEL(p) ((p)->state)

void newreg(registers_t *registers, NODEPTR_TYPE p);
#define NEWREG(p) newreg(&registers, p);

void freereg(registers_t *registers, char* regname);
#define FREEREG(regname) freereg(&registers, regname);
    
void newvar(registers_t *registers, NODEPTR_TYPE p);
#define NEWVAR(p) newvar(&registers, p);

void set_varreg(registers_t *registers, NODEPTR_TYPE p);
#define SET_VARREG(p) set_varreg(&registers, p);

char* gen_label(char* prefix);
    
#define NEW_OP_TREE_NODE(t, opval, k1, k2, _val, _varname) \
    t = malloc(sizeof(op_tree_t)); \
    t->op = opval; \
    t->kids[0] = k1; \
    t->kids[1] = k2; \
    t->state = 0; \
    t->regname = NULL; \
    t->val = _val; \
    t->varname = _varname;

#endif