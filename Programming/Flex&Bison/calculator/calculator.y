%{
#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
%}

%union {
    struct ast *a;
    double d;
}

%token <d> NUMBER

%token ADD SUB MUL DIV
%token ABS AND

%token OP CP
%token EOL COMMENT

%type <a> exp factor term

%%

calclist:/* nothing*/
    | calclist exp EOL {
        printf("= %4.4g\n", eval($2));
        treefree($2);
        printf("> ");
    }
    | calclist EOL { printf("> "); }
    ;

exp: factor
    | exp ADD factor { $$ = newast('+', $1, $3); }
    | exp SUB factor { $$ = newast('-', $1, $3); }
    | exp ABS factor { $$ = newast('|', $1, $3); }
    | exp AND factor { $$ = newast('&', $1, $3); }
    ;

factor: term
    | factor MUL term { $$ = newast('*', $1, $3); }
    | factor DIV term { $$ = newast('/', $1, $3); }
    ;

term: NUMBER
    | ABS term { $$ = newast('|', $2, NULL); }
    | OP exp CP { $$ = $2; }
    | SUB term { $$ = newast('-', 0, $2); }
    ;

%%

main(int argc, char **argv) {
    yyparse();
}

yyerror(char *s) {
    fprintf(stderr, "error: %s\n", s);
}
