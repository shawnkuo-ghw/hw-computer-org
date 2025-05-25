#include "sstd.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static boolean placeholder_found(const char * const cursor);
static string int_to_string(const int value);
static unsigned int length(const string string);

int s_printf_to_file(int fd, const string const format, const int * const values) {
    if (format == NULL) {
        return ERROR_FORMAT_NULL;
    }
    char * format_cursor = format;
    const int * values_cursor = values;
    int bytes_written = 0;
    if (format == NULL) {
        return -ERROR_FORMAT_NULL;
    }
    while (*format_cursor != 0) {
        if (placeholder_found(format_cursor)) {
            if (values == NULL) {
                return -ERROR_VALUES_NULL;
            }
            char * value_to_print = int_to_string(*values_cursor);
            int values_length = length(value_to_print);
            write(fd, value_to_print, values_length);
            bytes_written = bytes_written + values_length;
            format_cursor = format_cursor + 2;
            values_cursor = values_cursor + 1;
        } else {
            write(fd, format_cursor, 1);
            format_cursor = format_cursor + 1;
            bytes_written = bytes_written + 1;
        }
    }
    return bytes_written;
}

int s_printf(const string const format, const int * const values) {
    return s_printf_to_file(STDOUT_FILENO, format, values);
}

static unsigned int length(const string string) {
    int count = 0;
    while(string[count] != 0) {
        count++;
    }
    return count;
}

static boolean placeholder_found(const char * const cursor) {
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