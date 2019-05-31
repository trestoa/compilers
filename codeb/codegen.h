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
    GTEQOP = 16
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
    int *regs_used[REGCOUNT];
} registers_t;

#define PANIC printf
#define OP_LABEL(p) ((p)->op)
#define LEFT_CHILD(p) ((p)->kids[0])
#define RIGHT_CHILD(p) ((p)->kids[1])
#define STATE_LABEL(p) ((p)->state)
#define NEWREG(p) \
    if(registers.regs_used == 6) { printf("To many variables used.\n"); exit(4); } \
    p->regname = registers.regnames[registers.regs_used++];

#define FREEREG(regname) \
    for(int i = 0; i < REGCOUNT; i++) { \
        if(strcmp(regname, registers.regnames[i]) == 0) { \
            registers.regs_used[i] = 0; \
            registers.varnames[i] = NULL; \
            break; \
        } \
    }

#define NEWVAR(p) \
    for(int i = 0; i < REGCOUNT; i++) { \
        if(registers.regs_ues[i] == 0) { \
            p->regname = registers.regnames[i]; \
            registers.varnames[i] = p->varname; \
            break; \
        } \
    } \
    printf("To many variables used.\n"); \
    exit(4);

#define SET_VARREG(p) \
    for(int i = 0; i < REGCOUNT; i++) { \
        if(strcmp(p->varname, registers.varnames[i]) == 0) { \
            p->regname = registers.regnames[i]; \
            break; \
        } \
    }

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