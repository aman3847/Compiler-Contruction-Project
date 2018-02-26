// Name: Aman Gupta
// ID: 2014B2A70201P

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lexerDef.h"

#define MAX_BUFFER_SIZE 128

unsigned long long lineNo = 1; // Current Line in the Source File
char buffer1[MAX_BUFFER_SIZE]; // Input Buffer 1
char buffer2[MAX_BUFFER_SIZE]; // Input Buffer 2
int bufferPos1, bufferPos2; // Current character to be read from the buffer
int firstUse = 1; // First Time Use of Bufffers
int bufferSize1, bufferSize2;
int buff1Flag = 1; // Indicates whether to use Buffer 1 or not (Initially set to Yes)
int buff2Flag = 0; // Indicates whether to use Buffer 2 or not (Initially set to No)
int maxLengthCrossed; // Indicates whether lexeme has crossed maximum allowed length or not

tokenInfo* createToken()
{
    tokenInfo* temp = (tokenInfo*)malloc(sizeof(tokenInfo));
    strcpy(temp->lexeme,"");
    temp->tokenID = ERR;
    return temp;
}

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
    else if(id == DOLLAR) return "DOLLAR";
    else if(id == mainFunction) return "mainFunction";
    else if(id == stmtsAndFunctionDefs) return "stmtsAndFunctionDefs";
    else if(id == safdLF) return "safdLF";
    else if(id == stmtOrFunctionDef) return "stmtOrFunctionDef";
    else if(id == stmt) return "stmt";
    else if(id == functionDef) return "functionDef";
    else if(id == parameter_list) return "parameter_list";
    else if(id == type) return "type";
    else if(id == remainingList) return "remainingList";
    else if(id == declarationStmt) return "declarationStmt";
    else if(id == var_list) return "var_list";
    else if(id == more_ids) return "more_ids";
    else if(id == assignmentStmt_type1) return "assignmentStmt_type1";
    else if(id == assignmentStmt_type2) return "assignmentStmt_type2";
    else if(id == leftHandSide_singleVar) return "leftHandSide_singleVar";
    else if(id == leftHandSide_listVar) return "leftHandSide_listVar";
    else if(id == rightHandSide_type1) return "rightHandSide_type1";
    else if(id == rightHandSide_type2) return "rightHandSide_type2";
    else if(id == sizeExpression) return "sizeExpression";
    else if(id == ifStmt) return "ifStmt";
    else if(id == ifStmtLF) return "ifStmtLF";
    else if(id == otherStmts) return "otherStmts";
    else if(id == ioStmt) return "ioStmt";
    else if(id == funCallStmt) return "funCallStmt";
    else if(id == inputParameterList) return "inputParameterList";
    else if(id == listVar) return "listVar";
    else if(id == arithmeticExpression) return "arithmeticExpression";
    else if(id == aeLF) return "aeLF";
    else if(id == arithmeticTerm) return "arithmeticTerm";
    else if(id == atLF) return "atLF";
    else if(id == factor) return "factor";
    else if(id == operator_lowPrecedence) return "operator_lowPrecedence";
    else if(id == operator_highPrecedence) return "operator_highPrecedence";
    else if(id == booleanExpression) return "booleanExpression";
    else if(id == constrainedVars) return "constrainedVars";
    else if(id == var) return "var";
    else if(id == matrix) return "matrix";
    else if(id == rows) return "rows";
    else if(id == rowsLF) return "rowsLF";
    else if(id == row) return "row";
    else if(id == remainingColElements) return "remainingColElements";
    else if(id == matrixElement) return "matrixElement";
    else if(id == logicalOp) return "logicalOp";
    else if(id == relationalOp) return "relationalOp";
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

void copyLexemeToToken(char c, tokenInfo* t, int ind)
{
    t->lexeme[ind] = c;
    t->lexeme[ind+1] = '\0';
    return;
}


