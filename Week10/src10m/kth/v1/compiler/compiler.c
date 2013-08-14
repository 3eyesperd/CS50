/****************************************************************************
 * compiler.c
 *
 * Rob Bowden
 * rob@cs.harvard.edu
 *
 * Compiles a C program
 *
 * If that C program happens to be "login", insert some code into it so we
 * can hack it.
 *
 * If that C program happens to be "compiler", insert some code into it
 * that handles the insertion of code into the "login" program.
 ***************************************************************************/

#include <stdio.h>
#include <string.h>
#include "compile.h"

int main(int argc, char* argv[])
{

    // check for proper usage
    if (argc < 2) {
        printf("Must specify a file to compile.\n");
        return 1;
    }

    // for our purposes, the "main" file that we might want to modify is
    // always the first argument
    char* file = argv[1];

    // read the entire file into a buffer
    int filesize = get_size_of_file(file);
    FILE* f = fopen(file, "r");
    char buffer[filesize + 1];
    fread(buffer, filesize, 1, f);

    // null-terminate the buffer
    buffer[filesize] = 0;

    // compile the file
    compile(buffer, argc, argv);
    return 0;
}
