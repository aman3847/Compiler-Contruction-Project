// Name: Aman Gupta
// ID: 2014B2A70201P

#ifndef PARSERDEF
#define PARSERDEF

#define NO_OF_RULES 86
#define NO_OF_TERMINALS 38
#define NO_OF_NON_TERMINALS 44
#define START_INDEX_OF_NT 43

// Structure to store Terminal/Non-Terminal
typedef struct lexeme
{
	int id;
	struct lexeme *next;
}lexeme;

// Structure to store pointer to LHS of a Rule
typedef struct rule
{
	lexeme *head;
}rule;

// Structure of nodes that are to be stored in Stack
typedef struct stackNode
{
	int id;
	struct stackNode* next;
} stackNode;

// Structure of Stack
typedef struct stack
{
	stackNode* top;
} stack;

// Structure of Tree
typedef struct tree
{
	tokenInfo* token;
	struct tree* parent;
	struct tree* firstChild;
	struct tree* nextSibling;
} tree;

#endif