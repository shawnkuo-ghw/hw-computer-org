/**
 * @file   standard.h
 * @date   03-31-2026
 * @brief  This header file contains the prototypes of all the functions
 *         related to math, string and boolean, the declarations of some
 *         variable types and 
 */

#ifndef STANDARD_DEF
#define STANDARD_DEF
#include <limits.h> //You can get min and max values for int from here

/*
    An alias to `unsigned char` to better represent a `boolean`
*/
typedef unsigned char boolean;

/*
    An alias to `unsigned int` to better represent a `natural`
*/
typedef unsigned int natural;

/*
    An alias to `char *` to better represent a `string`
*/
typedef char * string;

/*
    A `boolean` constant representing a `True` value
*/
#define TRUE 1

/*
    A `boolean` constant representing a `False` value
*/
#define FALSE 0

/* ============================== Math ====================================== */

#define MIN_VALUE INT_MIN /* INT_MIN is the minimal value for int */

/*
    Returns the minimum of two values
    Takes two integer values, `a` and `b`
    Returns `a` if `a <= b`, otherwise it will return `b`
*/
extern int min(const int a, const int b);

/*
    Returns the minimum value in an array
    Takes an integer `size` and an `array` of that size
    Returns `e`, where `e` is in `array` and there is no other value `f` in `array` such that `f < e`;
    if `array` is empty, it will return `MIN_VALUE`.
*/
extern int minimum(const int size, int values[size]);

/*
    Returns whether a number is even or not
    Takes one integer `value`
    Returns `TRUE` iff `value` is even.
*/
extern boolean is_even(const int value);

/*
    Returns whether a number is odd or not
    Takes one integer `value`
    Returns `TRUE` iff `value` is odd.
*/
extern boolean is_odd(const int value);

/*
    Returns whether a number is prime or not
    Takes one integer `value`
    Returns `TRUE` iff `value` is prime (`value` is only divisible by `1` and `value`).
*/
extern boolean is_prime(const natural value);

/*
    Returns fibonacci of x defined as:
    fibonacci(0) == 0
    fibonacci(1) == 1
    fibonacci(n) == fibonacci(n - 1) + fibonacci(n - 2)
*/
extern natural fibonacci(const natural nth);

/* ================================= String ================================= */

/*
    Returns the length of a `NULL-Terminated` string
    Takes a pointer to the first character of a string, the string must be `NULL-Terminated`
*/
extern natural length(const string const str);

/*
    Returns whether two `NULL-Terminated` strings are equal or not
    Takes two strings `string1` and `string2`
    Returns `True` iff both strings are of the same length and
    for every `i in [0..length(string1)] | string1[i] == string2[i]`
*/
extern boolean equals(const string const str1, const string const str2);

/*
    Returns the first index where a character appears in a string.
    Takes a `NULL-Terminated` string `string` and a character to look for `e`
    Returns `i` such that `string[i] == e` and there is no `j < i` where `string[j] == e`,
    returns `-1` if the character does not appear in the string
*/
extern int index_of(const string const str, const char e);

/*
    Returns the last index where a character appears in a string.
    Takes a `NULL-Terminated` string `string` and a character to look for `e`
    Returns `i` such that `string[i] == e` and there is no `j > i` where `string[j] == e`,
    returns `-1` if the character does not appear in the string
*/
extern int last_index_of(const string const str, const char e);

/*
    Returns a modified version of a string where every uppercase letter has been transformed into lowercase.
    Takes a `NULL-Terminated` string `string`
    Returns a new `NULL-terminated` string `string2` equal to `string` except for every uppercase letter
    in `string` will be in lowercase in `string2`
*/
extern string to_lower_case(const string const str);

/*
    Returns a modified version of a string where every lowercase letter has been transformed into uppercase.
    Takes a `NULL-Terminated` string `string`
    Returns a new `NULL-terminated` string `string2` equal to `string` except for every lowercase letter
    in `string` will be in uppercase in `string2`
*/
extern string to_upper_case(const string const str);

