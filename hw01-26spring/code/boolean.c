/**
 * @file   boolean.c
 * @date   03-31-2026
 * @author Hongwei, GUO  (999014780)
 * @author Zhiyuan, CHEN (999014756)
 * @brief  This file contains all implementations of boolean related functions 
 *         declared in the header file `standard.h`.
 */


#include "standard.h"
#include <stdlib.h>


boolean not(const boolean a)                      { return !a; }
boolean and(const boolean a, const boolean b)     { return a && b; }
boolean or(const boolean a, const boolean b)      { return a || b; }
boolean xor(const boolean a, const boolean b)     { return a ^ b; }
boolean implies(const boolean a, const boolean b) { return !a || b; }


/* the types of all possible boolean expressions */
typedef enum EXPR_TYPE {
    VALUE,  /* single boolean value expression */
    NOT_OP, /* negation expression */
    AND_OP, /* conjunctoin expression */
    OR_OP,  /* didjuncton expression */
    IMP_OP  /* implication expression */
} EXPR_TYPE;


struct expression {
    EXPR_TYPE tag;
    union {
        struct expression* childs[2];
        boolean value;
    } e;
};


struct expression* BOOLEAN_VALUE(boolean value)
{
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


struct expression* AND(struct expression* left, struct expression* right)
{
    struct expression* r = malloc(sizeof(struct expression));
    r->tag = AND_OP;
    r->e.childs[0] = left;
    r->e.childs[1] = right;
    return r;
}


struct expression* OR(struct expression* left, struct expression* right)
{
    struct expression* r = malloc(sizeof(struct expression));
    r->tag = OR_OP;
    r->e.childs[0] = left;
    r->e.childs[1] = right;
    return r;
}


struct expression* IMPLIES(struct expression* left, struct expression* right)
{
    struct expression* r = malloc(sizeof(struct expression));
    r->tag = IMP_OP;
    r->e.childs[0] = left;
    r->e.childs[1] = right;
    return r;    
}


boolean eval(struct expression* expr)
{
    switch (expr->tag) {
        case VALUE:  return expr->e.value;
        case NOT_OP: return not(eval(expr->e.childs[0]));
        case AND_OP: return and(eval(expr->e.childs[0]), eval(expr->e.childs[1]));
        case OR_OP:  return  or(eval(expr->e.childs[0]), eval(expr->e.childs[1]));
        case IMP_OP: return implies(eval(expr->e.childs[0]), eval(expr->e.childs[1]));
        default:     return TRUE;
    }
}


void drop(struct expression* expr)
{
    switch (expr->tag) {
        case VALUE:   free(expr); break;
        case NOT_OP: drop(expr->e.childs[0]); free(expr); break;
        default:     drop(expr->e.childs[0]); drop(expr->e.childs[1]); free(expr);
    }
}