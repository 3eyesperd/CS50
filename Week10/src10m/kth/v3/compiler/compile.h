/****************************************************************************
 * compile.h
 *
 * Rob Bowden
 * rob@cs.harvard.edu
 *
 * Declares the functions defined in compile.c
 ***************************************************************************/

#ifndef COMPILE_H
#define COMPILE_H

#include <sys/types.h>

void compile(char* buffer, int argc, char* argv[]);
size_t get_size_of_file(char* filename);

#endif
