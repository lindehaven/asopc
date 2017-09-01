/*
    From "Compilers - Principles, Techniques, and Tools"
    by Alfred V. Aho, Ravi Sethi and Jeffrey D. Ullman.
    Chapter 2 "A Simple One-Pass Compiler".
    Addison-Wesley Publishing Company ISBN 0-201-10194-7.
*/

#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED

extern int lineno;
extern int tokenval;
extern int lexan(void);

#endif // LEXER_H_INCLUDED
