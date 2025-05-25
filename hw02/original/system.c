#include "sstd.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

static boolean file_exists(const string const filename);
static boolean file_is_executable(const string const filename);
static boolean file_is_readable(const string const filename);
static boolean file_is_writeable(const string const filename);
static int string_array_size(const string * const array);

int s_execute(const string const path_to_executable, const string * const args) {
    // TODO: Complete implementation ensuring the following requirements:
    // 1. A child process must use execve to execute the path_to_executable
    // 2. The arguments (args) for execve must with conventions (start with
    //    the executable to be executed and end with a NULL value).
    // 3. You can use variable environ as the last argument for execve
    // 4. The parent process must wait for the child and return the child's exit code as
    //    result.
}

int s_execute_optional_wait(const string const path_to_executable, const string * const args, const boolean _wait) {
    //TODO: implement, the behaviour will change with respect with s_execute on waiting for the child or not
}

int s_execute_with_redirection(const string const path_to_executable, const string * const args, const redirect redirect_op, const string redirect_file, const boolean _wait) {
    //TODO: implement, the behaviour will change with respect with s_execute_optional_wait on redirecting input or output of the child process.
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
    while (array[i] != NULL) {
        i++;
    }
    return i;
}
