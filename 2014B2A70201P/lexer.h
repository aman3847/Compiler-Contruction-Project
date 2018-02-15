// Name: Aman Gupta
// ID: 2014B2A70201P

#ifndef LEXER
#define LEXER

#include <stdio.h>
#include <stdlib.h>
#include "lexerDef.h"

char getChar(FILE *fp);
void printToken(tokenInfo *t);
void getNextToken(FILE *fp, tokenInfo *t);
void decrementBuffer();

#endif