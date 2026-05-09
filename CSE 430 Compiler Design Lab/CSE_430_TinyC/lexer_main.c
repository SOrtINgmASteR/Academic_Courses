/*
 * TinyC lexer-only driver
 *
 * Usage:
 *   ./tinyc_lexer [input.tc]
 *
 * Prints the token stream produced by the Flex lexer.
 */

#include <stdio.h>
#include <stdlib.h>

#include "parser.tab.h" /* token codes + YYSTYPE */

extern int yylex(void);
extern FILE *yyin;

/* Defined in lexer.l */
extern int g_emit_tokens;

/* When building lexer-only (without linking parser.tab.c), provide yylval. */
YYSTYPE yylval;

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

    g_emit_tokens = 1;

    int tok;
    while ((tok = yylex()) != 0) {
        /* Free values allocated by the lexer for token printing mode. */
        switch (tok) {
        case IDENT:
        case INT_LIT:
        case FLOAT_LIT:
        case STRING_LIT:
            free(yylval.sval);
            yylval.sval = NULL;
            break;
        default:
            break;
        }
    }

    if (argc == 2 && yyin) {
        fclose(yyin);
    }

    return 0;
}
