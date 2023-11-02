#include "shell.h"
#include <signal.h>
#include <unistd.h>

/**
 * signal_handler - handles the Ctrl+C signal (SIGINT)
 * @signal: signal number (unused)
 */
void signal_handler(int signal) {
    (void)signal; // Suppress unused parameter warning

    write(STDOUT_FILENO, "\n$ ", 3);
}

