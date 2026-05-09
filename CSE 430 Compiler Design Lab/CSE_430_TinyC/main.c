/*
 * TinyC parser driver
 *
 * Usage:
 *   ./tinyc_parser [input.tc]
 *
 * Reads TinyC code from a file (or stdin), runs the Bison parser,
 * prints a success message, prints the AST, and prints the symbol table.
 */

#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
#include "symbol_table.h"

extern int yyparse(void);
extern FILE *yyin;

extern AstNode *g_root;

static void usage(const char *argv0)
{
    fprintf(stderr, "Usage: %s [input.tc]\n", argv0);
}

int main(int argc, char **argv)
{
    if (argc > 2) {
        usage(argv[0]);
        return 1;
    }

    if (argc == 2) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("fopen");
            return 1;
        }
    }

    symtab_init();

    int rc = yyparse();
    if (rc == 0) {
        puts("Parsing successful.");

        puts("\nParse Tree (AST):");
        ast_print(g_root, 0, stdout);

        symtab_print(stdout);
    } else {
        puts("Parsing failed.");
    }

    ast_free(g_root);
    g_root = NULL;

    symtab_free();

    if (argc == 2 && yyin) {
        fclose(yyin);
    }

    return (rc == 0) ? 0 : 1;
}
