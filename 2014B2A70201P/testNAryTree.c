#include <stdio.h>
#include <string.h>
#include <stdlib.h>

# define MAX_LEXEME_SIZE 50

typedef enum
{
    ASSIGNOP,   // 0
    COMMENT,    // 1
    FUNID,      // 2
    ID,         // 3
    NUM,        // 4
    RNUM,       // 5
    STR,        // 6
    END,        // 7
    INT,        // 8
    REAL,       // 9
    STRING,     // 10
    MATRIX,     // 11
    MAIN,       // 12
    SQO,        // 13
    SQC,        // 14
    OP,         // 15
    CL,         // 16
    SEMICOLON,  // 17
    COMMA,      // 18
    IF,         // 19
    ELSE,       // 20
    ENDIF,      // 21
    READ,       // 22
    PRINT,      // 23
    FUNCTION,   // 24
    PLUS,       // 25
    MINUS,      // 26
    MUL,        // 27
    DIV,        // 28
    SIZE,       // 29
    AND,        // 30
    OR,         // 31
    NOT,        // 32
    LT,         // 33
    LE,         // 34
    EQ,         // 35
    GT,         // 36
    GE,         // 37
    NE,         // 38
    EPSILON,    // 39
    ERR         // 40
} tokenClass;

typedef struct tokenInfo
{
    char lexeme[MAX_LEXEME_SIZE];
    tokenClass tokenID;
    unsigned long long lineNo;
} tokenInfo;

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
}

typedef struct tree
{
	tokenInfo* token;
	struct tree* parent;
	struct tree* firstChild;
	struct tree* nextSibling;
} tree;

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

void visit(tree* node)
{
	printf("%s\n", tokenRepr(node->token->tokenID));
	return;
}

void inOrderTraversal(tree* root)
{
	if(root==NULL)
		return;
	inOrderTraversal(root->firstChild);
	visit(root);
	tree* temp2 = root->firstChild;
	while(temp2!=NULL)
	{
		temp2 = temp2->nextSibling;
		inOrderTraversal(temp2);
	}
	return;
}

int main()
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
	return 0;
}