#ifndef AST_H
#define AST_H

/*
 * TinyC AST / Parse Tree
 *
 * This module provides a small, easy-to-print tree structure that the Bison
 * parser builds while parsing TinyC source code.
 *
 * Ownership rules:
 * - Functions that accept `char *` take ownership of that heap-allocated string.
 * - `ast_free()` releases the entire tree including owned strings.
 */

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum AstKind {
    AST_PROGRAM,
    AST_FUNCTION,
    AST_TYPE,
    AST_BLOCK,
    AST_DECL,
    AST_ASSIGN,
    AST_IF,
    AST_WHILE,
    AST_RETURN,
    AST_PRINT,
    AST_BINOP,
    AST_IDENTIFIER,
    AST_INT_LITERAL,
    AST_FLOAT_LITERAL,
    AST_STRING_LITERAL
} AstKind;

typedef struct AstNode {
    AstKind kind;
    int line;

    /* Optional text for this node:
     * - identifier name
     * - literal value
     * - operator symbol (e.g., "+", "==")
     * - type name (e.g., "int")
     */
    char *text;

    /* Up to three children for fixed-arity constructs. */
    struct AstNode *a;
    struct AstNode *b;
    struct AstNode *c;

    /* For building ordered lists (statement lists, identifier lists, etc.). */
    struct AstNode *next;
} AstNode;

AstNode *ast_make_program(AstNode *function_node, int line);
AstNode *ast_make_function(char *name, AstNode *ret_type, AstNode *body, int line);
AstNode *ast_make_type(char *type_name, int line);
AstNode *ast_make_block(AstNode *stmts, int line);
AstNode *ast_make_decl(char *type_name, AstNode *id_list, int line);
AstNode *ast_make_assign(AstNode *id, AstNode *expr, int line);
AstNode *ast_make_if(AstNode *cond, AstNode *then_branch, AstNode *else_branch, int line);
AstNode *ast_make_while(AstNode *cond, AstNode *body, int line);
AstNode *ast_make_return(AstNode *expr, int line);
AstNode *ast_make_print(AstNode *arg, int line);

AstNode *ast_make_binop(const char *op, AstNode *lhs, AstNode *rhs, int line);
AstNode *ast_make_identifier(char *name, int line);
AstNode *ast_make_int_literal(char *value, int line);
AstNode *ast_make_float_literal(char *value, int line);
AstNode *ast_make_string_literal(char *value, int line);

/* List helper: appends `node` to the end of `list` and returns the head. */
AstNode *ast_list_append(AstNode *list, AstNode *node);

/* Pretty-print the AST. */
void ast_print(const AstNode *node, int indent, FILE *out);

/* Recursively free a node (including its children and `next` chain). */
void ast_free(AstNode *node);

#ifdef __cplusplus
}
#endif

#endif /* AST_H */
