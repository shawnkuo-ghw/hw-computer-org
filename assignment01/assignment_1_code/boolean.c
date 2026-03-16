#include "standard.h"
#include <stdlib.h>


enum {VALUE, NOT_OP, AND_OP, OR_OP};

struct expression {
    int tag;
    union {
        struct expression* childs[2];
        boolean value;
    } e;
};

struct expression* BOOLEAN_VALUE(boolean value) {
    struct expression* r = malloc(sizeof(struct expression));
    r->tag = VALUE;
    r->e.value = value;
    return r;
}

struct expression* NOT(struct expression* e)
{
    struct expression* r = malloc(sizeof(struct expression));
    r->tag = NOT_OP;
    r->e.childs[0] = e;
    r->e.childs[1] = 0;
    return r;
}


boolean eval(struct expression* expr)
{
    switch (expr->tag) {
        case VALUE:   return expr->e.value;
        case NOT_OP: return not(eval(expr->e.childs[0]));
    }
}

void drop(struct expression* expr) {
    switch (expr->tag) {
        case VALUE:   free(expr); break;
        case NOT_OP: drop(expr->e.childs[0]); free(expr); break;
        default:     drop(expr->e.childs[0]); drop(expr->e.childs[1]); free(expr);
    }
}
