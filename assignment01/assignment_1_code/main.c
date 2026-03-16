#include <stdio.h>
#include <stdlib.h>
#include "standard.h"

#define SIZE 42
#define MAX_VALUE 15

void print_array(const int size, const int values[size]);

void main(int argc, char ** argv) {

    int values[SIZE];
    int seed = argc>1?atoi(argv[1]):33;
    srand(seed);
    for (int i = 0; i < SIZE; i++) {
        values[i] = rand() % MAX_VALUE;
    }
    
    //we could just print all evaluations, or check if a boolean expression is a tautology, is satisfiable, or is a contradiction
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
            //do something
            drop(e);
        }
    }
}
