/****************************************************************************
 * compile.c
 *
 * Rob Bowden
 * rob@cs.harvard.edu
 *
 * Some hackish functions for compiling an in-memory buffer
 ***************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "compile.h"

/**
 * pass an in-memory buffer to clang for compilation
 *
 * argv[2] through argv[argc - 1] are the flags passed to clang
 *
 */
void compile(char *buffer, int argc, char* argv[])
{
    // this function constructs a call to "clang" that
    // will compile our in-memory buffer

    // first, we calculate the length of the compilation command
    // we'll be running

    // the length of our buffer
    int length = strlen(buffer);

    // plus the length of all the arguments (and spaces)
    for (int i = 2; i < argc; i++)
        length += strlen(argv[i]) + 1;

    // plus the length of the commands we're going to be running
    // to pass this buffer to clang, plus the null terminator
    length += strlen("echo '' | clang -xc -") + 1;

    // because we are running "echo" with single quotes, we need
    // to escape any single quotes inside of our buffer.
    // but it takes 4 characters to escape a single quote, so
    // cautiously allocatee 4 times as much space as we might need
    char new_buffer[length * 4];

    // zero out the new_buffer
    for (int i = 0; i < length; i++)
        new_buffer[i] = 0;

    // our command starts out with an "echo '"
    strcat(new_buffer, "echo \'");

    int new_len = strlen(new_buffer);

    // now, iterate over our buffer, inserting each character into
    // our new_buffer, except for the ' character, which is replaced
    // with the 4-character sequence '\''
    for (int i = 0, len = strlen(buffer); i < len; i++) {
        if (buffer[i] == '\'') {
            new_buffer[new_len++] = '\'';
            new_buffer[new_len++] = '\\';
            new_buffer[new_len++] = '\'';
            new_buffer[new_len++] = '\'';
        }
        else
            new_buffer[new_len++] = buffer[i];
    }

    // pipe our new_buffer into clang
    strcat(new_buffer, "\' | clang -xc -");

    // append all of the command line arguments to our command
    for (int i = 2; i < argc; i++) {
        strcat(new_buffer, " ");
        strcat(new_buffer, argv[i]);
    }

    // run our command
    system(new_buffer);
}

/**
 * returns the size of a file, given the file's name
 *
 */
size_t get_size_of_file(char* filename)
{
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}
