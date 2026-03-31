#include "sstd.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

extern char **environ;
static boolean file_exists(const string const filename);
static boolean file_is_executable(const string const filename);
static boolean file_is_readable(const string const filename);
static boolean file_is_writeable(const string const filename);
static     int string_array_size(const string * const array);

int s_execute(const string const path_to_executable, const string * const args) {
    // 1. A child process must use execve to execute the path_to_executable
    // 2. The arguments (args) for execve must comply with conventions (start with
    //    the executable to be executed and end with a NULL value).
    // 3. You can use variable environ as the last argument for execve
    // 4. The parent process must wait for the child and return the child's exit code as
    //    result.
    return s_execute_with_redirection(path_to_executable, args, NONE, NULL, TRUE);
}

int s_execute_optional_wait(const string const path_to_executable, const string * const args, const boolean _wait) {
    return s_execute_with_redirection(path_to_executable, args, NONE, NULL, _wait);
}

int s_execute_with_redirection(const string const path_to_executable, const string * const args, const redirect redirect_op, const string redirect_file, const boolean _wait) {
    
    
    // preconditions check
    if ( path_to_executable == NULL )              { return -ERROR_SYSTEM_NULL_FILE; }
    if ( !file_exists(path_to_executable) )        { return -ERROR_SYSTEM_NO_FILE; }
    if ( !file_is_readable(path_to_executable) )   { return -ERROR_SYSTEM_NO_ACCESS; }
    if ( !file_is_executable(path_to_executable) ) { return -ERROR_SYSTEM_NO_ACCESS; }
    
    
    // initialize arguments of execve
    int args_size = string_array_size(args);
    string * execve_args = (string *) malloc((args_size + 2) * sizeof(string *));
    execve_args[0] = path_to_executable;
    execve_args[args_size + 1] = NULL;
    for ( int i = 0; i < args_size; i++ ) {
        execve_args[i + 1] = args[i];
    }
    
    // program
    pid_t pid = fork();
    if ( pid < 0 ) {

        return pid;
    
    } else if ( pid == 0 ) {
        
        // child process
        if ( redirect_op == REDIRECT_IN ) {

            // A file is redirected to standard input
            if ( !file_exists(redirect_file) )      { return -ERROR_SYSTEM_NO_FILE; }
            if ( !file_is_readable(redirect_file) ) { return -ERROR_SYSTEM_NO_ACCESS; }
           
            int fdin = open(redirect_file, O_RDONLY);
            if ( fdin < 0 ) { return -ERROR_SYSTEM_EXECUTION_FAILED; }
            if ( dup2(fdin, STDIN_FILENO) < 0 ) {
                close(fdin);
                return -ERROR_SYSTEM_EXECUTION_FAILED; 
            }
            close(fdin);
            int result = execve(path_to_executable, execve_args, environ);
        
        } else if ( redirect_op == REDIRECT_OUT ) {

            // Standard output is redirected to a file
            if ( !file_exists(redirect_file) )       { return -ERROR_SYSTEM_NO_FILE; }
            if ( !file_is_writeable(redirect_file) ) { return -ERROR_SYSTEM_NO_ACCESS; }
            
            int fdout = open(redirect_file, O_WRONLY | O_TRUNC);
            if ( fdout < 0 ) { return -ERROR_SYSTEM_EXECUTION_FAILED; }
            if ( dup2(fdout, STDOUT_FILENO) < 0 ) { 
                close(fdout);
                return -ERROR_SYSTEM_EXECUTION_FAILED; 
            }
            close(fdout);
            int result = execve(path_to_executable, execve_args, environ);
        
        } else {

            printf("%s", path_to_executable);
            int result = execve(path_to_executable, execve_args, environ);
        }
        return -ERROR_SYSTEM_EXECUTION_FAILED;
    
    } else {
        
        // parent process
        if ( _wait ) {
            int status;
            waitpid(pid, &status, 0);
            if ( WIFEXITED(status) ) {
                return WEXITSTATUS(status);
            } else if ( WIFSIGNALED(status) ) {
                return WTERMSIG(status);
            } else {
                return -ERROR_SYSTEM_CHILD_INVALID_EXIT;
            }
        } else {
            return 0;
        }
    }
}

static boolean file_exists(const string const filename) {
    return access(filename, F_OK) == 0;
}

static boolean file_is_executable(const string const filename) {
    return access(filename, X_OK) == 0;
}

static boolean file_is_readable(const string const filename) {
    return access(filename, R_OK) == 0;
}

static boolean file_is_writeable(const string const filename) {
    return access(filename, W_OK) == 0;
}

static int string_array_size(const string * const array) {
    if (array == NULL) {
        return 0;
    }
    int i = 0;
    while (array[i] != '\0') {
        i++;
    }
    return i;
}
