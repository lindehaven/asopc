/*
    From "Compilers - Principles, Techniques, and Tools"
    by Alfred V. Aho, Ravi Sethi and Jeffrey D. Ullman.
    Chapter 2 "A Simple One-Pass Compiler".
    Addison-Wesley Publishing Company ISBN 0-201-10194-7.
*/

#include "global.h"

void emit(const int t, const int tval) {
    switch(t) {
        case '+':
        case '-':
        case '*':
        case '/':
            printf("%c\n", t);
            break;
        case DIV:
            printf("DIV\n");
            break;
        case MOD:
            printf("MOD\n");
            break;
        case AND:
            printf("AND\n");
            break;
        case OR:
            printf("OR\n");
            break;
        case XOR:
            printf("XOR\n");
            break;
        case NUM:
            printf("NUM\n");
            break;
        case ID:
            printf("ID\n");
            break;
        default:
            printf("token %d, tokenval %d\n", t, tval);
            break;
    }
}
