// Name: Aman Gupta
// ID: 2014B2A70201P

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lexer.h"
#include "lexerDef.h"
#include "parserDef.h"

/*tokenInfo* createToken()
{
    tokenInfo* temp = (tokenInfo*)malloc(sizeof(tokenInfo));
    strcpy(temp->lexeme,"");
    temp->tokenID = ERR;
    return temp;
}*/


/*typedef enum
{
	mainFunction = START_INDEX_OF_NT,
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
} nonTerminal;*/

/*char* tokenRepr(int id) 
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
}*/

int stringToEnum(char* id)
{
	if(strcmp("ASSIGNOP",id)==0)
    	return ASSIGNOP;
    else if(strcmp("FUNID",id)==0)
    	return FUNID;
    else if(strcmp("ID",id)==0)
    	return ID;
    else if(strcmp("NUM",id)==0)
    	return NUM;
    else if(strcmp("RNUM",id)==0)
    	return RNUM;
    else if(strcmp("STR",id)==0)
    	return STR;
    else if(strcmp("END",id)==0)
    	return END;
    else if(strcmp("INT",id)==0)
    	return INT;
    else if(strcmp("REAL",id)==0)
    	return REAL;
    else if(strcmp("STRING",id)==0)
    	return STRING;
    else if(strcmp("MATRIX",id)==0)
    	return MATRIX;
    else if(strcmp("MAIN",id)==0)
    	return MAIN;
    else if(strcmp("SQO",id)==0)
    	return SQO;
    else if(strcmp("SQC",id)==0)
    	return SQC;
    else if(strcmp("OP",id)==0)
    	return OP;
    else if(strcmp("CL",id)==0)
    	return CL;
    else if(strcmp("SEMICOLON",id)==0)
    	return SEMICOLON;
    else if(strcmp("COMMA",id)==0)
    	return COMMA;
    else if(strcmp("IF",id)==0)
    	return IF;
    else if(strcmp("ELSE",id)==0)
    	return ELSE;
    else if(strcmp("ENDIF",id)==0)
    	return ENDIF;
    else if(strcmp("READ",id)==0)
    	return READ;
    else if(strcmp("PRINT",id)==0)
    	return PRINT;
    else if(strcmp("FUNCTION",id)==0)
    	return FUNCTION;
    else if(strcmp("PLUS",id)==0)
    	return PLUS;
    else if(strcmp("MINUS",id)==0)
    	return MINUS;
    else if(strcmp("MUL",id)==0)
    	return MUL;
    else if(strcmp("DIV",id)==0)
    	return DIV;
    else if(strcmp("SIZE",id)==0)
    	return SIZE;
    else if(strcmp("AND",id)==0)
    	return AND;
    else if(strcmp("OR",id)==0)
    	return OR;
    else if(strcmp("NOT",id)==0)
    	return NOT;
    else if(strcmp("LT",id)==0)
    	return LT;
    else if(strcmp("LE",id)==0)
    	return LE;
    else if(strcmp("EQ",id)==0)
    	return EQ;
    else if(strcmp("GT",id)==0)
    	return GT;
    else if(strcmp("GE",id)==0)
    	return GE;
    else if(strcmp("NE",id)==0)
    	return NE;
    else if(strcmp("ROOT",id)==0)
    	return ROOT;
    else if(strcmp("mainFunction",id)==0)
		return mainFunction;
	else if(strcmp("stmtsAndFunctionDefs",id)==0)
		return stmtsAndFunctionDefs;
	else if(strcmp("safdLF",id)==0)
		return safdLF;
	else if(strcmp("stmtOrFunctionDef",id)==0)
		return stmtOrFunctionDef;
	else if(strcmp("stmt",id)==0)
		return stmt;
	else if(strcmp("functionDef",id)==0)
		return functionDef;
	else if(strcmp("parameter_list",id)==0)
		return parameter_list;
	else if(strcmp("type",id)==0)
		return type;
	else if(strcmp("remainingList",id)==0)
		return remainingList;
	else if(strcmp("declarationStmt",id)==0)
		return declarationStmt;
	else if(strcmp("var_list",id)==0)
		return var_list;
	else if(strcmp("more_ids",id)==0)
		return more_ids;
	else if(strcmp("assignmentStmt_type1",id)==0)
		return assignmentStmt_type1;
	else if(strcmp("assignmentStmt_type2",id)==0)
		return assignmentStmt_type2;
	else if(strcmp("leftHandSide_singleVar",id)==0)
		return leftHandSide_singleVar;
	else if(strcmp("leftHandSide_listVar",id)==0)
		return leftHandSide_listVar;
	else if(strcmp("rightHandSide_type1",id)==0)
		return rightHandSide_type1;
	else if(strcmp("rightHandSide_type2",id)==0)
		return rightHandSide_type2;
	else if(strcmp("sizeExpression",id)==0)
		return sizeExpression;
	else if(strcmp("ifStmt",id)==0)
		return ifStmt;
	else if(strcmp("ifStmtLF",id)==0)
		return ifStmtLF;
	else if(strcmp("otherStmts",id)==0)
		return otherStmts;
	else if(strcmp("ioStmt",id)==0)
		return ioStmt;
	else if(strcmp("funCallStmt",id)==0)
		return funCallStmt;
	else if(strcmp("inputParameterList",id)==0)
		return inputParameterList;
	else if(strcmp("listVar",id)==0)
		return listVar;
	else if(strcmp("arithmeticExpression",id)==0)
		return arithmeticExpression;
	else if(strcmp("aeLF",id)==0)
		return aeLF;
	else if(strcmp("arithmeticTerm",id)==0)
		return arithmeticTerm;
	else if(strcmp("atLF",id)==0)
		return atLF;
	else if(strcmp("factor",id)==0)
		return factor;
	else if(strcmp("operator_lowPrecedence",id)==0)
		return operator_lowPrecedence;
	else if(strcmp("operator_highPrecedence",id)==0)
		return operator_highPrecedence;
	else if(strcmp("booleanExpression",id)==0)
		return booleanExpression;
	else if(strcmp("constrainedVars",id)==0)
		return constrainedVars;
	else if(strcmp("var",id)==0)
		return var;
	else if(strcmp("matrix",id)==0)
		return matrix;
	else if(strcmp("rows",id)==0)
		return rows;
	else if(strcmp("rowsLF",id)==0)
		return rowsLF;
	else if(strcmp("row",id)==0)
		return row;
	else if(strcmp("remainingColElements",id)==0)
		return remainingColElements;
	else if(strcmp("matrixElement",id)==0)
		return matrixElement;
	else if(strcmp("logicalOp",id)==0)
		return logicalOp;
	else if(strcmp("relationalOp",id)==0)
		return relationalOp;
	else if(strcmp("EPSILON",id)==0)
		return EPSILON;
	else
		return -1;
}

