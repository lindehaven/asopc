/*
    From "Compilers - Principles, Techniques, and Tools"
    by Alfred V. Aho, Ravi Sethi and Jeffrey D. Ullman.
    Chapter 2 "A Simple One-Pass Compiler".
    Addison-Wesley Publishing Company ISBN 0-201-10194-7.
*/

#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

void error(const char *m) {
    fprintf(stderr, "line %d: %s\n", lineno, m);
    exit(1);
}
