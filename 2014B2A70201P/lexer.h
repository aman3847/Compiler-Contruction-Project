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
void removeComments(FILE *fp);
char* tokenRepr(int id);
int checkForMaxLength(tokenInfo *t, int ind, long long int lineNo);
// void checkForKeywords(tokenInfo *t);
void copyLexemeToToken(char c, tokenInfo* t, int ind);
tokenInfo* createToken();

#endif