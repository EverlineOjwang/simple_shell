
#include "shell.h"
#include <string.h>

/**
 * our_strdup - duplicates a string
 * @str: string to be duplicated
 * Return: pointer to the duplicated string or NULL on failure
 */
char *our_strdup(const char *str) {
    size_t length = our_strlen(str) + 1;
    char *new_str = (char *)malloc(length);

    if (new_str == NULL) {
        return NULL; // Memory allocation failure
    }

    strcpy(new_str, str);
    return new_str;
}

