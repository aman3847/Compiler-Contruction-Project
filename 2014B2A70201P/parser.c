// Name: Aman Gupta
// ID: 2014B2A70201P

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_OF_RULES 86
#define NO_OF_TERMINALS 38
#define NO_OF_NON_TERMINALS 44

typedef enum
{
    ASSIGNOP,   // 0
    FUNID,      // 1
    ID,         // 2
    NUM,        // 3
    RNUM,       // 4
    STR,        // 5
    END,        // 6
    INT,        // 7
    REAL,       // 8
    STRING,     // 9
    MATRIX,     // 10
    MAIN,       // 11
    SQO,        // 12
    SQC,        // 13
    OP,         // 14
    CL,         // 15
    SEMICOLON,  // 16
    COMMA,      // 17
    IF,         // 18
    ELSE,       // 19
    ENDIF,      // 20
    READ,       // 21
    PRINT,      // 22
    FUNCTION,   // 23
    PLUS,       // 24
    MINUS,      // 25
    MUL,        // 26
    DIV,        // 27
    SIZE,       // 28
    AND,        // 29
    OR,         // 30
    NOT,        // 31
    LT,         // 32
    LE,         // 33
    EQ,         // 34
    GT,         // 35
    GE,         // 36
    NE,         // 37
    ENDOFFILE   // 38
} terminal;

typedef enum
{
    mainFunction,
	stmtsAndFunctionDefs,
	safdLF,
	stmtOrFunctionDef,
	stmt,
	functionDef,
	parameter_list,
	type,
	remainingList,
	declarationStmt,
	var_list,
	more_ids,
	assignmentStmt_type1,
	assignmentStmt_type2,
	leftHandSide_singleVar,
	leftHandSide_listVar,
	rightHandSide_type1,
	rightHandSide_type2,
	sizeExpression,
	ifStmt,
	ifStmtLF,
	otherStmts,
	ioStmt,
	funCallStmt,
	inputParameterList,
	listVar,
	arithmeticExpression,
	aeLF,
	arithmeticTerm,
	atLF,
	factor,
	operator_lowPrecedence,
	operator_highPrecedence,
	booleanExpression,
	constrainedVars,
	var,
	matrix,
	rows,
	rowsLF,
	row,
	remainingColElements,
	matrixElement,
	logicalOp,
	relationalOp
} nonTerminal;

terminal reprTerminal(char *t) 
{
    if(strcmp("ASSIGNOP",t)==0)
    	return ASSIGNOP;
    else if(strcmp("FUNID",t)==0)
    	return FUNID;
    else if(strcmp("ID",t)==0)
    	return ID;
    else if(strcmp("NUM",t)==0)
    	return NUM;
    else if(strcmp("RNUM",t)==0)
    	return RNUM;
    else if(strcmp("STR",t)==0)
    	return STR;
    else if(strcmp("END",t)==0)
    	return END;
    else if(strcmp("INT",t)==0)
    	return INT;
    else if(strcmp("REAL",t)==0)
    	return REAL;
    else if(strcmp("STRING",t)==0)
    	return STRING;
    else if(strcmp("MATRIX",t)==0)
    	return MATRIX;
    else if(strcmp("MAIN",t)==0)
    	return MAIN;
    else if(strcmp("SQO",t)==0)
    	return SQO;
    else if(strcmp("SQC",t)==0)
    	return SQC;
    else if(strcmp("OP",t)==0)
    	return OP;
    else if(strcmp("CL",t)==0)
    	return CL;
    else if(strcmp("SEMICOLON",t)==0)
    	return SEMICOLON;
    else if(strcmp("COMMA",t)==0)
    	return COMMA;
    else if(strcmp("IF",t)==0)
    	return IF;
    else if(strcmp("ELSE",t)==0)
    	return ELSE;
    else if(strcmp("ENDIF",t)==0)
    	return ENDIF;
    else if(strcmp("READ",t)==0)
    	return READ;
    else if(strcmp("PRINT",t)==0)
    	return PRINT;
    else if(strcmp("FUNCTION",t)==0)
    	return FUNCTION;
    else if(strcmp("PLUS",t)==0)
    	return PLUS;
    else if(strcmp("MINUS",t)==0)
    	return MINUS;
    else if(strcmp("MUL",t)==0)
    	return MUL;
    else if(strcmp("DIV",t)==0)
    	return DIV;
    else if(strcmp("SIZE",t)==0)
    	return SIZE;
    else if(strcmp("AND",t)==0)
    	return AND;
    else if(strcmp("OR",t)==0)
    	return OR;
    else if(strcmp("NOT",t)==0)
    	return NOT;
    else if(strcmp("LT",t)==0)
    	return LT;
    else if(strcmp("LE",t)==0)
    	return LE;
    else if(strcmp("EQ",t)==0)
    	return EQ;
    else if(strcmp("GT",t)==0)
    	return GT;
    else if(strcmp("GE",t)==0)
    	return GE;
    else if(strcmp("NE",t)==0)
    	return NE;
    else
    	return -1;
}

