// Name: Aman Gupta
// ID: 2014B2A70201P

#include <string.h>
#include <stdio.h>
#include "lexerDef.h"

char* tokenRepr(int id) 
{
    // Returns the Printable Representation of a tokenID
    if(id == ASSIGNOP) return "ASSIGNOP";
    if(id == COMMENT) return "COMMENT";
    if(id == FUNID) return "FUNID";
    if(id == ID) return "ID";
    if(id == NUM) return "NUM";
    if(id == RNUM) return "RNUM";
    if(id == STR) return "STR";
    if(id == END) return "END";
    if(id == INT) return "INT";
    if(id == REAL) return "REAL";
    if(id == STRING) return "STRING";
    if(id == MATRIX) return "MATRIX";
    if(id == MAIN) return "MAIN";
    if(id == SQO) return "SQO";
    if(id == SQC) return "SQC";
    if(id == OP) return "OP";
    if(id == CL) return "CL";
    if(id == SEMICOLON) return "SEMICOLON";
    if(id == COMMA) return "COMMA";
    if(id == IF) return "IF";
    if(id == ELSE) return "ELSE";
    if(id == ENDIF) return "ENDIF";
    if(id == READ) return "READ";
    if(id == PRINT) return "PRINT";
    if(id == FUNCTION) return "FUNCTION";
    if(id == PLUS) return "PLUS";
    if(id == MINUS) return "MINUS";
    if(id == MUL) return "MUL";
    if(id == DIV) return "DIV";
    if(id == SIZE) return "SIZE";
    if(id == AND) return "AND";
    if(id == OR) return "OR";
    if(id == NOT) return "NOT";
    if(id == LT) return "LT";
    if(id == LE) return "LE";
    if(id == EQ) return "EQ";
    if(id == GT) return "GT";
    if(id == GE) return "GE";
    if(id == NE) return "NE";
    if(id == ERR) return "ERR";
}

int checkForMaxLength(tokenInfo *t, int ind, int lineNo)
{
    if(ind > 20)
    {
        printf("ERROR!! Length cannot be more than 20\t");
        t->lineNo = lineNo;
        t->tokenID = ERR;
        return 1;
    }
    else
        return 0;
}

void checkForKeywords(tokenInfo *t)
{
    if(strcmp(t->lexeme,"_main")==0)
    {
        t->tokenID = MAIN;
        return;
    }
    else
    {
        if(strcmp(t->lexeme,"end")==0)
        {
            t->tokenID = END;
            return;
        }
        else if(strcmp(t->lexeme,"int")==0)
        {
            t->tokenID = INT;
            return;
        }
        else if(strcmp(t->lexeme,"real")==0)
        {
            t->tokenID = REAL;
            return;
        }
        else if(strcmp(t->lexeme,"string")==0)
        {
            t->tokenID = STRING;
            return;
        }
        else if(strcmp(t->lexeme,"matrix")==0)
        {
            t->tokenID = MATRIX;
            return;
        }
        else if(strcmp(t->lexeme,"if")==0)
        {
            t->tokenID = IF;
            return;
        }
        else if(strcmp(t->lexeme,"else")==0)
        {
            t->tokenID = ELSE;
            return;
        }
        else if(strcmp(t->lexeme,"endif")==0)
        {
            t->tokenID = ENDIF;
            return;
        }
        else if(strcmp(t->lexeme,"read")==0)
        {
            t->tokenID = READ;
            return;
        }
        else if(strcmp(t->lexeme,"print")==0)
        {
            t->tokenID = PRINT;
            return;
        }
        else if(strcmp(t->lexeme,"function")==0)
        {
            t->tokenID = FUNCTION;
            return;
        }
        else
            return;
    }
}

void copyLexemeToToken(char c, tokenInfo* t, int ind)
{
    t->lexeme[ind] = c;
    t->lexeme[ind+1] = '\0';
    return;
}