// Name: Aman Gupta
// ID: 2014B2A70201P

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef LEXER
#include "lexer.h"
#endif

int main(int argc, char* argv[])
// int main()
{
    FILE* fp = fopen(argv[1],"r");
    // FILE* fp = fopen("temp.txt","r");
    int opt;
    // int opt = 2;
    printf("Select one of the options mentioned below:\n");
    printf("1. Remove Comments\n");
    printf("2. Print Tokens\n");
    scanf("%d",&opt);
    if(opt==1)
        removeComments(fp);
    else if(opt==2)
    {
        tokenInfo* newToken = (tokenInfo*)malloc(sizeof(tokenInfo));
        while(true)
        {
            strcpy(newToken->lexeme,"");
            newToken->tokenID = ERR;
            getNextToken(fp,newToken);
            if(newToken->tokenID!=ERR)
                printToken(newToken);
        }
    }
    else
        printf("Wrong Option Entered. TERMINATING!!\n");
    fclose(fp);
    return 0;
}
