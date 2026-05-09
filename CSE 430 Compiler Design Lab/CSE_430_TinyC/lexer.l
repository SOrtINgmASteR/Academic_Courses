/*
 * TinyC Lexer (Flex)
 *
 * Tokenizes a small C-like language:
 * - Recognizes C89 32 keywords (plus TinyC built-in `print`)
 * - Identifiers
 * - Integer, float, and string literals
 * - Operators and separators
 * - Ignores whitespace and comments
 *
 * Token printing:
 * - If `g_emit_tokens` is set to 1, the lexer prints a readable token stream.
 *   This is used by the `tinyc_lexer` binary.
 */

%option noyywrap
%option yylineno
%option nodefault
%option never-interactive
%option noinput
%option nounput

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.tab.h" /* token definitions + YYSTYPE */

int g_emit_tokens = 0;

static char *tinyc_strdup(const char *s)
{
    if (!s) {
        return NULL;
    }
    size_t len = strlen(s);
    char *out = (char *)malloc(len + 1);
    if (!out) {
        fprintf(stderr, "fatal: out of memory\n");
        exit(2);
    }
    memcpy(out, s, len + 1);
    return out;
}

typedef struct {
    const char *kw;
    int tok;
} Keyword;

static const Keyword kKeywords[] = {
    /* C89 keywords (32) */
    {"auto", AUTO},
    {"break", BREAK},
    {"case", CASE},
    {"char", CHAR},
    {"const", CONST},
    {"continue", CONTINUE},
    {"default", DEFAULT},
    {"do", DO},
    {"double", DOUBLE},
    {"else", ELSE},
    {"enum", ENUM},
    {"extern", EXTERN},
    {"float", FLOAT},
    {"for", FOR},
    {"goto", GOTO},
    {"if", IF},
    {"int", INT},
    {"long", LONG},
    {"register", REGISTER},
    {"return", RETURN},
    {"short", SHORT},
    {"signed", SIGNED},
    {"sizeof", SIZEOF},
    {"static", STATIC},
    {"struct", STRUCT},
    {"switch", SWITCH},
    {"typedef", TYPEDEF},
    {"union", UNION},
    {"unsigned", UNSIGNED},
    {"void", VOID},
    {"volatile", VOLATILE},
    {"while", WHILE},

    /* TinyC built-in */
    {"print", PRINT},
};

static int keyword_token(const char *text)
{
    size_t n = sizeof(kKeywords) / sizeof(kKeywords[0]);
    for (size_t i = 0; i < n; i++) {
        if (strcmp(text, kKeywords[i].kw) == 0) {
            return kKeywords[i].tok;
        }
    }
    return IDENT;
}

static const char *token_name(int tok)
{
    switch (tok) {
    case 0: return "EOF";
    /* Keywords */
    case AUTO: return "KW_AUTO";
    case BREAK: return "KW_BREAK";
    case CASE: return "KW_CASE";
    case CHAR: return "KW_CHAR";
    case CONST: return "KW_CONST";
    case CONTINUE: return "KW_CONTINUE";
    case DEFAULT: return "KW_DEFAULT";
    case DO: return "KW_DO";
    case DOUBLE: return "KW_DOUBLE";
    case ELSE: return "KW_ELSE";
    case ENUM: return "KW_ENUM";
    case EXTERN: return "KW_EXTERN";
    case FLOAT: return "KW_FLOAT";
    case FOR: return "KW_FOR";
    case GOTO: return "KW_GOTO";
    case IF: return "KW_IF";
    case INT: return "KW_INT";
    case LONG: return "KW_LONG";
    case REGISTER: return "KW_REGISTER";
    case RETURN: return "KW_RETURN";
    case SHORT: return "KW_SHORT";
    case SIGNED: return "KW_SIGNED";
    case SIZEOF: return "KW_SIZEOF";
    case STATIC: return "KW_STATIC";
    case STRUCT: return "KW_STRUCT";
    case SWITCH: return "KW_SWITCH";
    case TYPEDEF: return "KW_TYPEDEF";
    case UNION: return "KW_UNION";
    case UNSIGNED: return "KW_UNSIGNED";
    case VOID: return "KW_VOID";
    case VOLATILE: return "KW_VOLATILE";
    case WHILE: return "KW_WHILE";

    /* Built-in */
    case PRINT: return "PRINT";

    /* Identifiers + literals */
    case IDENT: return "IDENT";
    case INT_LIT: return "INT_LIT";
    case FLOAT_LIT: return "FLOAT_LIT";
    case STRING_LIT: return "STRING_LIT";

    /* Operators */
    case PLUS: return "PLUS";
    case MINUS: return "MINUS";
    case STAR: return "STAR";
    case SLASH: return "SLASH";
    case ASSIGN: return "ASSIGN";
    case EQ: return "EQ";
    case NEQ: return "NEQ";
    case LT: return "LT";
    case GT: return "GT";
    case LE: return "LE";
    case GE: return "GE";

    /* Separators */
    case SEMI: return "SEMI";
    case COMMA: return "COMMA";
    case LPAREN: return "LPAREN";
    case RPAREN: return "RPAREN";
    case LBRACE: return "LBRACE";
    case RBRACE: return "RBRACE";

    case INVALID: return "INVALID";

    default:
        return "<UNKNOWN_TOKEN>";
    }
}

