#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

/*
 * TinyC Symbol Table
 *
 * Stores declared variables with their datatype and scope level.
 * Used by the parser to insert identifiers during declarations and to detect
 * duplicates within the same scope.
 */

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

void symtab_init(void);
void symtab_free(void);

void symtab_enter_scope(void);
void symtab_leave_scope(void);
int symtab_current_scope(void);

/* Returns 1 on success, 0 if duplicate in current scope. */
int symtab_insert(const char *name, const char *type, int line);

/* Returns 1 if `name` is declared in the current scope; otherwise 0. */
int symtab_is_declared_in_current_scope(const char *name);

void symtab_print(FILE *out);

#ifdef __cplusplus
}
#endif

#endif /* SYMBOL_TABLE_H */
