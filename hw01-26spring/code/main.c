/**
 * @file   main.c
 * @date   03-31-2026
 * @author Hongwei, GUO  (999014780)
 * @author Zhiyuan, CHEN (999014756)
 * @brief  This file contains some test cases for all the functions declared in
 *         the header file `standard.h`.
 */


#include <stdio.h>
#include <stdlib.h>
#include "standard.h"

#define SIZE 42
#define MAX_VALUE 15

void print_array(const int size, const int values[size]);

void main(int argc, char ** argv)
{
    printf("===================== Math Methods Tests =====================\n\n");

    int values[SIZE];
    int seed = argc>1?atoi(argv[1]):33;
    srand(seed);
    for (int i = 0; i < SIZE; i++) {
        values[i] = rand() % MAX_VALUE;
    }
    
    /* check min and minimum*/

    printf("--------------------- min and minimum ---------------------\n\n");
    printf("min(1,2):   %2d\n", min(1,2));
    printf("min(2,1):   %2d\n", min(2,1));
    printf("min(-1, 1): %2d\n", min(-1, 1));
    printf("min(1, -1): %2d\n", min(1, -1));
    print_array(SIZE, values);
    printf("minimum element: %d\n", minimum(SIZE, values));

    /* check is_even, is_odd and is_prime */

    printf("\n\n--------------------- is_even, is_odd and is_prime ---------------------\n\n");
    for (int i = 0; i < SIZE; i++) {
        printf("is_even(%1$2d): %2$2d  |  is_odd(%1$2d): %3$2d  |  is_prime(%1$2d): %4$2d\n",
            values[i],
            is_even(values[i]),
            is_odd(values[i]),
            is_prime(values[i])
        );
    }

    /* check fibonacci */

    printf("\n\n--------------------- fibonacci ---------------------\n\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%2d-th fibonacci number: %d\n", i, fibonacci(i));
    }


    printf("\n\n===================== String Methods Tests =====================\n\n");
    
    string str0 = "gtiiiit";
    string str1 = "heLlo";
    string str2 = "wORld!!!";
    string str3 = "hello";
    string str4 = "hello";
    string strs[5] = {str0, str1, str2, str3, str4};

    /* check length */

    printf("-------------------- length --------------------\n\n");
    for (int i = 0; i < 5; i++) {
        printf("length(%10s) = %d\n", strs[i], length(strs[i]));
    }

    /* check equals */

    printf("\n\n-------------------- equals --------------------\n\n");
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            printf("equals(%10s, %10s) = %d\n", strs[i], strs[j], equals(strs[i], strs[j]));
        }
    }

    /* check index_of and last_index_of */

    printf("\n\n-------------------- index_of and last_index_of --------------------\n\n");
    char chars[5] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("index_of(%10s, %c) = %2d\n", strs[i], chars[j], index_of(strs[i], chars[j]));    
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("last_index_of(%10s, %c) = %2d\n", strs[i], chars[j], last_index_of(strs[i], chars[j]));
        }
    }

    /* check to_lower_case and to_upper_case */

    printf("\n\n-------------------- to_lower_case and to_upper_case --------------------\n\n");
    for (int i = 0; i < 5; i++) {
        printf("to_lower_case(%10s) = %s\n", strs[i], to_lower_case(strs[i]));
        printf("to_upper_case(%10s) = %s\n", strs[i], to_upper_case(strs[i]));
    }

    /* check starts_with */

    printf("\n\n-------------------- starts_with --------------------\n\n");
    string prefix0 = "hel";
    string prefix1 = "gtii";
    string prefix2 = "helloo";
    string prefix3 = "wOR";
    string prefix4 = "hello";
    string prefixs[5] = {prefix0, prefix1, prefix2, prefix3, prefix4};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("starts_with(%10s, %10s) = %d\n", strs[i], prefixs[j], starts_with(strs[i], prefixs[j]));
        }
    }

    /* check find */
    
    printf("\n\n-------------------- find --------------------\n\n");
    string substr0 = "iii";
    string substr1 = "Llo";
    string substr2 = "Rld";
    string substr3 = "el";
    string substr4 = "lo";
    string substrs[5] = {substr0, substr1, substr2, substr3, substr4};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("find(%10s, %10s) = %2d\n", strs[i], substrs[j], find(strs[i], substrs[j]));
        }
    }

    /* check replace_first */
    
    printf("\n\n-------------------- replace_first --------------------\n\n");
    string replacement = "REPLACEMENT";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("replace_first(%10s, %10s, %15s) = %20s\n",
                strs[i],
                substrs[j],
                replacement,
                replace_first(strs[i], substrs[j], replacement)
            );
        }
    }


    printf("\n\n===================== Boolean Methods Tests =====================\n\n");

    /* check NOT, AND and OR */ 
    
    printf("--------------------- NOT, AND and OR ---------------------\n\n");
    const boolean booleans[2] = {TRUE, FALSE};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            struct expression * e = NOT( 
                AND(
                    BOOLEAN_VALUE(booleans[i]),
                    OR(
                        BOOLEAN_VALUE(booleans[i]),
                        BOOLEAN_VALUE(booleans[j])
                    )
                )
            );
            printf("NOT(AND(%d, OR(%d, %d))): %d\n",
                booleans[i],
                booleans[i],
                booleans[j],
                eval(e)
            );
            drop(e);
        }
    }

    /* check IMPLIES */

    printf("\n\n--------------------- IMPLIES ---------------------\n\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            struct expression * e = IMPLIES(
                BOOLEAN_VALUE(booleans[i]),
                BOOLEAN_VALUE(booleans[j])
            );
            printf("IMPLIES(%d, %d))): %d\n",
                booleans[i],
                booleans[j],
                eval(e)
            );
            drop(e);
        }
    }
}

void print_array(const int size, const int values[size]) {
    printf("array: [");
    for (int i = 0; i < size; i++) {
        if (i == size-1)
            printf("%d", values[i]);
        else
            printf("%d, ", values[i]);
    }
    printf("]\n");
}