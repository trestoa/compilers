#include "codegen.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void newreg(registers_t *registers, NODEPTR_TYPE p) {
    for(int i = 0; i < REGCOUNT; i++) {
        if(registers->regs_used[i] == 0) {
            registers->regs_used[i] = 1;
            p->regname = registers->regnames[i];
            return;
        }
    }
    printf("To many variables used.\n"); 
    exit(4);
}

void freereg(registers_t *registers, char* regname) {
    for(int i = 0; i < REGCOUNT; i++) {
        if(strcmp(regname, registers->regnames[i]) == 0) {
            registers->regs_used[i] = 0;
            registers->varnames[i] = NULL;
            return;
        }
    }
}

void newvar(registers_t *registers, NODEPTR_TYPE p) {
    for(int i = 0; i < REGCOUNT; i++) {
        if(registers->regs_used[i] == 0) { 
            registers->regs_used[i] = 1;
            p->regname = registers->regnames[i];
            registers->varnames[i] = p->varname;
            return;
        }
    }
    printf("To many variables used.\n");
    exit(4);
}

void set_varreg(registers_t *registers, NODEPTR_TYPE p) {
    for(int i = 0; i < REGCOUNT; i++) {
        if(strcmp(p->varname, registers->varnames[i]) == 0) {
            p->regname = registers->regnames[i];
            return;
        }
    }
}