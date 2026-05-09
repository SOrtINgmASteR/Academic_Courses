#include "ast.h"

#include <stdlib.h>
#include <string.h>

static AstNode *ast_alloc(AstKind kind, int line)
{
    AstNode *n = (AstNode *)calloc(1, sizeof(AstNode));
    if (!n) {
        fprintf(stderr, "fatal: out of memory while allocating AST node\n");
        exit(2);
    }
    n->kind = kind;
    n->line = line;
    return n;
}

static char *xstrdup(const char *s)
{
    if (!s) {
        return NULL;
    }
    size_t len = strlen(s);
    char *out = (char *)malloc(len + 1);
    if (!out) {
        fprintf(stderr, "fatal: out of memory while duplicating string\n");
        exit(2);
    }
    memcpy(out, s, len + 1);
    return out;
}

AstNode *ast_make_program(AstNode *function_node, int line)
{
    AstNode *n = ast_alloc(AST_PROGRAM, line);
    n->a = function_node;
    return n;
}

AstNode *ast_make_function(char *name, AstNode *ret_type, AstNode *body, int line)
{
    AstNode *n = ast_alloc(AST_FUNCTION, line);
    n->text = name; /* owned */
    n->a = ret_type;
    n->b = body;
    return n;
}

AstNode *ast_make_type(char *type_name, int line)
{
    AstNode *n = ast_alloc(AST_TYPE, line);
    n->text = type_name; /* owned */
    return n;
}

AstNode *ast_make_block(AstNode *stmts, int line)
{
    AstNode *n = ast_alloc(AST_BLOCK, line);
    n->a = stmts;
    return n;
}

AstNode *ast_make_decl(char *type_name, AstNode *id_list, int line)
{
    AstNode *n = ast_alloc(AST_DECL, line);
    n->text = type_name; /* owned */
    n->a = id_list;
    return n;
}

AstNode *ast_make_assign(AstNode *id, AstNode *expr, int line)
{
    AstNode *n = ast_alloc(AST_ASSIGN, line);
    n->a = id;
    n->b = expr;
    return n;
}

AstNode *ast_make_if(AstNode *cond, AstNode *then_branch, AstNode *else_branch, int line)
{
    AstNode *n = ast_alloc(AST_IF, line);
    n->a = cond;
    n->b = then_branch;
    n->c = else_branch;
    return n;
}

AstNode *ast_make_while(AstNode *cond, AstNode *body, int line)
{
    AstNode *n = ast_alloc(AST_WHILE, line);
    n->a = cond;
    n->b = body;
    return n;
}

AstNode *ast_make_return(AstNode *expr, int line)
{
    AstNode *n = ast_alloc(AST_RETURN, line);
    n->a = expr;
    return n;
}

AstNode *ast_make_print(AstNode *arg, int line)
{
    AstNode *n = ast_alloc(AST_PRINT, line);
    n->a = arg;
    return n;
}

AstNode *ast_make_binop(const char *op, AstNode *lhs, AstNode *rhs, int line)
{
    AstNode *n = ast_alloc(AST_BINOP, line);
    n->text = xstrdup(op); /* owned */
    n->a = lhs;
    n->b = rhs;
    return n;
}

AstNode *ast_make_identifier(char *name, int line)
{
    AstNode *n = ast_alloc(AST_IDENTIFIER, line);
    n->text = name; /* owned */
    return n;
}

AstNode *ast_make_int_literal(char *value, int line)
{
    AstNode *n = ast_alloc(AST_INT_LITERAL, line);
    n->text = value; /* owned */
    return n;
}

AstNode *ast_make_float_literal(char *value, int line)
{
    AstNode *n = ast_alloc(AST_FLOAT_LITERAL, line);
    n->text = value; /* owned */
    return n;
}

AstNode *ast_make_string_literal(char *value, int line)
{
    AstNode *n = ast_alloc(AST_STRING_LITERAL, line);
    n->text = value; /* owned */
    return n;
}

AstNode *ast_list_append(AstNode *list, AstNode *node)
{
    if (!node) {
        return list;
    }
    if (!list) {
        return node;
    }

    AstNode *cur = list;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = node;
    return list;
}

static const char *ast_kind_name(AstKind kind)
{
    switch (kind) {
    case AST_PROGRAM:
        return "PROGRAM";
    case AST_FUNCTION:
        return "FUNCTION";
    case AST_TYPE:
        return "TYPE";
    case AST_BLOCK:
        return "BLOCK";
    case AST_DECL:
        return "DECL";
    case AST_ASSIGN:
        return "ASSIGN";
    case AST_IF:
        return "IF";
    case AST_WHILE:
        return "WHILE";
    case AST_RETURN:
        return "RETURN";
    case AST_PRINT:
        return "PRINT";
    case AST_BINOP:
        return "BINOP";
    case AST_IDENTIFIER:
        return "IDENT";
    case AST_INT_LITERAL:
        return "INT_LIT";
    case AST_FLOAT_LITERAL:
        return "FLOAT_LIT";
    case AST_STRING_LITERAL:
        return "STRING_LIT";
    default:
        return "<unknown>";
    }
}

static void indent_out(int indent, FILE *out)
{
    for (int i = 0; i < indent; i++) {
        fputs("  ", out);
    }
}

static void ast_print_child(const char *label, const AstNode *child, int indent, FILE *out)
{
    if (!child) {
        return;
    }
    indent_out(indent, out);
    fprintf(out, "%s:\n", label);
    ast_print(child, indent + 1, out);
}

void ast_print(const AstNode *node, int indent, FILE *out)
{
    for (const AstNode *cur = node; cur; cur = cur->next) {
        indent_out(indent, out);
        fprintf(out, "%s", ast_kind_name(cur->kind));
        if (cur->text) {
            fprintf(out, " (%s)", cur->text);
        }
        fprintf(out, " [line %d]", cur->line);
        fputc('\n', out);

        ast_print_child("A", cur->a, indent + 1, out);
        ast_print_child("B", cur->b, indent + 1, out);
        ast_print_child("C", cur->c, indent + 1, out);
    }
}

void ast_free(AstNode *node)
{
    if (!node) {
        return;
    }

    ast_free(node->a);
    ast_free(node->b);
    ast_free(node->c);
    ast_free(node->next);

    free(node->text);
    free(node);
}
