#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *our_strcat(const char *str1, const char *str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char *result = (char *)malloc(len1 + len2 + 1);  // +1 for the null terminator

    if (result == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

int main() {
    const char *str1 = "Hello, ";
    const char *str2 = "world!";
    char *concatenated = our_strcat(str1, str2);

    printf("Concatenated string: %s\n", concatenated);

    free(concatenated);  // Don't forget to free the dynamically allocated memory

    return 0;
}

