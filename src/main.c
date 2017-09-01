/*
    From "Compilers - Principles, Techniques, and Tools"
    by Alfred V. Aho, Ravi Sethi and Jeffrey D. Ullman.
    Chapter 2 "A Simple One-Pass Compiler".
    Addison-Wesley Publishing Company ISBN 0-201-10194-7.
*/

#include <stdlib.h>
#include "init.h"
#include "parser.h"

int main(void)
{
    init();
    parse();
    exit(0);
}
