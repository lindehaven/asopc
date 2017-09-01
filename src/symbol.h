/*
    From "Compilers - Principles, Techniques, and Tools"
    by Alfred V. Aho, Ravi Sethi and Jeffrey D. Ullman.
    Chapter 2 "A Simple One-Pass Compiler".
    Addison-Wesley Publishing Company ISBN 0-201-10194-7.
*/

#ifndef SYMBOL_H_INCLUDED
#define SYMBOL_H_INCLUDED

extern struct entry symtable[];
extern int lookup(const char []);
extern int insert(const char [], const int);
extern int token(const int p);

#endif // SYMBOL_H_INCLUDED
