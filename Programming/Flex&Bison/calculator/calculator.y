%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
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

term: NUMBER { $$ = newnum($1); }
    | ABS term { $$ = newast('|', $2, NULL); }
    | OP exp CP { $$ = $2; }
    | SUB term { $$ = newast('-', newnum(0), $2); }
    ;

%%

struct ast *newast(int nodetype, struct ast *l, struct ast *r) {
    struct ast *a = malloc(sizeof(struct ast));

    if(!a) {
        yyerror("out of space");
        exit(0);
    }
    a->nodetype = nodetype;
    a->l = l;
    a->r = r;
    return a;
}

struct ast *newnum(double d) {
    struct numval *a = malloc(sizeof(struct numval));

    if(!a) {
        yyerror("out of space");
        exit(0);
    }
    a->nodetype = 'K';
    a->number = d;
    return (struct ast*) a;
}

double eval(struct ast *a) {
    double v;

    switch(a->nodetype) {
        case 'K': v = ((struct numval*)a)->number; break;

        case '+': v = eval(a->l) + eval(a->r); break;
        case '-': v = eval(a->l) - eval(a->r); break;
        case '*': v = eval(a->l) * eval(a->r); break;
        case '/': v = eval(a->l) / eval(a->r); break;

        case '|':
        if (a->r == NULL) {
            v = eval(a->l);
            if(v < 0) {
                v = -v;
            }
        } else {
            v = (int)eval(a->l) | (int)eval(a->r);
        }
        break;

        case '&': v = (int)eval(a->l) & (int)eval(a->r); break;

        default: printf("internal error: bad node %c\n", a->nodetype);
    }
    return v;
}

void treefree(struct ast* a) {
    switch(a->nodetype) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '|':
    case '&':
        if(a->l) treefree(a->l);
        if(a->r) treefree(a->r);
    case 'K':
        free(a);
        break;
    default: printf("internal error: free bad node%c\n", a->nodetype);
    }
}

void yyerror(char *s, ...) {
    va_list ap;
    va_start(ap, s);

    fprintf(stderr, "%d: error: ", yylineno);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
}

int main() {
    printf("> ");
    return yyparse();
}
