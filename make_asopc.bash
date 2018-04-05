#!/usr/bin/env bash
OPT='-O2 -Wall -s -o'
BIN='bin/Release/asopc.exe'
SRC='src/emitter.h src/error.h src/global.h src/init.h src/lexer.h src/parser.h src/symbol.h
     src/emitter.c src/error.c src/global.h src/init.c src/lexer.c src/parser.c src/symbol.c src/main.c'
mkdir -p bin
mkdir -p bin/Release
echo "gcc $OPT $BIN $SRC"
      gcc $OPT $BIN $SRC
