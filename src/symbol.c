/*
    From "Compilers - Principles, Techniques, and Tools"
    by Alfred V. Aho, Ravi Sethi and Jeffrey D. Ullman.
    Chapter 2 "A Simple One-Pass Compiler".
    Addison-Wesley Publishing Company ISBN 0-201-10194-7.
*/

#include <string.h>
#include "global.h"
#include "error.h"

#define SYMMAX  100
#define STRMAX  999

static char lexemes[STRMAX];
static int lastchar = -1;
static struct entry symtable[SYMMAX];
static int lastentry = 0;

int lookup(const char s[]) {
    int p;
    for (p = lastentry; p > 0; p = p - 1) {
        if (strcmp(symtable[p].lexptr, s) == 0) {
            return p;
        }
    }
    return 0;
}

int insert(const char s[], const int tok) {
    int len;
    len = strlen(s);
    if (lastentry + 1 >= SYMMAX) {
        error("symbol table full");
    }
    if (lastchar + len + 1 >= STRMAX) {
        error("lexemes array full");
    }
    lastentry = lastentry + 1;
    symtable[lastentry].token = tok;
    symtable[lastentry].lexptr = &lexemes[lastchar+1];
    lastchar = lastchar + len + 1;
    strcpy(symtable[lastentry].lexptr, s);
    return lastentry;
}

int token(const int p) {
    if (p >= 0 && p < SYMMAX) {
        return symtable[p].token;
    } else {
        return NONE;
    }
}
