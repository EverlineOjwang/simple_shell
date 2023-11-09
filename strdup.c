
#include "shell.h"
#include <string.h>

/**
 * strdup - duplicates a string
 * @str: string to be duplicated
 * Return: pointer to the duplicated string or NULL on failure
 */
char *strdup(const char *str) {
    size_t length = strlen(str) + 1;
    char *new_str = (char *)malloc(length);

    if (new_str == NULL) {
        return NULL;
    }

    strcpy(new_str, str);
    return new_str;
}

