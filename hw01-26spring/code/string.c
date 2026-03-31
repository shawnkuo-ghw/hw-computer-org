/**
 * @file   string.c
 * @date   03-31-2026
 * @author Hongwei, GUO  (999014780)
 * @author Zhiyuan, CHEN (999014756)
 * @brief  This file contains all implementations of strings related functions 
 *         declared in the header file `standard.h`.
 */


#include <stdlib.h>
#include "standard.h"


/* Switchs a range of characters by a certain constant value*/
static char shift_in_range(
    const char    c,            /* input char */
    const natural range_start,  /* start of the range of target char */
    const natural range_end,    /* end of the range of target char */
    const int     shift         /* shifting value */
) { return (range_start <= c && c <= range_end) ? c + shift : c; }


natural length(const string const str)
{
    natural len = 0;
    while ( str[len] != '\0' ) { len++; }
    return len;
}


boolean equals(const string const str1, const string const str2)
{
    natural len1 = length(str1);
    natural len2 = length(str2);
    if ( len1 != len2 ) {
        return FALSE;
    } else {
        boolean is_equal = TRUE;
        natural i = 0;
        while ( is_equal && i < len1 ) {
            if ( str1[i] != str2[i] ) {
                is_equal = FALSE;
            } else { i++; }
        }
        return is_equal;      
    }
}


int index_of(const string const str, const char e)
{
    int index = -1;
    int i = 0;
    natural len = length(str);
    boolean has_found = FALSE;
    while ( !has_found && i < len ) {
        if ( str[i] == e ) {
            has_found = TRUE;
            index = i;
        } else { i++; }
    }
    return index;
}


int last_index_of(const string const str, const char e)
{
    int index = -1;
    int i = length(str) - 1;
    boolean has_found = FALSE;
    while ( !has_found && i >= 0 ) {
        if ( str[i] == e ) {
            has_found = TRUE;
            index = i;
        } else { i--; }
    }
    return index;
}


string to_lower_case(const string const str)
{
    natural len = length(str);
    string new_str = (string) malloc( (len + 1) * sizeof(char) );
    for (int i = 0; i < len; i++) {
        new_str[i] = shift_in_range(str[i], 'A', 'Z', 'a' - 'A');
    }
    new_str[len] = '\0';
    return new_str;
}


string to_upper_case(const string const str)
{
    natural len = length(str);
    string new_str = (string) malloc( (len + 1) * sizeof(char) );
    for (int i = 0; i < len; i++) {
        new_str[i] = shift_in_range(str[i], 'a', 'z', 'A' - 'a');
    }
    new_str[len] = '\0';
    return new_str;
}


boolean starts_with(const string const str, const string const prefix)
{
    natural len_str = length(str);
    natural len_pre = length(prefix);
    if ( len_pre > len_str ) {
        return FALSE;
    } else {
        boolean res = TRUE;
        int i = 0;
        while ( res && i < len_pre ) {
            if ( str[i] != prefix[i] ) {
                res = FALSE;
            } else { i++; }
        }
        return res;
    }
}


/*
    Returns whether substring `substr` occurs at the index `start_idx` in the string `str`
    Returns `TRUE` iff for every `j` in `[0..length(substr)]`, `str[start_idx + j] == substr[j]`.
*/
static boolean check_substr(
    const string const str,     /* string */
    natural start_idx,          /* starting index of string */
    const string const substr,  /* substring */
    const natural substr_length /* the length of substring */
) {
    boolean is_substr = TRUE;
    int i = 0; 
    while ( is_substr && i < substr_length ) {
        if ( str[start_idx + i] == '\0' || str[start_idx + i] != substr[i] ) {
            is_substr = FALSE;
        } else { i++; }
    }
    return is_substr;
}

int find(const string const str, const string const substr)
{
    natural len_str = length(str);
    natural len_sub = length(substr);
    if ( len_str < len_sub ) {
        return -1;
    } else {
        boolean has_found = FALSE;
        int index = -1;
        int i = 0;
        while ( !has_found && i <= len_str - len_sub ) {
            if ( check_substr(str, i, substr, len_sub) ) {
                has_found = TRUE;
                index = i;
            } else { i++; }
        }
        return index;
    }
}


string replace_first(const string const original, const string const target, const string const replacement)
{
    int index = find(original, target);
    natural len_ori = length(original);
    string new_str;
    if ( index == -1 ) {
        new_str = (string) malloc( (len_ori + 1) * sizeof(char) );
        for (int i = 0; i < len_ori; i++) {
            new_str[i] = original[i];
        }
        new_str[len_ori] = '\0';
    } else {
        natural len_tar = length(target);
        natural len_rep = length(replacement);
        natural len_new = len_ori - len_tar + len_rep + 1;
        new_str = (string) malloc( len_new * sizeof(char) );
        int i = 0;
        while ( i < len_new ) {
            if ( i < index ) {
                new_str[i] = original[i];
            } else if ( index <= i && i < index + len_rep ) {
                new_str[i] = replacement[i - index];
            } else {
                new_str[i] = original[i - len_rep + len_tar];
            }
            i++;
        }
        new_str[len_new] = '\0';
    }
    return new_str;
}