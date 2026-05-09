#include "symbol_table.h"

#include <stdlib.h>
#include <string.h>

typedef struct Symbol {
    char *name;
    char *type;
    int scope;
    int line;
    struct Symbol *next;
} Symbol;

static Symbol *g_head = NULL;
static Symbol *g_tail = NULL;
static int g_scope = 0;

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

void symtab_init(void)
{
    g_head = NULL;
    g_tail = NULL;
    g_scope = 0;
}

void symtab_free(void)
{
    Symbol *cur = g_head;
    while (cur) {
        Symbol *next = cur->next;
        free(cur->name);
        free(cur->type);
        free(cur);
        cur = next;
    }
    g_head = NULL;
    g_tail = NULL;
    g_scope = 0;
}

void symtab_enter_scope(void)
{
    g_scope++;
}

void symtab_leave_scope(void)
{
    if (g_scope > 0) {
        g_scope--;
    }
}

int symtab_current_scope(void)
{
    return g_scope;
}

int symtab_is_declared_in_current_scope(const char *name)
{
    if (!name) {
        return 0;
    }

    for (Symbol *cur = g_head; cur; cur = cur->next) {
        if (cur->scope == g_scope && strcmp(cur->name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

int symtab_insert(const char *name, const char *type, int line)
{
    if (!name || !type) {
        return 0;
    }

    if (symtab_is_declared_in_current_scope(name)) {
        return 0;
    }

    Symbol *sym = (Symbol *)calloc(1, sizeof(Symbol));
    if (!sym) {
        fprintf(stderr, "fatal: out of memory while inserting symbol\n");
        exit(2);
    }

    sym->name = xstrdup(name);
    sym->type = xstrdup(type);
    sym->scope = g_scope;
    sym->line = line;
    sym->next = NULL;

    if (!g_head) {
        g_head = sym;
        g_tail = sym;
    } else {
        g_tail->next = sym;
        g_tail = sym;
    }

    return 1;
}

void symtab_print(FILE *out)
{
    if (!out) {
        out = stdout;
    }

    fputs("\nSymbol Table\n", out);
    fputs("-------------------------------\n", out);
    fprintf(out, "%-20s %-10s %-5s %-5s\n", "Name", "Type", "Scope", "Line");
    fputs("-------------------------------\n", out);

    for (Symbol *cur = g_head; cur; cur = cur->next) {
        fprintf(out, "%-20s %-10s %-5d %-5d\n", cur->name, cur->type, cur->scope, cur->line);
    }
}
