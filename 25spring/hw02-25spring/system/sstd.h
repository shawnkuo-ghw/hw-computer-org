/*
* A simple library offering operations to write to a file in a similar way as a very simplified printf and fprintf;
* an a function to execute an executable with a set of arguments.
*/

#ifndef SSTD_H
#define SSTD_H

/*
* Error code when either s_printf or s_printf_to_file are called with a NULL format value.
*/
#define ERROR_FORMAT_NULL 1

/*
* Error code when either s_printf or s_printf_to_file are called with a format holding at least one
* placeholder (%d), and the values argument is NULL.
*/
#define ERROR_VALUES_NULL 2

/*
* Error code when any s_execute, or s_printf_to_file function is called with a file that doesn't exist
*/
#define ERROR_SYSTEM_NO_FILE 3

/*
* Error code when any s_execute, or s_printf_to_file function is called with a file that doesn't have execution permissions.
*/
#define ERROR_SYSTEM_NO_ACCESS 4

/*
* Error code when any s_execute function is called with a NULL file.
*/
#define ERROR_SYSTEM_NULL_FILE 5

/*
* Error code when any s_execute function failed to execute the executable given by path_to_executable.
*/
#define ERROR_SYSTEM_EXECUTION_FAILED 6

/*
* Error code when the executable executed by any s_execute function did not terminate by either a call to exit or by returning from
* it's main function. 
*/
#define ERROR_SYSTEM_CHILD_INVALID_EXIT 7

/*
* An alias for char *, to be used when one wants to treat a pointer to a char as a string.
*/
typedef char * string;
/*
* An alias for unsigned char, to be used when one wants to use boolean values.
*/
typedef unsigned char boolean;

#define TRUE 1
#define FALSE 0

/*
* prints to a specific file.
* This function takes a file descriptor identifying the file to write to
* a formatted string containing one or more `%d` strings;
* and an array of integer values that must be the same length as there are `%d` in the string.
* This function will return how many bytes it wrote.
*/
int s_printf_to_file(int fd, const string const format, const int * const values);

/*
* prints to standard output.
* This function takes a formatted string containing one or more `%d` strings;
* and an array of integer values that must be the same length as there are `%d` in the string.
* This function will return how many bytes it wrote.
*/
int s_printf(const string const format, const int * const values);

/*
* This function takes a path to an executable, and a NULL-terminated array of strings to be used
* as arguments for the executable.
* This function will wait until the called executable finishes and return their exit code 
*/
int s_execute(const string const path_to_executable, const string * const args);

/*
* This function takes a path to an executable, a NULL-terminated array of strings to be used
* as arguments for the executable, and a boolean value that determines whether the caller of this function
* will wait for the called executable or not.
*/
extern int s_execute_optional_wait(const string const path_to_executable, const string * const args, const boolean _wait);

/*
* Defines the file redirection when executing an executable
*/
typedef enum {
    /*
    * No redirection
    */
    NONE,
    /*
    * Standard output is redirected to a file
    */
    REDIRECT_OUT,
    /*
    * A file is redirected to standard input
    */
    REDIRECT_IN
} redirect;

/*
* Executes an executable with potential file redirection and may wait on the executable to finish.
*
* Arguments:
* path_to_executable : a path to an executable;
* args :  a NULL-terminated array of strings to be used as arguments for the executable;
* redirect_op : a redirect value that determines if-and-which redirection will be used (*);
* redirect_file : a path to a file used alongside the redirection operator (**);
* _wait : a boolean that determines whether this function will wait until the executable finished or not.
*
* (*) : See `redirect` documentation for more information.
* (**) : ignored if `redirect_op` is `NONE`
*
* Returns the exit code of the executable, or 0 if `_wait` is `False`.
*/
extern int s_execute_with_redirection(const string const path_to_executable, const string * const args, const redirect redirect_op, const string redirect_file, const boolean _wait);

#endif
