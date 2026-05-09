/*
 * TinyC Parser (Bison)
 *
 * Parses a minimal C-like language:
 * - Single function definition (e.g., int main() { ... })
 * - Variable declarations
 * - Assignment statements
 * - Arithmetic and relational expressions
 * - if-else and while statements
 * - return statements
 * - print(...) built-in statement
 *
 * Builds an AST (parse tree) and integrates with the symbol table:
 * - Inserts identifiers during declaration parsing
 * - Detects duplicate declarations in the same scope
 */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "symbol_table.h"

extern int yylex(void);
extern int yylineno;

void yyerror(const char *msg);

AstNode *g_root = NULL;

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
%}

/* Ensure the generated header can compile without including ast.h */
%code requires {
    typedef struct AstNode AstNode;
}

%union {
    char *sval;
    AstNode *node;
}

%define parse.error verbose

/* C89 keywords (32). Lexer recognizes all of them.
 * Grammar uses only a subset (int/float/if/else/while/return), but we keep
 * the full token list for completeness.
 */
%token AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN
%token FLOAT FOR GOTO IF INT LONG REGISTER RETURN SHORT SIGNED SIZEOF STATIC
%token STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE

/* TinyC built-in */
%token PRINT

/* Identifiers and literals */
%token <sval> IDENT
%token <sval> INT_LIT FLOAT_LIT STRING_LIT

/* Operators */
%token PLUS MINUS STAR SLASH
%token ASSIGN
%token EQ NEQ LT GT LE GE

/* Separators */
%token SEMI COMMA LPAREN RPAREN LBRACE RBRACE

/* Any unexpected/invalid character surfaced by the lexer */
%token INVALID

%type <node> program function compound_stmt stmt stmt_list stmt_list_opt
%type <node> decl assignment if_stmt while_stmt return_stmt print_stmt
%type <node> expr
%type <node> id_list
%type <sval> type_spec

%start program

/* Precedence and associativity */
%left EQ NEQ LT GT LE GE
%left PLUS MINUS
%left STAR SLASH
%right UMINUS

/* Resolve dangling-else */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

program
    : function
      {
          g_root = ast_make_program($1, yylineno);
          $$ = g_root;
      }
    ;

function
    : type_spec IDENT LPAREN RPAREN compound_stmt
      {
          AstNode *type_node = ast_make_type($1, yylineno); /* owns $1 */
          $$ = ast_make_function($2, type_node, $5, yylineno); /* owns $2 */
      }
    ;

compound_stmt
    : LBRACE
      {
          /* New block scope */
          symtab_enter_scope();
      }
      stmt_list_opt
      RBRACE
      {
          symtab_leave_scope();
          $$ = ast_make_block($3, yylineno);
      }
    ;

stmt_list_opt
    : /* empty */
      {
          $$ = NULL;
      }
    | stmt_list
      {
          $$ = $1;
      }
    ;

stmt_list
    : stmt_list stmt
      {
          $$ = ast_list_append($1, $2);
      }
    | stmt
      {
          $$ = $1;
      }
    ;

stmt
    : decl
      {
          $$ = $1;
      }
    | assignment
      {
          $$ = $1;
      }
    | if_stmt
      {
          $$ = $1;
      }
    | while_stmt
      {
          $$ = $1;
      }
    | return_stmt
      {
          $$ = $1;
      }
    | print_stmt
      {
          $$ = $1;
      }
    | compound_stmt
      {
          $$ = $1;
      }
    ;

/* Declarations: e.g., int a, b; */
decl
    : type_spec id_list SEMI
      {
          /* Insert each identifier into the symbol table. */
          for (AstNode *id = $2; id; id = id->next) {
              if (!symtab_insert(id->text, $1, id->line)) {
                  fprintf(stderr,
                          "Semantic error (line %d): duplicate declaration of '%s' in scope %d\n",
                          id->line,
                          id->text,
                          symtab_current_scope());
              }
          }

          $$ = ast_make_decl($1, $2, yylineno); /* owns $1 */
      }
    ;

