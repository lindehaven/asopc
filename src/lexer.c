/*
    From "Compilers - Principles, Techniques, and Tools"
    by Alfred V. Aho, Ravi Sethi and Jeffrey D. Ullman.
    Chapter 2 "A Simple One-Pass Compiler".
    Addison-Wesley Publishing Company ISBN 0-201-10194-7.
*/

#include "global.h"
#include "error.h"
#include "symbol.h"

int lineno = 1;
int tokenval = NONE;

static char lexbuf[BSIZE];

int lexan(void) {
    int t;
    while(1) {
        t = getchar();
        if (t == ' ' || t == '\t') {
            ;
        } else if (t == '\n') {
            lineno = lineno + 1;
        } else if (isdigit(t)) {
            ungetc(t, stdin);
            scanf("%d", &tokenval);
            return NUM;
        } else if (isalpha(t)) {
            int p, b = 0;
            while (isalnum(t)) {
                lexbuf[b] = t;
                t = getchar();
                b = b + 1;
                if (b >= BSIZE) {
                    error("compiler error");
                }
            }
            lexbuf[b] = EOS;
            if (t != EOF) {
                ungetc(t, stdin);
            }
            p = lookup(lexbuf);
            if (p == 0) {
                p = insert(lexbuf, ID);
            }
            tokenval = p;
            return token(p);
        } else if (t == EOF) {
            return DONE;
        } else {
            tokenval = NONE;
            return t;
        }
    }
}
