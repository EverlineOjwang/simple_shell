#include "shell.h"

/**
 * our_strcmp - compares two strings lexicographically
 * @string1: first string to compare
 * @string2: second string to compare
 *
 * Return: an integer less than, equal to, or greater than zero if string1 is
 * found, respectively, to be less than, to match, or be greater than string2
 */
int our_strcmp(const char *string1, const char *string2) {
    while (*string1 && *string2 && *string1 == *string2) {
        string1++;
        string2++;
    }

    return (int)((unsigned char)*string1 - (unsigned char)*string2);
}

