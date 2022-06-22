#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

int main(int argc, char **argv)
{
    (void) argc;

    assert(argv != NULL);
    char *program = *argv++;

    if (*argv == NULL) {
        fprintf(stderr, "ERROR: usage of %s is invalid \n", program);
        fprintf(stderr, "ERROR: must have a file path specified \n");
        exit(1);
    }

    char *file_path = *argv++;
    char *text = *argv;

    FILE *file = fopen(file_path, "a");

    if (file == NULL) {
        fprintf(stderr, "ERROR: %s could not be opened and exited with the error: %d \n", file_path, errno);
        exit(errno);
    }
    
    fputs(text, file);

    int close_value = fclose(file);
    
    if (close_value != 0) {
        fprintf(stderr, "ERROR: could not close %s and exited with %d error code", file_path, errno);
        exit(errno);
    }

    return 0;
}