id_list
    : IDENT
      {
          $$ = ast_make_identifier($1, yylineno); /* owns $1 */
      }
    | id_list COMMA IDENT
      {
          AstNode *node = ast_make_identifier($3, yylineno); /* owns $3 */
          $$ = ast_list_append($1, node);
      }
    ;

assignment
    : IDENT ASSIGN expr SEMI
      {
          AstNode *id = ast_make_identifier($1, yylineno); /* owns $1 */
          $$ = ast_make_assign(id, $3, yylineno);
      }
    ;

if_stmt
    : IF LPAREN expr RPAREN stmt %prec LOWER_THAN_ELSE
      {
          $$ = ast_make_if($3, $5, NULL, yylineno);
      }
    | IF LPAREN expr RPAREN stmt ELSE stmt
      {
          $$ = ast_make_if($3, $5, $7, yylineno);
      }
    ;

while_stmt
    : WHILE LPAREN expr RPAREN stmt
      {
          $$ = ast_make_while($3, $5, yylineno);
      }
    ;

return_stmt
    : RETURN SEMI
      {
          $$ = ast_make_return(NULL, yylineno);
      }
    | RETURN expr SEMI
      {
          $$ = ast_make_return($2, yylineno);
      }
    ;

print_stmt
    : PRINT LPAREN expr RPAREN SEMI
      {
          $$ = ast_make_print($3, yylineno);
      }
    | PRINT LPAREN STRING_LIT RPAREN SEMI
      {
          AstNode *s = ast_make_string_literal($3, yylineno); /* owns $3 */
          $$ = ast_make_print(s, yylineno);
      }
    ;

/* Only support int/float types for now (easy to extend). */
type_spec
    : INT
      {
      $$ = tinyc_strdup("int");
      }
    | FLOAT
      {
      $$ = tinyc_strdup("float");
      }
    ;

expr
    : expr PLUS expr
      {
          $$ = ast_make_binop("+", $1, $3, yylineno);
      }
    | expr MINUS expr
      {
          $$ = ast_make_binop("-", $1, $3, yylineno);
      }
    | expr STAR expr
      {
          $$ = ast_make_binop("*", $1, $3, yylineno);
      }
    | expr SLASH expr
      {
          $$ = ast_make_binop("/", $1, $3, yylineno);
      }

    | expr EQ expr
      {
          $$ = ast_make_binop("==", $1, $3, yylineno);
      }
    | expr NEQ expr
      {
          $$ = ast_make_binop("!=", $1, $3, yylineno);
      }
    | expr LT expr
      {
          $$ = ast_make_binop("<", $1, $3, yylineno);
      }
    | expr GT expr
      {
          $$ = ast_make_binop(">", $1, $3, yylineno);
      }
    | expr LE expr
      {
          $$ = ast_make_binop("<=", $1, $3, yylineno);
      }
    | expr GE expr
      {
          $$ = ast_make_binop(">=", $1, $3, yylineno);
      }

    | MINUS expr %prec UMINUS
      {
          /* Represent unary minus as 0 - expr for simplicity. */
          AstNode *zero = ast_make_int_literal(tinyc_strdup("0"), yylineno);
          $$ = ast_make_binop("-", zero, $2, yylineno);
      }

    | LPAREN expr RPAREN
      {
          $$ = $2;
      }
    | IDENT
      {
          $$ = ast_make_identifier($1, yylineno); /* owns $1 */
      }
    | INT_LIT
      {
          $$ = ast_make_int_literal($1, yylineno); /* owns $1 */
      }
    | FLOAT_LIT
      {
          $$ = ast_make_float_literal($1, yylineno); /* owns $1 */
      }
    ;

%%

void yyerror(const char *msg)
{
    fprintf(stderr, "Parse error (line %d): %s\n", yylineno, msg);
}
