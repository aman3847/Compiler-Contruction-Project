// Name: Aman Gupta
// ID: 2014B2A70201P

#include <string.h>
#include <stdio.h>
#include "lexerDef.h"

char* tokenRepr(int id) 
{
    // Returns the Printable Representation of a tokenID
    if(id == ASSIGNOP) return "ASSIGNOP";
    else if(id == COMMENT) return "COMMENT";
    else if(id == FUNID) return "FUNID";
    else if(id == ID) return "ID";
    else if(id == NUM) return "NUM";
    else if(id == RNUM) return "RNUM";
    else if(id == STR) return "STR";
    else if(id == END) return "END";
    else if(id == INT) return "INT";
    else if(id == REAL) return "REAL";
    else if(id == STRING) return "STRING";
    else if(id == MATRIX) return "MATRIX";
    else if(id == MAIN) return "MAIN";
    else if(id == SQO) return "SQO";
    else if(id == SQC) return "SQC";
    else if(id == OP) return "OP";
    else if(id == CL) return "CL";
    else if(id == SEMICOLON) return "SEMICOLON";
    else if(id == COMMA) return "COMMA";
    else if(id == IF) return "IF";
    else if(id == ELSE) return "ELSE";
    else if(id == ENDIF) return "ENDIF";
    else if(id == READ) return "READ";
    else if(id == PRINT) return "PRINT";
    else if(id == FUNCTION) return "FUNCTION";
    else if(id == PLUS) return "PLUS";
    else if(id == MINUS) return "MINUS";
    else if(id == MUL) return "MUL";
    else if(id == DIV) return "DIV";
    else if(id == SIZE) return "SIZE";
    else if(id == AND) return "AND";
    else if(id == OR) return "OR";
    else if(id == NOT) return "NOT";
    else if(id == LT) return "LT";
    else if(id == LE) return "LE";
    else if(id == EQ) return "EQ";
    else if(id == GT) return "GT";
    else if(id == GE) return "GE";
    else if(id == NE) return "NE";
    else if(id == EPSILON) return "EPSILON";
    else if(id == ERR) return "ERR";
}

int checkForMaxLength(tokenInfo *t, int ind, long long int lineNo)
{
    if(ind > 20)
    {
        printf("Line No.: %llu\tLexical ERROR!! Identifier is longer than the prescribed length (20)\n", lineNo);
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