nonTerminal reprNonTerminal(char* nt)
{
	if(strcmp("mainFunction",nt)==0)
		return mainFunction;
	else if(strcmp("stmtsAndFunctionDefs",nt)==0)
		return stmtsAndFunctionDefs;
	else if(strcmp("safdLF",nt)==0)
		return safdLF;
	else if(strcmp("stmtOrFunctionDef",nt)==0)
		return stmtOrFunctionDef;
	else if(strcmp("stmt",nt)==0)
		return stmt;
	else if(strcmp("functionDef",nt)==0)
		return functionDef;
	else if(strcmp("parameter_list",nt)==0)
		return parameter_list;
	else if(strcmp("type",nt)==0)
		return type;
	else if(strcmp("remainingList",nt)==0)
		return remainingList;
	else if(strcmp("declarationStmt",nt)==0)
		return declarationStmt;
	else if(strcmp("var_list",nt)==0)
		return var_list;
	else if(strcmp("more_ids",nt)==0)
		return more_ids;
	else if(strcmp("assignmentStmt_type1",nt)==0)
		return assignmentStmt_type1;
	else if(strcmp("assignmentStmt_type2",nt)==0)
		return assignmentStmt_type2;
	else if(strcmp("leftHandSide_singleVar",nt)==0)
		return leftHandSide_singleVar;
	else if(strcmp("leftHandSide_listVar",nt)==0)
		return leftHandSide_listVar;
	else if(strcmp("rightHandSide_type1",nt)==0)
		return rightHandSide_type1;
	else if(strcmp("rightHandSide_type2",nt)==0)
		return rightHandSide_type2;
	else if(strcmp("sizeExpression",nt)==0)
		return sizeExpression;
	else if(strcmp("ifStmt",nt)==0)
		return ifStmt;
	else if(strcmp("ifStmtLF",nt)==0)
		return ifStmtLF;
	else if(strcmp("otherStmts",nt)==0)
		return otherStmts;
	else if(strcmp("ioStmt",nt)==0)
		return ioStmt;
	else if(strcmp("funCallStmt",nt)==0)
		return funCallStmt;
	else if(strcmp("inputParameterList",nt)==0)
		return inputParameterList;
	else if(strcmp("listVar",nt)==0)
		return listVar;
	else if(strcmp("arithmeticExpression",nt)==0)
		return arithmeticExpression;
	else if(strcmp("aeLF",nt)==0)
		return aeLF;
	else if(strcmp("arithmeticTerm",nt)==0)
		return arithmeticTerm;
	else if(strcmp("atLF",nt)==0)
		return atLF;
	else if(strcmp("factor",nt)==0)
		return factor;
	else if(strcmp("operator_lowPrecedence",nt)==0)
		return operator_lowPrecedence;
	else if(strcmp("operator_highPrecedence",nt)==0)
		return operator_highPrecedence;
	else if(strcmp("booleanExpression",nt)==0)
		return booleanExpression;
	else if(strcmp("constrainedVars",nt)==0)
		return constrainedVars;
	else if(strcmp("var",nt)==0)
		return var;
	else if(strcmp("matrix",nt)==0)
		return matrix;
	else if(strcmp("rows",nt)==0)
		return rows;
	else if(strcmp("rowsLF",nt)==0)
		return rowsLF;
	else if(strcmp("row",nt)==0)
		return rows;
	else if(strcmp("remainingColElements",nt)==0)
		return remainingColElements;
	else if(strcmp("matrixElement",nt)==0)
		return matrixElement;
	else if(strcmp("logicalOp",nt)==0)
		return logicalOp;
	else if(strcmp("relationalOp",nt)==0)
		return relationalOp;
}
// Structure to store Terminal/Non-Terminal
typedef struct lexeme
{
	char id[30];
	struct lexeme *next;

}lexeme;

// Structure to store pointer to LHS of a Rule
typedef struct rule
{
	lexeme *head;
}rule;

rule grammar[NO_OF_RULES]; // Array of Pointers to LHS of a Rule
rule firstAndFollow[NO_OF_RULES];
rule* parseTable[NO_OF_NON_TERMINALS][NO_OF_TERMINALS+1];

