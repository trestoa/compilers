#ifndef CODEGEN_H
#define CODEGEN_H

typedef enum op {
    ASSIGN = 1,
    CONSTANT = 2,
    VARDEF = 3,
    RET = 4

} op_t;

#define STATEPTR_TYPE long
#define STATE_TYPE long

typedef struct op_tree {
    op_t op;
    struct op_tree *kids[2];
    STATEPTR_TYPE state;
    char *regname;
    long val;
} op_tree_t;
#define NODEPTR_TYPE op_tree_t*

typedef struct registers {
    char *regnames[6];
    int regs_used;
} registers_t;

#define PANIC printf
#define OP_LABEL(p) ((p)->op)
#define LEFT_CHILD(p) ((p)->kids[0])
#define RIGHT_CHILD(p) ((p)->kids[1])
#define STATE_LABEL(p) ((p)->state)
#define NEWREG(p) \
    if(registers.regs_used == 6) { printf("To many variables used.\n"); exit(4); } \
    p->regname = registers.regnames[registers.regs_used++];

#define NEW_OP_TREE_NODE(t, opval, k1, k2, _val) \
    t = malloc(sizeof(op_tree_t)); \
    t->op = opval; \
    t->kids[0] = k1; \
    t->kids[1] = k2; \
    t->state = 0; \
    t->regname = NULL; \
    t->val = _val;


#endif