/*
    Returns whether a string starts with a prefix or not
    Takes two `NULL-Terminated` strings `string` and `prefix`
    Returns `TRUE` iff for every `i` in `[0..length(prefix))`, `string[i] == prefix[i]`
*/
extern boolean starts_with(const string const str, const string const prefix);

/*
    Returns the index of the first occurrence of a non-empty substring in another string.
    Takes two `NULL-Terminated` strings `string` and `target`
    Returns `i` such that for every `j` in `[0..length(target))`, `string[i + j] == target[j]` and there is no `k < i` such that for every `j` in `[0..length(target))`, `string[k + j] == target[j]`,
    returns `-1` if there is no occurrence of `target` in `string`
*/
extern int find(const string const str, const string const target);

/*
    Returns a modified version of a string where the first occurrence of a non-empty substring is replaced by another substring.
    Takes an `original` string, a `target` string to look for, and a `replacement` string.
    Returns a new `NULL-Terminated` string where the first occurrence of `target` in `original` is replaced by `replacement`.
    If there is no occurrence of `target` in `original`, it will just return a copy of `original`.
    All strings are `NULL-Terminated`.
*/
extern string replace_first(const string const original, const string const target, const string const replacement);

/* ================================ Boolean ================================= */

/*
    Returns the logical and between two boolean values
    Takes two `boolean` values `a` and `b`
    Returns `a && b`
*/
extern boolean and(const boolean a, const boolean b);

/*
    Returns the logical not of a boolean value
    Takes one `boolean` value `a`
    Returns `! a`
*/
extern boolean not(const boolean a);

/*
    Returns the logical or between two boolean values
    Takes two `boolean` values `a` and `b`
    Returns `a || b`
*/
extern boolean or(const boolean a, const boolean b);

/*
    Returns the logical xor between two boolean values
    Takes two `boolean` values `a` and `b`
    Returns `a ^ b`
*/
extern boolean xor(const boolean a, const boolean b);

/*
    Returns the logical implies between two boolean values
    Takes two `boolean` values `a` and `b`
    Returns `!a || b`
 */
extern boolean implies(const boolean a, const boolean b);

/*
    Defines a boolean expression that can be evaluated into a single `boolean` value
*/
struct expression;

/*
    Creates an `expression` representing a single boolean value.
    Takes a `boolean` value (`value`)
    Returns a pointer to a new `expression` representing a boolean value from `value`
*/
extern struct expression* BOOLEAN_VALUE(boolean value);

/*
    Creates an `expression` representing a negation of another `expression`.
    Takes a pointer to an `expression` `e`
    Returns a pointer to a new `expression` representing a negation of `e`
*/
extern struct expression* NOT(struct expression* e);

/*
    Creates an `expression` representing a conjunction of two other `expression`s.
    Takes two pointers to `expression`s `left` and `right`
    Returns a pointer to a new `expression` representing a conjunction of `left` and `right`
*/
extern struct expression* AND(struct expression* left, struct expression* right);

/*
    Creates an `expression` representing a disjunction of two other `expression`s.
    Takes two pointers to `expression`s `left` and `right`
    Returns a pointer to a new `expression` representing a disjunction of `left` and `right`
*/
extern struct expression* OR(struct expression* left, struct expression* right);

/*
    Creates an `expression` representing an implication of two other `expression`s.
    Takes two pointers to `expression`s `left` and `right`
    Returns a pointer to a new `expression` representing an implication from `left` to `right`
*/
extern struct expression* IMPLIES(struct expression* left, struct expression* right);

/*
    Evaluates an `expression` into a `boolean` value
    Takes a pointer to an `expression` `expr`
    Evaluates `expr` into a `boolean` value
*/
extern boolean eval(struct expression* expr);

/*
    Cleans (free) an `expression` value
    Takes a pointer to an `expression` `expr`
    Frees all the memory taken by `expr`
*/
extern void drop(struct expression* expr);

/*
    An `expression` constant representing a `True` expression
*/
#define V BOOLEAN_VALUE(TRUE)

/*
    An `expression` constant representing a `False` expression
*/
#define F BOOLEAN_VALUE(FALSE)

#endif // STANDARD_DEF