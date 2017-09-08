/*
    From "Compilers - Principles, Techniques, and Tools"
    by Alfred V. Aho, Ravi Sethi and Jeffrey D. Ullman.
    Chapter 2 "A Simple One-Pass Compiler".
    Addison-Wesley Publishing Company ISBN 0-201-10194-7.
*/

#include "global.h"
#include "symbol.h"

struct entry keywords[] = {
    {"div",     DIV},
    {"DIV",     DIV},
    {"mod",     MOD},
    {"MOD",     MOD},
    {"and",     AND},
    {"AND",     AND},
    {"or",      OR},
    {"OR",      OR},
    {"xor",     XOR},
    {"XOR",     XOR},
    {0,         0}
};

void init(void) {
    struct entry *p;
    for (p = keywords; p->token; p++) {
        insert(p->lexptr, p->token);
    }
}
