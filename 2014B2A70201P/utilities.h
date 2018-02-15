// Name: Aman Gupta
// ID: 2014B2A70201P

#ifndef UTILITIES
#define UTILITIES

#include "lexerDef.h"

char* tokenRepr(int id);
int checkForMaxLength(tokenInfo *t, int ind, int lineNo);
void checkForKeywords(tokenInfo *t);
void copyLexemeToToken(char c, tokenInfo* t, int ind);

#endif