#include "standard.h"
#include <stdlib.h>

  
static char shift_in_range(const char c, unsigned int range_start, unsigned int range_end, const int shift);


unsigned int length(const char * string) {
    // DONE by lms
    unsigned int len = 0;
    while (string[len] != '\0') {
        len ++;
    }
    return len;
}

boolean equals(const char * string1, const char * string2) {
    // DONE by ghw
    boolean is_equal = TRUE;
    if ( string1 != string2 ) {
        unsigned int len1 = length(string1);
        unsigned int len2 = length(string2);
        if ( len1 != len2 ) {
            is_equal = FALSE;
        } else {
            unsigned int i = 0;
            while ( is_equal && i < len1 ) {
                if ( string1[i] != string2[i] ) {
                    is_equal = FALSE;
                } else {
                    i ++;
                }
            }
        }
    }
    return is_equal;
}

int index_of(const char * string, const char e) {
    // DONE by ghw
    int i = 0;
    int idx = -1;
    boolean found = FALSE;
    while ( !found && string[i] != '\0') {
        if (string[i] == e) {
            idx = i;
            found = TRUE;
        } else {
            i ++;
        }
    }
    return idx;
}

int last_index_of(const char * string, const char e) {
    // DONE by ghw
    int idx = -1;
    int len = length(string);
    if ( len > 0 ) {
        int i = len - 1;
        boolean found = FALSE;
        while ( !found && i > -1 ) {
            if ( string[i] == e ) {
                found = TRUE;
                idx = i;
            } else {
                i --;
            }
        }
    }
    return idx;  
}

#define LOWER_CASE_MIN 97
#define LOWER_CASE_MAX 122

#define UPPER_CASE_MIN 65
#define UPPER_CASE_MAX 90

#define CASE_DIFF 32

char * to_lower_case(const char * string) {
    // DONE by ghw
    unsigned int len = length(string);
    char * new_str = NULL;
    if ( len > 0 ) {
        new_str = (char *) malloc( sizeof(char) * (len+1) );
        for ( unsigned int i = 0; i < len; i++ ) {
            new_str[i] = shift_in_range(string[i], UPPER_CASE_MIN, UPPER_CASE_MAX, CASE_DIFF);
        }
        new_str[len] = '\0';
    }
    return new_str;
}

char * to_upper_case(const char * string) {
    // DONE by ghw
    unsigned int len = length(string);
    char * new_str = NULL;
    if ( len > 0 ) {
        new_str = malloc( sizeof(char) * (len+1) );
        for (unsigned int i = 0; i < len; i++) {
            new_str[i] = shift_in_range(string[i], LOWER_CASE_MIN, LOWER_CASE_MAX, -CASE_DIFF);  
        }
        new_str[len] = '\0';  
    }
    return new_str;
}


/*
    a private function which will switch a range of characters by a certain constant value.
*/
static char shift_in_range(const char c, unsigned int range_start, unsigned int range_end, const int shift) {
    // DONE by lms
    if (range_start <= c && c <= range_end) {  
        return c + shift;  
    }
    return c;  
}
   

char * substring(const char * string, unsigned int from, unsigned int to) {
    // DONE by ghw
    char * substr = NULL;
    int len = length(string);
    if ( len > 0 && 0 <= from && from < to && to <= len ) {
        int sublen = to - from;
        substr = (char *) malloc( sizeof(char) * (sublen+1) );
        for ( unsigned int i = 0; i < sublen; i++ ) {
            substr[i] = string[from + i];
        }
        substr[sublen] = '\0';
    }
    return substr;
}