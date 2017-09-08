/*
    From "Compilers - Principles, Techniques, and Tools"
    by Alfred V. Aho, Ravi Sethi and Jeffrey D. Ullman.
    Chapter 2 "A Simple One-Pass Compiler".
    Addison-Wesley Publishing Company ISBN 0-201-10194-7.
*/

#include "global.h"
#include "lexer.h"
#include "emitter.h"
#include "error.h"

static int lookahead;

static void expr(void);
static void term(void);
static void factor(void);
static void match(const int);

void parse(void) {
    lookahead = lexan();
    while (lookahead != DONE) {
        expr();
        match(';');
    }
}

static void expr(void) {
    int t;
    term();
    while (1) {
        switch (lookahead) {
            case '+':
            case '-':
                t = lookahead;
                match(lookahead);
                term();
                emit(t, NONE);
                continue;
            default:
                return;
        }
    }
}

static void term(void) {
    int t;
    factor();
    while(1) {
        switch (lookahead) {
            case '*':
            case '/':
            case DIV:
            case MOD:
            case AND:
            case OR:
            case XOR:
                t = lookahead;
                match(lookahead);
                factor();
                emit(t, NONE);
                continue;
            default:
                return;
        }
    }
}

static void factor(void) {
    switch (lookahead) {
        case '(':
            match('(');
            expr();
            match(')');
            break;
        case NUM:
            emit(NUM, tokenval);
            match(NUM);
            break;
        case ID:
            emit(ID, tokenval);
            match(ID);
            break;
        default:
            error("syntax error");
    }
}

static void match(const int t) {
    if (lookahead == t) {
        lookahead = lexan();
    } else {
        error("syntax error");
    }
}

