// Name: Aman Gupta
// ID: 2014B2A70201P

#ifndef PARSER
#define PARSER

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>
#include "parserDef.h"

int stringToEnum(char* id);
char* enumToString(int id);
lexeme* getLexeme(char* id);

void readGrammar(char *filename);
void createFirstAndFollow(char *filename);
void printGrammar();
void printFirstAndFollow();

void createParseTable();
void initializeParseTable();
void printParseTable();

stackNode* createStackNode(int id);
stack* initializeStack();
bool isEmpty(stack* stack);
void push(stack* stack, stackNode* node);
int pop(stack* stack);
int top(stack* stack);
void reverseStack(stack* mainStack, stack* auxStack);
void printStack(stack* stack);
void testStackFunctionalities();

tree* createTreeNode(tokenInfo* token);
void insertTreeNode(tree* root, tree* node);
void visit(tree* node, FILE* fp2);
void testNAryTreeFunctionalities();

void parseInputSourceCode(FILE* fp);
void createParseTree(FILE* fp, FILE* fp2);
void copyDetails(tree* root, tokenInfo* token);
void printParseTree(FILE* fp2);

#endif