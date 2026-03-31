#include "sstd.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static boolean placeholder_found(const string const cursor);
static string int_to_string(const int value);
static unsigned int length(const string string);

int s_printf_to_file(int fd, const string const format, const int * const values) {
    //TODO: implement
}

int s_printf(const string const format, const int * const values) {
    //TODO: implement
}

static unsigned int length(const string string) {
    int count = 0;
    while(string[count] != 0) {
        count++;
    }
    return count;
}

static boolean placeholder_found(const string const cursor) {
    if (cursor == NULL) {
        return FALSE;
    } else if (*cursor == '%') {
        if (*(cursor+1) == 0) {
            return FALSE;
        } else if (*(cursor+1) == 'd') {
            return TRUE;
        }
    }
    return FALSE;
}

#define ZERO_CHAR 48

static string int_to_string(const int value) {
    int current_value = value;
    //An int is 4 bytes, so it can go from -2,147,483,648 to 2,147,483,647
    //so considering the lowest negative value, we would need a string of size 11
    //but we need an extra char to put the zero at the end of the returned string.
    const int max_size = 11;
    char * representation = (char *) malloc(max_size + 1);
    representation[max_size] = 0;
    int current_digit_position = max_size;
    boolean is_negative = FALSE;
    if (current_value < 0) {
        current_value = current_value * -1; //potential bug
        is_negative = TRUE;
    }
    do {
        int digit = current_value % 10;
        int rest = current_value / 10;
        current_value = rest;
        current_digit_position--;
        char digit_as_char = digit + ZERO_CHAR;
        representation[current_digit_position] = digit_as_char;
    } while (current_value > 0);
    if (is_negative) {
        current_digit_position--;
        representation[current_digit_position] = '-';
    }
    return representation + current_digit_position;
}