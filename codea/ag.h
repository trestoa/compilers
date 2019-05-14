#ifndef AG_H
#define AG_H

typedef enum symbol_type {
    LABEL = 0,
    VARIABLE = 1
} symbol_type_t;

typedef struct symbol {
    symbol_type_t type;
    char *name;
    struct symbol *next;
} symbol_t;

#endif