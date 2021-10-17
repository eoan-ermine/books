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

%left ABS AND
%left ADD SUB
%left MUL DIV

%nonassoc MODULO UMINUS

%%

calclist:/* nothing*/
    | calclist exp EOL {
        printf("= %4.4g\n", eval($2));
        treefree($2);
        printf("> ");
    }
    | calclist EOL { printf("> "); }
    ;

exp: exp ADD exp { $$ = newast('+', $1, $3); }
    | exp SUB exp { $$ = newast('-', $1, $3); }
    | exp ABS exp { $$ = newast('|', $1, $3); }
    | exp AND exp { $$ = newast('&', $1, $3); }
    | exp MUL exp { $$ = newast('*', $1, $3); }
    | exp DIV exp { $$ = newast('/', $1, $3); }
    | ABS exp %prec MODULO { $$ = newast('|', $2, NULL); }
    | SUB exp %prec UMINUS { $$ = newast('-', newnum(0), $2); }
    | OP exp CP { $$ = $2; }
    | NUMBER { $$ = newnum($1); }
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