char* enumString[] = {"ASSIGNOP", "COMMENT", "FUNID", "ID", "NUM", "RNUM", "STR", "END", "INT", "REAL", "STRING", "MATRIX", "MAIN", "SQO", "SQC", "OP", "CL", "SEMICOLON", "COMMA", "IF", "ELSE", "ENDIF", "READ", "PRINT", "FUNCTION", "PLUS", "MINUS", "MUL", "DIV", "SIZE", "AND", "OR", "NOT", "LT", "LE", "EQ", "GT", "GE", "NE", "EPSILON", "ERR", "DOLLAR", "ROOT", "mainFunction", "stmtsAndFunctionDefs", "safdLF", "stmtOrFunctionDef", "stmt", "functionDef", "parameter_list", "type", "remainingList", "declarationStmt", "var_list", "more_ids", "assignmentStmt_type1", "assignmentStmt_type2", "leftHandSide_singleVar", "leftHandSide_listVar", "rightHandSide_type1", "rightHandSide_type2", "sizeExpression", "ifStmt", "ifStmtLF", "otherStmts", "ioStmt", "funCallStmt", "inputParameterList", "listVar", "arithmeticExpression", "aeLF", "arithmeticTerm", "atLF", "factor", "operator_lowPrecedence", "operator_highPrecedence", "booleanExpression", "constrainedVars", "var", "matrix", "rows", "rowsLF", "row", "remainingColElements", "matrixElement", "logicalOp", "relationalOp"};

