/**
 * @file   math.c
 * @date   03-31-2026
 * @author Hongwei, GUO  (999014780)
 * @author Zhiyuan, CHEN (999014756)
 * @brief  This file contains all implementations of math related functions 
 *         declared in the header file `standard.h`.
 */


#include <stdlib.h>
#include "standard.h"


int min(const int a, const int b) {
    return (a <= b) ? a : b;
}


int minimum(const int size, int values[size]) {
    if ( size == 0 ) {
        return MIN_VALUE;
    } else {
        int min_value = values[0];
        for (int i = 0; i < size; i++) {
            min_value = min(min_value, values[i]);
        }
        return min_value;
    }
}


boolean is_even(const int value) {
    return (value % 2 == 0) ? TRUE : FALSE;
}


boolean is_odd(const int value) {
    return (value % 2 != 0) ? TRUE : FALSE;
}


boolean is_prime(const natural value)
{
    if ( value < 2 ) {
        return FALSE;
    } else if ( value == 2 ) {
        return TRUE;
    } else {
        boolean res = TRUE;
        natural div = 2;
        while ( res && div < value ) {
            if ( value % div == 0 ) {
                res = FALSE;
            } else {
                div++;
            }
        }
        return res;
    }
}


natural fibonacci(const natural nth)
{
    if ( nth == 0 || nth == 1 ) {
        return nth;
    } else {
        natural * fib_nums = (natural *) malloc((nth+1) * sizeof(natural));
        fib_nums[0] = 0;
        fib_nums[1] = 1;
        for (int i = 2; i <= nth; i++) {
            fib_nums[i] = fib_nums[i-1] + fib_nums[i-2];
        }
        natural fib_nth = fib_nums[nth];
        free(fib_nums);
        return fib_nth;
    }
}