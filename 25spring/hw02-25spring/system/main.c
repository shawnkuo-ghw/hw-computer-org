/*
* A simple program to show custom implementation of printf-like functions, and to emulate bash execution of an executable.
* The usage of this program is:
*
* ./system --print <string> <int values>
*   This will take a string containing a number N, which can be zero, of placeholders %d, e.g.: "My favorite number is %d\n".
*   and a space separated list of integer values which size should match N, e.g.: 42.
*   It will then call function s_printf with the format string and the integer values
*
* ./system --print-to-file <file> <string> <int values>
*   Same as with --print, but the first argument will be a file to which to print, and instead of calling s_printf
*   this will call s_printf_to_file.
*
* ./system --execute <executable> <arguments>
*   This will execute the <executable>, which should be the full path to a program (e.g.: /usr/bin/ls)
*   with the list of space-separated arguments.
*
* ./system --execute-nw <executable> <arguments>
*   This will execute the <executable>, which should be the full path to a program (e.g.: /usr/bin/ls)
*   with the list of space-separated arguments. Process system will not wait for the executable to finish.
*
* ./system --execute-stdinr <file> <executable> <arguments>
*   This will execute the <executable>, which should be the full path to a program (e.g.: /usr/bin/ls)
*   with the list of space-separated arguments. It will redirect the STANDARD INPUT to file for the executable,
*   but not for the system process.
*
* ./system --execute-stdoutr <file> <executable> <arguments>
*   This will execute the <executable>, which should be the full path to a program (e.g.: /usr/bin/ls)
*   with the list of space-separated arguments. It will redirect the STANDARD OUTPUT to file for the executable,
*   but not for the system process.
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "sstd.h"

#define PRINT                   "--print"
#define PRINT_F                 "--print-to-file"
#define EXECUTE                 "--execute"
#define EXECUTE_NO_WAIT         "--execute-nw"
#define EXECUTE_REDIRECT_STDIN  "--execute-stdinr"
#define EXECUTE_REDIRECT_STDOUT "--execute-stdoutr"

int main(int argc, char * argv[]) {
    
    int result;

    if ( strcmp(argv[1], PRINT) == 0 && argc == 4 ) {
        // ./system --print <string> <int values>
        result = s_printf( argv[2], argv[3] );

    } else if ( strcmp(argv[1], PRINT_F) == 0 && argc == 5 ) {
        // ./system --print-to-file <file> <string> <int values> 
        int fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH );
        result = s_printf_to_file( fd, argv[3], argv[4] );

    } else if ( strcmp(argv[1], EXECUTE) == 0 && argc == 4 ) {
        // ./system --execute <executable> <arguments>
        result = s_execute(argv[2], argv[3]);
   
    } else if ( strcmp(argv[1], EXECUTE_NO_WAIT) == 0 && argc == 4 ) {
        // ./system --execute-nw <executable> <arguments>
        
        result = s_execute_optional_wait(argv[2], argv[3], FALSE);
    
    } else if ( strcmp(argv[1], EXECUTE_REDIRECT_STDIN) == 0 && argc == 5 ) {
        // ./system --execute-stdinr <file> <executable> <arguments>
        result = s_execute_with_redirection(argv[3], argv[4], REDIRECT_IN, argv[2], TRUE);
    
    } else if ( strcmp(argv[1], EXECUTE_REDIRECT_STDOUT) == 0 && argc == 5 ) {
        // ./system --execute-stdoutr <file> <executable> <arguments>
        result = s_execute_with_redirection(argv[3], argv[4], REDIRECT_OUT, argv[2], TRUE);
    
    } else {
    
        return EXIT_FAILURE; 
    
    }
    return result;
}