static void emit_token(int tok, const char *lexeme)
{
    if (!g_emit_tokens) {
        return;
    }

    if (!lexeme) {
        lexeme = "";
    }

    fprintf(stdout, "line %-4d  %-14s  %s\n", yylineno, token_name(tok), lexeme);
}
%}

%x COMMENT

DIGIT      [0-9]
ID_START   [A-Za-z_]
ID_CONT    [A-Za-z0-9_]
IDENT_RE   {ID_START}{ID_CONT}*

INT_RE     {DIGIT}+
EXP_RE     ([eE][+-]?{INT_RE})
FLOAT_RE   (({INT_RE}\.{DIGIT}*{EXP_RE}?)|({DIGIT}*\.{INT_RE}{EXP_RE}?)|({INT_RE}{EXP_RE}))

STRING_RE  \"([^\\\n]|\\.)*\"

%%
"/*"                { BEGIN(COMMENT); }
<COMMENT>"*/"        { BEGIN(INITIAL); }
<COMMENT>\n          { /* yylineno updated by Flex */ }
<COMMENT>.           { /* ignore comment contents */ }

"//"[^\n]*          { /* ignore // comment */ }

[ \t\r\n]+           { /* ignore */ }

"=="                { emit_token(EQ, yytext); return EQ; }
"!="                { emit_token(NEQ, yytext); return NEQ; }
"<="                { emit_token(LE, yytext); return LE; }
">="                { emit_token(GE, yytext); return GE; }

"="                 { emit_token(ASSIGN, yytext); return ASSIGN; }
"<"                 { emit_token(LT, yytext); return LT; }
">"                 { emit_token(GT, yytext); return GT; }
"+"                 { emit_token(PLUS, yytext); return PLUS; }
"-"                 { emit_token(MINUS, yytext); return MINUS; }
"*"                 { emit_token(STAR, yytext); return STAR; }
"/"                 { emit_token(SLASH, yytext); return SLASH; }

";"                 { emit_token(SEMI, yytext); return SEMI; }
","                 { emit_token(COMMA, yytext); return COMMA; }
"("                 { emit_token(LPAREN, yytext); return LPAREN; }
")"                 { emit_token(RPAREN, yytext); return RPAREN; }
"{"                 { emit_token(LBRACE, yytext); return LBRACE; }
"}"                 { emit_token(RBRACE, yytext); return RBRACE; }

{STRING_RE}          {
                        yylval.sval = tinyc_strdup(yytext);
                        emit_token(STRING_LIT, yylval.sval);
                        return STRING_LIT;
                     }

{FLOAT_RE}           {
                        yylval.sval = tinyc_strdup(yytext);
                        emit_token(FLOAT_LIT, yylval.sval);
                        return FLOAT_LIT;
                     }

{INT_RE}             {
                        yylval.sval = tinyc_strdup(yytext);
                        emit_token(INT_LIT, yylval.sval);
                        return INT_LIT;
                     }

{IDENT_RE}           {
                        int tok = keyword_token(yytext);
                        if (tok != IDENT) {
                            emit_token(tok, yytext);
                            return tok;
                        }

                        yylval.sval = tinyc_strdup(yytext);
                        emit_token(IDENT, yylval.sval);
                        return IDENT;
                     }

.                    {
                        fprintf(stderr,
                                "Lexical error (line %d): unexpected character '%s'\n",
                                yylineno,
                                yytext);
                        emit_token(INVALID, yytext);
                        return INVALID;
                     }

<<EOF>>              {
                        emit_token(0, "EOF");
                        return 0;
                     }

%%
