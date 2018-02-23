// Name: Aman Gupta
// ID: 2014B2A70201P

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_OF_RULES 86
#define NO_OF_TERMINALS 44
#define NO_OF_NON_TERMINALS 40

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

lexeme* getLexeme(char* id)
{
	lexeme *node = (lexeme*)malloc(sizeof(lexeme));
	strcpy(node->id, id);
	node->next = NULL;
	return node;
}

// Function to read Grammar from a text file
void readGrammar(char *filename, rule *grammar)
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
	return;
}

// Function to print the grammar (Just for Verification)
void printGrammar(rule *grammar)
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

// void createParseTable(FirstAndFollow F, table T)
// {
	// To be implemented
// }

int main()
{
	readGrammar("Modified_Grammar.txt", grammar);
	printGrammar(grammar);
	return 0;
}