char getChar(FILE *fp)
{
    if(firstUse == 1) 
    {
        // First call to getCharacter
        bufferSize1 = fread(buffer1, sizeof(char), (size_t)MAX_BUFFER_SIZE, fp);
        bufferSize2 = fread(buffer2, sizeof(char), (size_t)MAX_BUFFER_SIZE, fp);
        bufferPos1 = 0;
        bufferPos2 = 0;
        firstUse = 0;
    }
    if(bufferSize1 == 0 && bufferSize2 == 0)
        return '$'; // EOF Reached
    if(buff1Flag == 1)
    {
        if(bufferPos1 == bufferSize1)
        {
            bufferSize1 = fread(buffer1, sizeof(char), (size_t)MAX_BUFFER_SIZE, fp);
            buff1Flag = 0;
            buff2Flag = 1;
            bufferPos1 = 0;
            return getChar(fp);
        }
        else
        {
            return buffer1[bufferPos1++];
        }
    }
    if(buff2Flag == 1)
    {
        if(bufferPos2 == bufferSize2)
        {
            bufferSize2 = fread(buffer2, sizeof(char), (size_t)MAX_BUFFER_SIZE, fp);
            buff2Flag = 0;
            buff1Flag = 1;
            bufferPos2 = 0;
            return getChar(fp);
        }
        else
        {
            return buffer2[bufferPos2++];
        }
    }
}

void decrementBuffer()
{
    if(buff1Flag == 1)
        bufferPos1--;
    else
        bufferPos2--;
    return;
}

void printToken(tokenInfo *t)
{
    char tokenID[10];
    char lexeme[21];
    strcpy(lexeme, t->lexeme);
    strcpy(tokenID,tokenRepr(t->tokenID));
    if(strcmp(lexeme, "")!=0 && maxLengthCrossed==0)
        printf("Line %llu: %s %s\n", t->lineNo, lexeme, tokenID);
    return;
}

void removeComments(FILE *fp)
{
    char c;
    int state = 1;
    int newLineFlag = 0;
    printf("Line %llu: ", lineNo);
    while(true)
    {
        c = getChar(fp);
        if(c=='$')
            exit(0);
        if(newLineFlag == 1)
        {
            newLineFlag = 0;
            printf("Line %llu: ", lineNo);
        }
        switch(state)
        {
            case 1:
                switch(c)
                {
                    case '\n':
                        lineNo++;
                        putchar(c);
                        newLineFlag = 1;
                        break;
                    case '#':
                        state = 2;
                        break;
                    default:
                        putchar(c);
                }
                break;

            case 2:
                switch(c)
                {
                    case '\n':
                        lineNo++;
                        putchar(c);
                        state = 1;
                        newLineFlag = 1;
                        break;
                }
                break;
        }
    }
}    

int getKey(char* lexeme)
{
    int key = 0;
    int i;
    for(i=0; i<strlen(lexeme); i++)
        key += lexeme[i];
    key = key%23;
    // printf("lexeme = %s\n", lexeme);
    // printf("key = %d\n", key);
    return key;
}

int keyWords[] = {1,-1,-1,-1,-1,1,1,-1,-1,1,1,1,1,-1,-1,-1,-1,1,-1,1,-1,1,-1};

void checkForKeywords(int key, tokenInfo *t)
{
    if(keyWords[key]==-1)
        return;
    else
    {
        switch(key)
        {
            case 0:
                if(strcmp("if",t->lexeme)==0)
                    t->tokenID = IF;
                break;
            case 5: 
                if(strcmp("print",t->lexeme)==0)
                    t->tokenID = PRINT;
                break;
            case 6:
                if(strcmp("real",t->lexeme)==0)
                    t->tokenID = REAL;
                break;
            case 9:
                if(strcmp("int",t->lexeme)==0)
                    t->tokenID = INT;
                break;
            case 10:
                if(strcmp("_main",t->lexeme)==0)
                    t->tokenID = MAIN;
                break;
            case 11:
                if(strcmp("else",t->lexeme)==0)
                    t->tokenID = ELSE;
                break;
            case 12:
                if(strcmp("end",t->lexeme)==0)
                    t->tokenID = END;
                else if(strcmp("endif",t->lexeme)==0)
                    t->tokenID = ENDIF;
                break;

            case 17:
                if(strcmp("matrix",t->lexeme)==0)
                    t->tokenID = MATRIX;
                break;
            case 19:
                if(strcmp("string",t->lexeme)==0)
                    t->tokenID = STRING;
                else if(strcmp("function",t->lexeme)==0)
                    t->tokenID = FUNCTION;
                break;
            case 21:
                if(strcmp("read",t->lexeme)==0)
                    t->tokenID = READ;
                break;
            default:
                break;
        }
        return;
    }
}