lexeme* getLexeme(char* id)
{
	lexeme *node = (lexeme*)malloc(sizeof(lexeme));
	strcpy(node->id, id);
	node->next = NULL;
	return node;
}

// Function to read Grammar from a text file
void readGrammar(char *filename)
{
	FILE *fp = fopen(filename, "r");
	char str[256];
	char *delimiter = " ";
	int i = 0;
	lexeme *temp, *temp2;
	char *token;
	while(fgets(str, 256, fp)!=NULL)
	{
		int s = strlen(str);
		// str[s-1] = 0;
		token = strtok(str, delimiter);
		// printf("token = %s\n", token);
		temp = getLexeme(token);
		grammar[i].head = temp;
		token = strtok(NULL, delimiter); // ===>
		// printf("token = %s\n", token);
		token = strtok(NULL, delimiter);
		// printf("token = %s\n", token);
		while(token!=NULL)
		{
			temp2 = getLexeme(token);
			temp->next = temp2;
			temp = temp2;
			token = strtok(NULL, delimiter);
			// if(token!=NULL)
				// printf("token = %s\n", token);
		}
		// printf("grammar[%d].head = %s\n", i, grammar[i].head->id);
		i++;
	}
	fclose(fp);
	return;
}

void createFirstAndFollow(char *filename)
{
	FILE *fp = fopen(filename, "r");
	char str[256];
	char *delimiter = " ";
	int i = 0;
	lexeme *temp, *temp2;
	char *token;
	int len;
	while(fgets(str, 256, fp)!=NULL)
	{
		int s = strlen(str);
		// str[s-1] = 0;
		token = strtok(str, delimiter);
		// printf("token = %s\n", token);
		temp = getLexeme(token);
		firstAndFollow[i].head = temp;
		len = strlen(temp->id);
		if(temp->id[len-1]=='\n')
			temp->id[len-1] = '\0';
		// printf("size = %llu\n", sizeof(temp->id));
		// printf("token = %s\n", token);
		token = strtok(NULL, delimiter);
		// printf("token = %s\n", token);
		while(token!=NULL)
		{
			temp2 = getLexeme(token);
			len = strlen(temp2->id);
			if(temp2->id[len-1]=='\n')
				temp2->id[len-1] = '\0';
			temp->next = temp2;
			temp = temp2;
			token = strtok(NULL, delimiter);
			// if(token!=NULL)
				// printf("token = %s\n", token);
		}
		// printf("grammar[%d].head = %s\n", i, grammar[i].head->id);
		i++;
	}
	fclose(fp);
	return;
}

// Function to print the grammar (Just for Verification)
void printGrammar()
{
	int i;
	lexeme *temp;
	for(i=0; i<NO_OF_RULES; i++)
	{
		printf("%s", grammar[i].head->id);
		printf(" ===>");
		temp = grammar[i].head;
		temp = temp->next;
		while(temp!=NULL)
		{
			printf(" %s", temp->id);
			temp = temp->next;
		}
		// printf("\n");
	}
	return;
}

void printFirstAndFollow()
{
	int i;
	lexeme *temp;
	for(i=0; i<NO_OF_RULES; i++)
	{
		temp = firstAndFollow[i].head;
		while(temp->next!=NULL)
		{
			printf("%s ", temp->id);
			temp = temp->next;
		}
		printf("%s\n", temp->id);
	}
	return;
}

void createParseTable()
{
	// Output to be checked
	int i;
	lexeme *t;
	char *nt;
	nonTerminal lhs;
	terminal rhs;
	rule* temp;
	for(i=0; i<NO_OF_RULES; i++)
	{
		nt = grammar[i].head->id;
		lhs = reprNonTerminal(nt);
		// printf("lhs = %d\n",lhs);
		t = firstAndFollow[i].head;
		rhs = reprTerminal(t->id);
		// printf("first %s\n", firstAndFollow[i].head->id);
		// printf("rhs = %d\n",reprTerminal(firstAndFollow[0].head->id));
		temp = &grammar[i];
		parseTable[lhs][rhs] = temp;
		while(t->next!=NULL)
		{
			t = t->next;
			rhs = reprTerminal(t->id);
			parseTable[lhs][rhs] = temp;
		}
	}
	return;
}

int main()
{
	readGrammar("modifiedGrammar.txt");
	// printf("PRINTING GRAMMAR\n");
	// printGrammar();
	// printf("\n\nPRINTING FIRST AND FOLLOW\n");
	createFirstAndFollow("firstAndFollow.txt");
	// printFirstAndFollow();
	createParseTable();
	return 0;
}