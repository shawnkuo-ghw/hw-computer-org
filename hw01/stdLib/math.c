#include "standard.h"


int max(const int a, const int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int maximum(const int size, int values[size]) {
    // DONE done by ghw
    if ( size == 0 ) {
        return MIN_VALUE;
    }
    int max_value = values[0];
    for ( int i = 0; i < size; i++ ) {
        max_value = max(max_value, values[i]);
    }
    return max_value;
}

boolean is_even(const int value) {
    if (value & 1) {
        return FALSE;
    } else {
        return TRUE;
    }
}

boolean is_odd(const int value) {
    if (value & 1) {
        return TRUE;
    } else {
        return FALSE;
    }
}

boolean is_prime(const unsigned int value) {
    // DONE by ghw
    boolean isPrime = TRUE;
    if ( value < 2 ) {
        isPrime = FALSE;
    } else {
        unsigned int factor = 2;
        while ( isPrime && factor < value ) {
            if ( value % factor == 0 ) {
                isPrime = FALSE;
            } else {
                factor ++;
            }
        }
    }
    return isPrime;
}

unsigned int fibonnaci(const unsigned int nth) {
    // DONE by ghw
    unsigned int nth_fibo;
    if (nth == 1 || nth == 2 ) {
        nth_fibo = 1;
    } else {
        int dp[nth];
        dp[0] = 1;
        dp[1] = 1;
        for ( int i = 2; i < nth; i++ ) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        nth_fibo = dp[nth-1];
    }
    return nth_fibo;
}