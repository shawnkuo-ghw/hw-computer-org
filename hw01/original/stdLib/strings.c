#include "standard.h"
#include <stdlib.h>

unsigned int length(const char * string) {
    //TODO: complete
}

boolean equals(const char * string1, const char * string2) {
    //TODO: complete
}

int index_of(const char * string, const char e) {
    int idx = 0;
    boolean found = FALSE;
    while (string[idx] != 0) {
        if (string[idx] == e) {
            return idx;
        }
        idx++;
    }
    return found?idx:-1;
}

int last_index_of(const char * string, const char e) {
    //TODO: complete
}

#define LOWER_CASE_MIN 97
#define LOWER_CASE_MAX 122

#define UPPER_CASE_MIN 65
#define UPPER_CASE_MAX 90

#define CASE_DIFF 32

char * to_lower_case(const char * string) {
    //TODO: complete
}

char * to_upper_case(const char * string) {
    //TODO: complete
}

//TODO create a private function (use the `static` keyword) which will
//     switch a range of characters by a certain constant value, the profile
//     will be:
//     `static char shift_in_range(const char c, unsigned int range_start, unsigned int range_end, const int shift)`

char * substring(const char * string, unsigned int from, unsigned int to) {
    //TODO: complete
}