void getNextToken(FILE *fp, tokenInfo *t)
{
    // Reads the file pointed to by fp and fetches the first matching tokenInfo
    char c;
    int state = 1; // Start State
    int lexemeInd = 0;
    maxLengthCrossed = 0;
    int key = -1;
    while(true)
    {
        c = getChar(fp); // Stores the character
        if(c=='$') // EOF
        {
            t->tokenID = DOLLAR;
            return;
        }
        t->lineNo = lineNo; // Updating the line number for the tokenInfo
        // Implementing the DFA using nested Switch Case statments
        switch(state)
        {
            case 1: // Start State
                switch(c)
                {
                    case '\n':
                        lineNo++;
                    case ' ':
                    case '\r':
                    case '\t':
                        state = 1;
                        break;
                    case '=': 
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 2;
                        break;
                    case '#':
                        state = 6;
                        break;
                    case '_':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 8;
                        break;
                    case 'a':
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'e':
                    case 'f':
                    case 'g':
                    case 'h':
                    case 'i':
                    case 'j':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'o':
                    case 'p':
                    case 'q':
                    case 'r':
                    case 's':
                    case 't':
                    case 'u':
                    case 'v':
                    case 'w':
                    case 'x':
                    case 'y':
                    case 'z':
                    case 'A':
                    case 'B':
                    case 'C':
                    case 'D':
                    case 'E':
                    case 'F':
                    case 'G':
                    case 'H':
                    case 'I':
                    case 'J':
                    case 'K':
                    case 'L':
                    case 'M':
                    case 'N':
                    case 'O':
                    case 'P':
                    case 'Q':
                    case 'R':
                    case 'S':
                    case 'T':
                    case 'U':
                    case 'V':
                    case 'W':
                    case 'X':
                    case 'Y':
                    case 'Z':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 10;
                        break;
                    case '"':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 12;
                        break;
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 15;
                        break;
                    case '.':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 19;
                        break;
                    case '[': // SQO Found
                        t->tokenID = SQO;
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        return;
                    case ']': // SQC Found
                        t->tokenID = SQC;
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        return;
                    case '(': // OP Found
                        t->tokenID = OP;
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        return;
                    case ')': // CL Found
                        t->tokenID = CL;
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        return;
                    case ';': // SEMICOLON Found
                        t->tokenID = SEMICOLON;
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        return;
                    case ',': // COMMA Found
                        t->tokenID = COMMA;
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        return;
                    case '+': // PLUS Found
                        t->tokenID = PLUS;
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        return;
                    case '-': // MINUS Found
                        t->tokenID = MINUS;
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        return;
                    case '*': // MUL Found
                        t->tokenID = MUL;
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        return;
                    case '/': // DIV Found
                        t->tokenID = DIV;
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        return;
                    case '@': // SIZE Found
                        t->tokenID = SIZE;
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        return;
                    case '<':
                        state = 42;
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        break;
                    case '>':
                        state = 44;
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        break;
                    default:
                        printf("Line No.: %llu\tLexical Error!! Unknown Symbol <%c>\n", lineNo, c);
                        return;
                }
                break;

            case 2:
                switch(c)
                {
                    case '=': // EQ Found
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        t->lineNo = lineNo;
                        t->tokenID = EQ;
                        return;
                    case '/':
                        state = 4;
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        break;
                    default: // ASSIGNOP Found
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        t->lineNo = lineNo;
                        t->tokenID = ASSIGNOP;
                        return;
                }
                break;

            case 4:
                switch(c)
                {
                    case '=': // NE Found
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        t->lineNo = lineNo;
                        t->tokenID = NE;
                        return;
                    default:
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        printf("Line No.: %llu\t Lexical Error!!\t Unknown Pattern: <%s>\n", lineNo, t->lexeme);
                        return;
                }
                break;

            case 6:
                switch(c)
                {
                    case '\n': // COMMENT Found
                        t->tokenID = COMMENT;
                        t->lineNo = lineNo;
                        lineNo++;
                        state = 1;
                        return;
                    default:
                        break;
                }
                break;

            case 8:
                switch(c)
                {
                    case 'a':
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'e':
                    case 'f':
                    case 'g':
                    case 'h':
                    case 'i':
                    case 'j':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'o':
                    case 'p':
                    case 'q':
                    case 'r':
                    case 's':
                    case 't':
                    case 'u':
                    case 'v':
                    case 'w':
                    case 'x':
                    case 'y':
                    case 'z':
                    case 'A':
                    case 'B':
                    case 'C':
                    case 'D':
                    case 'E':
                    case 'F':
                    case 'G':
                    case 'H':
                    case 'I':
                    case 'J':
                    case 'K':
                    case 'L':
                    case 'M':
                    case 'N':
                    case 'O':
                    case 'P':
                    case 'Q':
                    case 'R':
                    case 'S':
                    case 'T':
                    case 'U':
                    case 'V':
                    case 'W':
                    case 'X':
                    case 'Y':
                    case 'Z':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 9;
                        break;
                    default:
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        printf("Line No.: %llu\t Lexical Error!!\t Unknown Pattern: <%s>\n", lineNo, t->lexeme);
                        return;
                }
                break;

            case 9:
                switch(c)
                {
                    case 'a':
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'e':
                    case 'f':
                    case 'g':
                    case 'h':
                    case 'i':
                    case 'j':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'o':
                    case 'p':
                    case 'q':
                    case 'r':
                    case 's':
                    case 't':
                    case 'u':
                    case 'v':
                    case 'w':
                    case 'x':
                    case 'y':
                    case 'z':
                    case 'A':
                    case 'B':
                    case 'C':
                    case 'D':
                    case 'E':
                    case 'F':
                    case 'G':
                    case 'H':
                    case 'I':
                    case 'J':
                    case 'K':
                    case 'L':
                    case 'M':
                    case 'N':
                    case 'O':
                    case 'P':
                    case 'Q':
                    case 'R':
                    case 'S':
                    case 'T':
                    case 'U':
                    case 'V':
                    case 'W':
                    case 'X':
                    case 'Y':
                    case 'Z':
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        if(maxLengthCrossed==0)
                        {
                            copyLexemeToToken(c, t, lexemeInd);
                            lexemeInd++;
                        }
                        if(maxLengthCrossed==0 && lexemeInd > 20)
                        {
                            maxLengthCrossed = 1;
                            printf("Line %llu: ERROR!! Max Length Crossed\n", lineNo);
                        }
                        state = 9;
                        break;
                    default: // FUNCTION or MAIN Found
                        decrementBuffer(); // // This character is part of next tokenInfo and needs to be read again
                        t->lineNo = lineNo;
                        t->tokenID = FUNCTION;
                        key = getKey(t->lexeme);
                        checkForKeywords(key, t);
                        return;
                }
                break;

            case 10:
                switch(c)
                {
                    case 'a':
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'e':
                    case 'f':
                    case 'g':
                    case 'h':
                    case 'i':
                    case 'j':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'o':
                    case 'p':
                    case 'q':
                    case 'r':
                    case 's':
                    case 't':
                    case 'u':
                    case 'v':
                    case 'w':
                    case 'x':
                    case 'y':
                    case 'z':
                    case 'A':
                    case 'B':
                    case 'C':
                    case 'D':
                    case 'E':
                    case 'F':
                    case 'G':
                    case 'H':
                    case 'I':
                    case 'J':
                    case 'K':
                    case 'L':
                    case 'M':
                    case 'N':
                    case 'O':
                    case 'P':
                    case 'Q':
                    case 'R':
                    case 'S':
                    case 'T':
                    case 'U':
                    case 'V':
                    case 'W':
                    case 'X':
                    case 'Y':
                    case 'Z':
                        if(maxLengthCrossed==0)
                        {
                            copyLexemeToToken(c, t, lexemeInd);
                            lexemeInd++;
                        }
                        if(maxLengthCrossed==0 && lexemeInd > 20)
                        {
                            maxLengthCrossed = 1;
                            printf("Line %llu: ERROR!! Max Length Crossed\n", lineNo);
                        }
                        state = 10;
                        break;
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        // ID Found
                        if(maxLengthCrossed==0)
                        {
                            copyLexemeToToken(c, t, lexemeInd);
                            lexemeInd++;
                        }
                        if(maxLengthCrossed==0 && lexemeInd > 20)
                        {
                            maxLengthCrossed = 1;
                            printf("Line %llu: ERROR!! Max Length Crossed\n", lineNo);
                        }
                        t->lineNo = lineNo;
                        t->tokenID = ID;
                        key = getKey(t->lexeme);
                        checkForKeywords(key, t);

                        return;
                    default:
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        t->lineNo = lineNo;
                        t->tokenID = ID;
                        key = getKey(t->lexeme);
                        checkForKeywords(key, t);
                        return;
                }
                break;

            case 12:
                switch(c)
                {
                    case 'a':
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'e':
                    case 'f':
                    case 'g':
                    case 'h':
                    case 'i':
                    case 'j':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'o':
                    case 'p':
                    case 'q':
                    case 'r':
                    case 's':
                    case 't':
                    case 'u':
                    case 'v':
                    case 'w':
                    case 'x':
                    case 'y':
                    case 'z':
                    case ' ':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 13;
                        break;
                    default:
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        printf("Line No.: %llu\t Lexical Error!!\t Unknown Pattern: <%s>\n", lineNo, t->lexeme);
                        return;
                }
                break;

            case 13:
                switch(c)
                {
                    case 'a':
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'e':
                    case 'f':
                    case 'g':
                    case 'h':
                    case 'i':
                    case 'j':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'o':
                    case 'p':
                    case 'q':
                    case 'r':
                    case 's':
                    case 't':
                    case 'u':
                    case 'v':
                    case 'w':
                    case 'x':
                    case 'y':
                    case 'z':
                    case ' ':
                        if(maxLengthCrossed==0)
                        {
                            copyLexemeToToken(c, t, lexemeInd);
                            lexemeInd++;
                        }
                        if(maxLengthCrossed==0 && lexemeInd > 20)
                        {
                            maxLengthCrossed = 1;
                            printf("Line %llu: ERROR!! Max Length Crossed\n", lineNo);
                        }
                        state = 13;
                        break;
                    case '"':
                        // STR Found
                        if(maxLengthCrossed==0)
                        {
                            copyLexemeToToken(c, t, lexemeInd);
                            lexemeInd++;
                        }
                        if(maxLengthCrossed==0 && lexemeInd > 20)
                        {
                            maxLengthCrossed = 1;
                            printf("Line %llu: ERROR!! Max Length Crossed\n", lineNo);
                        }
                        t->lineNo = lineNo;
                        t->tokenID = STR;
                        return;
                    default:
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        printf("Line No.: %llu\t Lexical Error!!\t Unknown Pattern: <%s%c>\n", lineNo, t->lexeme, c);
                        return;
                }
                break;

            case 15:
                switch(c)
                {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 15;
                        break;
                    case '.':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 16;
                        break;
                    default:
                        // NUM Found
                        decrementBuffer();
                        t->lineNo = lineNo;
                        t->tokenID = NUM;
                        return;
                }
                break;

            case 16:
                switch(c)
                {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 17;
                        break;
                    case 'a':
                    case 'n':
                    case 'o':
                        // The tokenInfo found before this was NUM;
                        decrementBuffer();
                        decrementBuffer();
                        t->lexeme[lexemeInd-1] = '\0';
                        state = 1;
                        t->lineNo = lineNo;
                        t->tokenID = NUM;
                        return;
                    default:
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        printf("Line No.: %llu\t Lexical Error!!\t Unknown Pattern: <%s>\n", lineNo, t->lexeme);
                        return;
                }
                break;

            case 17:
                switch(c)
                {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        // RNUM Found
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        t->lineNo = lineNo;
                        t->tokenID = RNUM;
                        return;
                    default:
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        printf("Line No.: %llu\t Lexical Error!!\t Unknown Pattern: <%s>\n", lineNo, t->lexeme);
                        return;
                }
                break;

            case 19:
                switch(c)
                {
                    case 'a':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 20;
                        break;
                    case 'o':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 24;
                        break;
                    case 'n':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 27;
                        break;
                    default:
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        printf("Line No.: %llu\t Lexical Error!!\t Unknown Pattern: <%s>\n", lineNo, t->lexeme);
                        return;
                }
                break;

            case 20:
                switch(c)
                {
                    case 'n':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 21;
                        break;
                    default:
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        printf("Line No.: %llu\t Lexical Error!!\t Unknown Pattern: <%s>\n", lineNo, t->lexeme);
                        return;
                }
                break;

            case 21:
                switch(c)
                {
                    case 'd':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 22;
                        break;
                    default:
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        printf("Line No.: %llu\t Lexical Error!!\t Unknown Pattern: <%s>\n", lineNo, t->lexeme);
                        return;
                }
                break;

            case 22:
                switch(c)
                {
                    case '.':
                        // AND Found
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        t->lineNo = lineNo;
                        t->tokenID = AND;
                        return;
                    default:
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        printf("Line No.: %llu\t Lexical Error!!\t Unknown Pattern: <%s>\n", lineNo, t->lexeme);
                        return;
                }
                break;

            case 24:
                switch(c)
                {
                    case 'r':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 25;
                        break;
                    default:
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        printf("Line No.: %llu\t Lexical Error!!\t Unknown Pattern: <%s>\n", lineNo, t->lexeme);
                        return;
                }
                break;

            case 25:
                switch(c)
                {
                    case '.':
                        // OR Found
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        t->lineNo = lineNo;
                        t->tokenID = OR;
                        return;
                    default:
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        printf("Line No.: %llu\t Lexical Error!!\t Unknown Pattern: <%s>\n", lineNo, t->lexeme);
                        return;
                }
                break;

            case 27:
                switch(c)
                {
                    case 'o':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 28;
                        break;
                    default:
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        printf("Line No.: %llu\t Lexical Error!!\t Unknown Pattern: <%s>\n", lineNo, t->lexeme);
                        return;
                }
                break;

            case 28:
                switch(c)
                {
                    case 't':
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        state = 29;
                        break;
                    default:
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        printf("Line No.: %llu\t Lexical Error!!\t Unknown Pattern: <%s>\n", lineNo, t->lexeme);
                        return;
                }
                break;

            case 29:
                switch(c)
                {
                    case '.':
                        // NOT Found
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        t->lineNo = lineNo;
                        t->tokenID = NOT;
                        return;
                    default:
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        printf("Line No.: %llu\t Lexical Error!!\t Unknown Pattern: <%s>\n", lineNo, t->lexeme);
                        return;
                }
                break;

            case 42:
                switch(c)
                {
                    case '=':
                        // LE Found
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        t->lexeme[lexemeInd] = '\0';
                        t->lineNo = lineNo;
                        t->tokenID = LE;
                        return;
                    default:
                        // LT Found
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        t->lineNo = lineNo;
                        t->tokenID = LT;
                        return;
                }
                break;

            case 44:
                switch(c)
                {
                    case '=':
                        // GE Found
                        copyLexemeToToken(c, t, lexemeInd);
                        lexemeInd++;
                        t->lineNo = lineNo;
                        t->tokenID = GE;
                        return;
                    default:
                        // LT Found
                        decrementBuffer(); // This character is part of next tokenInfo and needs to be read again
                        t->lineNo = lineNo;
                        t->tokenID = GT;
                        return;
                }
                break;

            case 45:
                switch(c)
                {
                    case 'a':
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'e':
                    case 'f':
                    case 'g':
                    case 'h':
                    case 'i':
                    case 'j':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'o':
                    case 'p':
                    case 'q':
                    case 'r':
                    case 's':
                    case 't':
                    case 'u':
                    case 'v':
                    case 'w':
                    case 'x':
                    case 'y':
                    case 'z':
                    case 'A':
                    case 'B':
                    case 'C':
                    case 'D':
                    case 'E':
                    case 'F':
                    case 'G':
                    case 'H':
                    case 'I':
                    case 'J':
                    case 'K':
                    case 'L':
                    case 'M':
                    case 'N':
                    case 'O':
                    case 'P':
                    case 'Q':
                    case 'R':
                    case 'S':
                    case 'T':
                    case 'U':
                    case 'V':
                    case 'W':
                    case 'X':
                    case 'Y':
                    case 'Z':
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        continue;
                    default:
                        decrementBuffer();
                        state = 1;
                }
        }
    }
}