char* enumToString(int id)
{
	return enumString[id];
}

// Structure to store Terminal/Non-Terminal
/*typedef struct lexeme
{
	// char id[30];
	int id;
	struct lexeme *next;
}lexeme;

// Structure to store pointer to LHS of a Rule
typedef struct rule
{
	lexeme *head;
}rule;*/

rule grammar[NO_OF_RULES]; // Array of Pointers to LHS of a Rule
rule firstAndFollow[NO_OF_RULES];
lexeme* parseTable[NO_OF_NON_TERMINALS][NO_OF_TERMINALS+1];

lexeme* getLexeme(char* id)
{
	lexeme *node = (lexeme*)malloc(sizeof(lexeme));
	// strcpy(node->id, id);
	char* str;
	int len = strlen(id);
	if(id[len-1]=='\n')
			id[len-1] = '\0';
	node->id = stringToEnum(id);
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
	int len;
	while(fgets(str, 256, fp)!=NULL)
	{
		int s = strlen(str);
		// str[s-1] = 0;
		token = strtok(str, delimiter);
		// printf("token = %s\n", token);
		temp = getLexeme(token);
		grammar[i].head = temp;
		// len = strlen(temp->id);
		// if(temp->id[len-1]=='\n')
			// temp->id[len-1] = '\0';
		token = strtok(NULL, delimiter); // ===>
		// printf("token = %s\n", token);
		token = strtok(NULL, delimiter);
		// printf("token = %s\n", token);
		while(token!=NULL)
		{
			temp2 = getLexeme(token);
			// len = strlen(temp2->id);
			// if(temp2->id[len-1]=='\n')
				// temp2->id[len-1] = '\0';
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
		// len = strlen(temp->id);
		// if(temp->id[len-1]=='\n')
			// temp->id[len-1] = '\0';
		// printf("size = %llu\n", sizeof(temp->id));
		// printf("token = %s\n", token);
		token = strtok(NULL, delimiter);
		// printf("token = %s\n", token);
		while(token!=NULL)
		{
			temp2 = getLexeme(token);
			// len = strlen(temp2->id);
			// if(temp2->id[len-1]=='\n')
				// temp2->id[len-1] = '\0';
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
		printf("%s", enumToString(grammar[i].head->id));
		printf(" ===>");
		temp = grammar[i].head;
		temp = temp->next;
		while(temp!=NULL)
		{
			printf(" %s", enumToString(temp->id));
			temp = temp->next;
		}
		if(i!=NO_OF_RULES-1)
			printf("\n");
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
			printf("%s ", enumToString(temp->id));
			temp = temp->next;
		}
		printf("%s", enumToString(temp->id));
		if(i!=NO_OF_RULES-1)
			printf("\n");
	}
	return;
}

void createParseTable()
{
	// Output to be checked
	int i;
	lexeme *t;
	int lhs, rhs;
	lexeme* temp;
	for(i=0; i<NO_OF_RULES; i++)
	{
		lhs = grammar[i].head->id;
		// printf("lhs = %d\n",lhs);
		t = firstAndFollow[i].head;
		rhs = t->id;
		// printf("first %s\n", firstAndFollow[i].head->id);
		// printf("rhs = %d\n",reprTerminal(firstAndFollow[0].head->id));
		temp = grammar[i].head;
		temp = temp->next;
		// temp = temp->head->next;
		parseTable[lhs-START_INDEX_OF_NT][rhs] = temp;
		while(t->next!=NULL)
		{
			t = t->next;
			rhs = t->id;
			parseTable[lhs-START_INDEX_OF_NT][rhs] = temp;
		}
	}
	return;
}

void initializeParseTable()
{
	for(int i=0; i<NO_OF_NON_TERMINALS; i++)
	{
		for(int j=0; j<NO_OF_TERMINALS+1; j++)
			parseTable[i][j] = NULL;
	}
}

void printParseTable()
{
	lexeme* temp;
	for(int i=0; i<NO_OF_NON_TERMINALS; i++)
	{
		// printf("\nNon-Terminal - %d\n", START_INDEX_OF_NT+i);
		printf("Non-Terminal - %s\n", enumToString(START_INDEX_OF_NT+i));
		for(int j=0; j<NO_OF_TERMINALS+1; j++)
		{
			temp = parseTable[i][j];
			if(temp!=NULL)
			{
				printf("%s ",enumToString(temp->id));
				// printf("%s ",temp->head->id);
			}
			else
			{
				printf("NULL ");
			}
		}
		printf("\n\n");
	}
}

/*typedef struct stackNode
{
	int id;
	struct stackNode* next;
} stackNode;

typedef struct stack
{
	stackNode* top;
	// unsigned int capacity;
} stack;*/

stackNode* createStackNode(int id)
{
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->id = id;
	temp->next = NULL;
	return temp;
}

stack* initializeStack()
{
	stack* temp = (stack*)malloc(sizeof(stack));
	temp->top = NULL;
	return temp;
}

bool isEmpty(stack* stack)
{
	if(stack->top==NULL)
		return true;
	else
		return false;
}

void push(stack* stack, stackNode* node)
{
	if(isEmpty(stack))
	{
		stack->top = node;
	}
	else
	{
		node->next = stack->top;
		stack->top = node;
	}
	return;
}

int pop(stack* stack)
{
	stackNode* temp = stack->top;
	if(isEmpty(stack))
	{
		return -1;
	}
	else
	{
		stack->top = stack->top->next;
		free(temp);
		return 1;
	}
}

int top(stack* stack)
{
	if(isEmpty(stack))
		return -1;
	else
		return stack->top->id;
}

void reverseStack(stack* mainStack, stack* auxStack)
{
	stackNode* temp;
	int ele;
	while(!isEmpty(auxStack))
	{
		ele = top(auxStack);
		temp = createStackNode(ele);
		push(mainStack, temp);
		pop(auxStack);
	}
	return;
}

void printStack(stack* stack)
{
	int ele;
	stackNode* temp = stack->top;
	while(temp!=NULL)
	{
		printf("%s\n", enumToString(temp->id));
		temp = temp->next;
	}
	return;
}

/*void testStackFunctionalities()
{
	stack* auxStack = initializeStack(auxStack);
	stackNode* node1 = createStackNode(MAIN);
	stackNode* node2 = createStackNode(SQO);
	stackNode* node3 = createStackNode(SQC);
	stackNode* node4 = createStackNode(stmtsAndFunctionDefs);
	stackNode* node5 = createStackNode(END);
	push(auxStack, node1);
	push(auxStack, node2);
	push(auxStack, node3);
	push(auxStack, node4);
	push(auxStack, node5);
	int ele;
	int flag;
	// printf("Aux Stack");
	// printStack(auxStack);
	stack* mainStack = initializeStack(mainStack);
	reverseStack(mainStack, auxStack);
	printf("Reversed Stack\n");
	printStack(mainStack);
	return;
}*/

stack* auxStack;
stack* mainStack;

/*typedef struct tree
{
	tokenInfo* token;
	struct tree* parent;
	struct tree* firstChild;
	struct tree* nextSibling;
} tree;*/


tree* createTreeNode(tokenInfo* token)
{
	tree* temp = (tree*)malloc(sizeof(tree));
	temp->token = token;
	temp->parent = NULL;
	temp->firstChild = NULL;
	temp->nextSibling = NULL;
	return temp;
}

void insertTreeNode(tree* root, tree* node)
{
	tree* temp;
	if(root==NULL)
		root = node;
	else if(root->firstChild==NULL)
	{
		root->firstChild = node;
		node->parent = root;
	}
	else if(root->firstChild->nextSibling==NULL)
	{
		root->firstChild->nextSibling = node;
		node->parent = root;
	}
	else
	{
		temp = root->firstChild->nextSibling;
		while(temp->nextSibling!=NULL)
			temp = temp->nextSibling;
		temp->nextSibling = node;
		node->parent = root;
	}
	return;
}

void visit(tree* node, FILE* fp2)
{
	// if(node->token->tokenID == mainFunction)
		// printf("ROOT\n");
	// else	
		fprintf(fp2,"%s\n", enumToString(node->token->tokenID));
	return;
}

void inOrderTraversal(tree* root, FILE* fp2)
{
	// printf("\nEntered inOrderTraversal\n");
	if(root==NULL)
		return;
	inOrderTraversal(root->firstChild, fp2);
	visit(root, fp2);
	tree* temp2 = root->firstChild;
	while(temp2!=NULL)
	{
		temp2 = temp2->nextSibling;
		inOrderTraversal(temp2, fp2);
	}
	return;
}

tree* parseTree;

/*void testNAryTreeFunctionalities()
{
	tokenInfo* t1 = createToken();
	t1->tokenID = MAIN;
	tokenInfo* t2 = createToken();
	t2->tokenID = INT;
	tokenInfo* t3 = createToken();
	t3->tokenID = EPSILON;
	tokenInfo* t4 = createToken();
	t4->tokenID = END;
	tokenInfo* t5 = createToken();
	t5->tokenID = ENDIF;
	tokenInfo* t6 = createToken();
	t6->tokenID = FUNCTION;
	tokenInfo* t7 = createToken();
	t7->tokenID = STRING;
	tokenInfo* t8 = createToken();
	t8->tokenID = MATRIX;
	tokenInfo* t9 = createToken();
	t9->tokenID = IF;
	tree* n1 = createTreeNode(t1);
	tree* n2 = createTreeNode(t2);
	tree* n3 = createTreeNode(t3);
	tree* n4 = createTreeNode(t4);
	tree* n5 = createTreeNode(t5);
	tree* n6 = createTreeNode(t6);
	tree* n7 = createTreeNode(t7);
	tree* n8 = createTreeNode(t8);
	tree* n9 = createTreeNode(t9);
	insertTreeNode(n1,n2);
	insertTreeNode(n1,n3);
	insertTreeNode(n1,n4);
	insertTreeNode(n1,n5);
	insertTreeNode(n4,n6);
	insertTreeNode(n4,n7);
	insertTreeNode(n4,n8);
	insertTreeNode(n7,n9);
	inOrderTraversal(n1);
	return;
}*/

void copyDetails(tree* root, tokenInfo* token)
{
	root->token = token;
	return;
}

void copyToken(tokenInfo* dest, tokenInfo* src)
{
	dest->tokenID = src->tokenID;
	strcpy(dest->lexeme, src->lexeme);
	dest->lineNo = src->lineNo;
	return;
}

void parseInputSourceCode(FILE* fp)
{
	stackNode* stNode = createStackNode(DOLLAR);
	push(mainStack, stNode); // pushed End of File Marker

	tokenInfo* rootToken = (tokenInfo*)malloc(sizeof(tokenInfo));
	strcpy(rootToken->lexeme, "ROOT");
	rootToken->tokenID = ROOT;
	parseTree = createTreeNode(rootToken);


	tokenInfo* mainFunctionToken = (tokenInfo*)malloc(sizeof(tokenInfo));
	strcpy(mainFunctionToken->lexeme, "mainFunction");
	mainFunctionToken->tokenID = mainFunction;
	
	tree* mainNode = createTreeNode(mainFunctionToken);
	insertTreeNode(parseTree, mainNode);
	parseTree = parseTree->firstChild;
	// printf("parent = %s\n", enumToString(parseTree->parent->token->tokenID));

	tokenInfo* newToken = (tokenInfo*)malloc(sizeof(tokenInfo));
	strcpy(newToken->lexeme, "");
	newToken->tokenID = ERR;

	stNode = createStackNode(mainFunction);
	push(mainStack, stNode);

	// printf("%s\n", enumToString(newToken->tokenID));
	tree* trNode;

    // insertTreeNode(parseTree, node);
    // printf("Created Tree\n");
    // inOrderTraversal(parseTree);
    getNextToken(fp,newToken);
	// printf("check = %s\n", enumToString(parseTree->token->tokenID));
	// printf("check = %s\n", enumToString(parseTree->token->tokenID));
    while(newToken->tokenID == COMMENT)
    {
    	getNextToken(fp,newToken);
    }
    int topOfStack;
    lexeme* ruleRhs;
    tree* currRoot = parseTree;
    tokenInfo* tempToken;
    tokenInfo* tempToken2;

    // printf("b;a--------------------------\n");
    // inOrderTraversal(parseTree);
    while(newToken->tokenID!=DOLLAR)
    {
    	topOfStack = top(mainStack);
    	if(topOfStack >= START_INDEX_OF_NT) // topOfStack is Non-terminal
    	{
    		// int i = topOfStack, j= newToken->tokenID;
    		// printf("%d %d %p %p %p\n",i,j,parseTable[i][j-1], parseTable[i][j], parseTable[i][j+1] );
    		if(parseTable[topOfStack-START_INDEX_OF_NT][newToken->tokenID]!=NULL)
    		{
    			ruleRhs = parseTable[topOfStack-START_INDEX_OF_NT][newToken->tokenID];
    			// printf("Before 1 = %s\n", enumToString(top(mainStack)));
    			pop(mainStack);
    			// printf("After 1 = %s\n", enumToString(top(mainStack)));
    			while(ruleRhs!=NULL)
    			{
    				// printf("%s\n", enumToString(ruleRhs->id));
    				
    				
    				tempToken = createToken();
    				tempToken->tokenID = ruleRhs->id;
    				trNode = createTreeNode(tempToken);
    				// printf("check = %s\n", enumToString(tempToken->tokenID));
    				// printf("parseTree = %s\n",enumToString(parseTree->token->tokenID));
    				insertTreeNode(currRoot, trNode);
    				// printf("b;a--------------------------\n");
    				// inOrderTraversal(parseTree);
    				if(ruleRhs->id==EPSILON)
    				{
    					while(currRoot->parent->nextSibling==NULL)
    					{
    						currRoot = currRoot->parent;
    						if(currRoot->parent==NULL)
    							return;
    					}
    				}
    				
    				stNode = createStackNode(ruleRhs->id);
    				push(auxStack, stNode);
    				ruleRhs = ruleRhs->next;
    			}
    			currRoot = currRoot->firstChild;
    			// printStack(auxStack);
    			reverseStack(mainStack, auxStack);
    			// printStack(mainStack);
    		}
    		else
    		{
    			printf("ERROR in PARSING - 1\n");
    			// exit(0);
    			return;
    		}
    	}
    	else if(topOfStack < START_INDEX_OF_NT && topOfStack!=-1) // topOfStack is Terminal
    	{
    		// int i = topOfStack, j= newToken->tokenID;
    		// printf("%d %d %p %p %p\n",i,j,parseTable[i][j-1], parseTable[i][j], parseTable[i][j+1] );
    		if(topOfStack == 39) // 39 is EPSILON
    		{
    			// trNode = createTreeNode(newToken);
    			// insertTreeNode(parseTree, trNode);
    			// printf("Before 2 = %s\n", enumToString(top(mainStack)));
    			pop(mainStack);
    		}
    		else if(topOfStack == newToken->tokenID)
    		{
    			// trNode = createTreeNode(newToken);
    			// insertTreeNode(parseTree, trNode);
    			// printStack(mainStack);
    			// printf("blah\n");
    			// printf("Before 2 = %s\n", enumToString(top(mainStack)));

    			tempToken2 = createToken();
    			copyToken(tempToken2, newToken);
    			copyDetails(currRoot, tempToken2);
    			// printToken(currRoot->token);
    			pop(mainStack);
    			
    			if(currRoot->nextSibling!=NULL)
    				currRoot = currRoot->nextSibling;
    			else
    			{
    				while(currRoot->parent->nextSibling==NULL)
    				{
    					currRoot = currRoot->parent;
    					if(currRoot->parent==NULL)
    						return;
    				}
    				currRoot = currRoot->parent->nextSibling;
    			}
    			// printStack(mainStack);
    			// printf("After 2 = %s\n", enumToString(top(mainStack)));
    			// printf("\n\n");
    			getNextToken(fp, newToken);
    			while(newToken->tokenID == COMMENT)
    			{
			    	getNextToken(fp,newToken);
			    }
			    // printf("currRoot = %s\n",enumToString(currRoot->token->tokenID));
			    // printf("parseTree = %s\n",enumToString(parseTree->token->tokenID));
    		}
    		else
    		{
    			// printf("topOfStack = %s\n", enumToString(topOfStack));
    			// printf("newToken->id = %s\n", enumToString(newToken->tokenID));
    			printf("ERROR in PARSING - 2\n");
    			// exit(0);
    			return;
    		}
    	}
    	else if(topOfStack == DOLLAR)
    	{
    		printf("ERROR in PARSING - 3\n");
    		// exit(0);
    		return;
    	}
    }
    topOfStack = top(mainStack);
    if(newToken->tokenID == DOLLAR && topOfStack!=41) // 41 - DOLLAR Index in enum
    {
    	// printStack(mainStack);
    	// printf("topOfStack = %s\n", enumToString(topOfStack));
    	printf("ERROR in PARSING - 4\n");
    	// exit(0);
    	return;
    }
    else if(newToken->tokenID == DOLLAR && topOfStack == 41)
    {
    	// printf("parseTree = %s\n",enumToString(parseTree->token->tokenID));
    	printf("Input source code is syntactically correct...........\n");
    }
    return; 
}


// int main(int argc, char* argv[])
// int main()
void createParseTree(FILE* fp, FILE* fp2)
{
	// FILE* fp = fopen("parseTest.txt","r");
	// FILE* fp = fopen(argv[1],"r");
	readGrammar("modifiedGrammar.txt");
	// printf("PRINTING GRAMMAR\n");
	// printGrammar();
	// printf("\n\nPRINTING FIRST AND FOLLOW\n");
	createFirstAndFollow("firstAndFollow.txt");
	// printFirstAndFollow();
	initializeParseTable();
	createParseTable();
	// printParseTable();
	// printf("Waiting....");
	// testStackFunctionalities();
	// testNAryTreeFunctionalities();
	auxStack = initializeStack();
	mainStack = initializeStack();
	parseInputSourceCode(fp);
	// FILE* fp2 = fopen("parsetreeoutfile.txt","w");
	// printf("Returned from parsing Function--------------------\n");
	// fclose(fp);
	// printf("Entering inOrderTraversal\n");
	// printf("blah = %s\n", enumToString(parseTree->token->tokenID));
	inOrderTraversal(parseTree, fp2);
	// fclose(fp2);
	return;
	// return 0;
}

void printParseTree(FILE* fp2)
{
	char c;
	while((c=fgetc(fp2))!=EOF)
		putchar(c);
}