#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

/*
    From "Compilers - Principles, Techniques, and Tools"
    by Alfred V. Aho, Ravi Sethi and Jeffrey D. Ullman.
    Chapter 2 "A Simple One-Pass Compiler".
    Addison-Wesley Publishing Company ISBN 0-201-10194-7.
*/

#include <stdio.h>
#include <ctype.h>

#define BSIZE   128
#define NONE    -1
#define EOS     '\0'

#define NUM     256
#define DIV     257
#define MOD     258
#define ID      259
#define DONE    260

struct entry {
    char *lexptr;
    int  token;
};

#endif // GLOBAL_H_INCLUDED
