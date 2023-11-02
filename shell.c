#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGUMENTS 100

void executeCommand(char *args[]) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        wait(NULL);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARGUMENTS];
    
    while (1) {
        printf("$ ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        
        // Tokenize input
        size_t argCount = 0;
        char *token = strtok(input, " \n\t\r\a");
        while (token != NULL) {
            args[argCount++] = token;
            token = strtok(NULL, " \n\t\r\a");
        }
        args[argCount] = NULL;
        
        if (argCount > 0) {
            // Handle built-in commands
            if (strcmp(args[0], "exit") == 0) {
                break;
            } else if (strcmp(args[0], "env") == 0) {
                char **env = environ;
                while (*env) {
                    printf("%s\n", *env);
                    env++;
                }
            } else {
                // Execute other commands
                executeCommand(args);
            }
        }
    }
    
    printf("Shell exited.\n");
    return 0;
}


