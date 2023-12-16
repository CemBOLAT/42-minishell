# minishell

## <a href="https://excalidraw.com/#json=u6tkV6c4viSZazqRWEZfL,nReavsFn2OkurYtsbWOB6A" >MindMap</a> that works counterwise way.

## Program Details
- **Program Name:** minishell
- **Turn-in Files:** Makefile, *.h, *.c

## External Functions
# External Functions

# External Functions

| #  | Function             | Description                                                  | Library Link                                               |
|---|----------------------|--------------------------------------------------------------|------------------------------------------------------------|
| 1 | `readline`           | Reads a line from the user.                                   | [Readline Library](https://tiswww.case.edu/php/chet/readline/rltop.html) |
| 2 | `rl_clear_history`   | Clears the entire history.                                    | [Readline Library](https://tiswww.case.edu/php/chet/readline/rltop.html) |
| 3 | `rl_on_new_line`     | Prepares to call readline() again.                            | [Readline Library](https://tiswww.case.edu/php/chet/readline/rltop.html) |
| 4 | `rl_replace_line`    | Replaces the contents of the line buffer with a new string.  | [Readline Library](https://tiswww.case.edu/php/chet/readline/rltop.html) |
| 6 | `add_history`        | Adds a line to the command history.                           | [Readline Library](https://tiswww.case.edu/php/chet/readline/rltop.html) |
| 7 | `printf`             | Prints formatted output to the standard output (stdout).    | [C Standard Library](https://en.cppreference.com/w/c/io/printf) |
| 8 | `malloc`             | Allocates a block of memory of specified size.              | [C Standard Library](https://en.cppreference.com/w/c/memory/malloc) |
| 9 | `free`               | Deallocates the memory previously allocated by `malloc`.   | [C Standard Library](https://en.cppreference.com/w/c/memory/free) |
|10 | `write`              | Writes data to the specified file descriptor.               | [C Standard Library](https://en.cppreference.com/w/c/io/write) |
|11 | `access`             | Tests accessibility of a file.                               | [C Standard Library](https://en.cppreference.com/w/c/io/access) |
|12 | `open`               | Opens a file or device.                                      | [C Standard Library](https://en.cppreference.com/w/c/io/open) |
|13 | `read`               | Reads data from a file descriptor.                           | [C Standard Library](https://en.cppreference.com/w/c/io/read) |
|14 | `close`              | Closes a file descriptor.                                    | [C Standard Library](https://en.cppreference.com/w/c/io/close) |
|15 | `fork`               | Creates a new process by duplicating the calling process.   | [C Standard Library](https://en.cppreference.com/w/c/process/fork) |
|16 | `wait`               | Waits for the child process to terminate.                   | [C Standard Library](https://en.cppreference.com/w/c/process/wait) |
|17 | `waitpid`            | Waits for a specific child process to terminate.            | [C Standard Library](https://en.cppreference.com/w/c/process/waitpid) |
|18 | `wait3`              | Waits for child processes and provides status information.  | [C Standard Library](https://en.cppreference.com/w/c/process/wait) |
|19 | `wait4`              | Waits for a specific child process and provides status information. | [C Standard Library](https://en.cppreference.com/w/c/process/waitpid) |
|20 | `signal`             | Sets a function to handle a signal.                         | [C Standard Library](https://en.cppreference.com/w/c/signal/signal) |
|25 | `exit`               | Terminates the calling process.                              | [C Standard Library](https://en.cppreference.com/w/c/process/exit) |
|26 | `getcwd`             | Gets the current working directory.                         | [C Standard Library](https://en.cppreference.com/w/c/io/getcwd) |
|27 | `chdir`              | Changes the current working directory.                      | [C Standard Library](https://en.cppreference.com/w/c/io/chdir) |
|28 | `stat`               | Gets file status.                                           | [C Standard Library](https://en.cppreference.com/w/c/io/stat) |
|32 | `execve`             | Executes a program.                                         | [C Standard Library](https://en.cppreference.com/w/c/process/exec) |
|33 | `dup`                | Duplicates a file descriptor.                               | [C Standard Library](https://en.cppreference.com/w/c/io/dup) |
|34 | `dup2`               | Duplicates a file descriptor and allows choosing a specific file descriptor number. | [C Standard Library](https://en.cppreference.com/w/c/io/dup2) |
|35 | `pipe`               | Creates a pipe.                                            | [C Standard Library](https://en.cppreference.com/w/c/io/pipe) |
|39 | `strerror`           | Returns a pointer to the textual representation of the current errno value. | [C Standard Library](https://en.cppreference.com/w/c/string/strerror) |
|40 | `getenv`             | Gets the value of the environment variable.                 | [C Standard Library](https://en.cppreference.com/w/c/program/getenv) |

## Description
Write a shell that should:
- Display a prompt when waiting for a new command.
- Have a working history.
- Search and launch the right executable (based on the PATH variable or using a relative or an absolute path).
- Avoid using more than one global variable to indicate a received signal. Be careful, this global variable cannot provide any other information or data access than the number of a received signal.
- Not interpret unclosed quotes or special characters which are not required by the subject such as \ (backslash) or ; (semicolon).
- Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
- Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).
- Implement redirections:
  - < should redirect input.
  - > should redirect output.
  - << should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
  - >> should redirect output in append mode.
- Implement pipes (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
- Handle environment variables ($ followed by a sequence of characters) which should expand to their values.
- Handle $? which should expand to the exit status of the most recently executed foreground pipeline.
- Handle ctrl-C, ctrl-D, and ctrl-\ which should behave like in bash.
- In interactive mode:
  - ctrl-C displays a new prompt on a new line.
  - ctrl-D exits the shell.
  - ctrl-\ does nothing.
- Implement the following builtins:
  - echo with option -n
  - cd with only a relative or absolute path
  - pwd with no options
  - export with no options
  - unset with no options
  - env with no options or arguments
  - exit with no options

**Note:** The readline() function can cause memory leaks. You don’t have to fix them. But that doesn’t mean your own code, yes the code you wrote, can have memory leaks. You should limit yourself to the subject description. Anything that is not asked is not required. If you have any doubt about a requirement, take bash as a reference.
