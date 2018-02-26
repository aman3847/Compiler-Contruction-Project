// Name: Aman Gupta
// ID: 2014B2A70201P

#ifndef LEXERDEF
#define LEXERDEF

# define MAX_LEXEME_SIZE 50
# define START_INDEX_OF_NT 43

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
    ERR,        // 40
    DOLLAR,     // 41
    ROOT        // 42
} tokenClass;

typedef enum
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

} nonTerminal;

typedef struct tokenInfo
{
    char lexeme[MAX_LEXEME_SIZE];
    int tokenID;
    unsigned long long lineNo;
} tokenInfo;

#endif