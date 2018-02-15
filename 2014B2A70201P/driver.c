// Name: Aman Gupta
// ID: 2014B2A70201P

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

int main()
{
    FILE *fp = fopen("test.txt","r");
    tokenInfo* newToken = (tokenInfo*)malloc(sizeof(tokenInfo));
    while(true)
    {
        strcpy(newToken->lexeme,"");
        newToken->tokenID = ERR;
        getNextToken(fp,newToken);
        printToken(newToken);
    }
    return 0;
}