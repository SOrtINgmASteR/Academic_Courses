%{
#include <stdio.h>
int line = 1;
%}

%%
"//".*   { printf("%d\t%s\tsingle line comment\n", line, yytext); }

"/*"([^*]|\*+[^*/])*"*/"   { printf("%d\t%s\tmulti line comment\n", line, yytext); }

"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"   { printf("%d\t%s\tkeyword\n", line, yytext); }

[0-9]+(\.[0-9]+)?   { printf("%d\t%s\tconstnt\n", line, yytext); }

[a-zA-Z_][a-zA-Z0-9_]*   { printf("%d\t%s\tidentifire\n", line, yytext); }

"=="|"!="|"<="|">="|"&&"|"||"   { printf("%d\t%s\topertor(Logical)\n", line, yytext); }

"+"|"-"|"*"|"/"|"="|"+="|"-="|"*="|"/="|"++"|"--"   { printf("%d\t%s\topertor(Arithmtic)\n", line, yytext); }

";"|","   { printf("%d\t%s\tpunctuation\n", line, yytext); }

[()\[\]{}]   { printf("%d\t%s\tprenthesis\n", line, yytext); }


\n   { line++; }

[ \t\r]+   { }

.   { printf("%d\t%s\tunknown\n", line, yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    FILE *fp = fopen("input.c", "r");
    if (!fp) {
        printf("File not found\n");
        return 1;
    }

    yyin = fp;
    yylex();

    fclose(fp);
    return 0;
}
