#include <stdio.h>
#include <stdlib.h>

size_t our_strlen(const char *str);

ssize_t our_getline(char **line, size_t *len, FILE *stream) {
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t bytesRead;

    if (*line == NULL || *len == 0) {
        bufsize = 1024;
        buffer = (char *)malloc(bufsize);
        if (buffer == NULL) {
            perror("malloc");
            return -1;
        }
        *line = buffer;
        *len = bufsize;
    } else {
        buffer = *line;
        bufsize = *len;
    }

    bytesRead = getline(&buffer, &bufsize, stream);

    if (bytesRead != -1) {
        if (bytesRead > 0 && buffer[bytesRead - 1] == '\n') {
            buffer[bytesRead - 1] = '\0';
            bytesRead--;
        }
    } else {
        free(buffer); // Free the buffer in case of error
        *line = NULL;
        *len = 0;
    }

    return bytesRead;
}

