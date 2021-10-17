%{
    #include "calculator.h"
    #include "calculator.tab.h"
%}

EXP ([Ee][-+]?[0-9]+)

%%
"+"     { return ADD; }
"-"     { return SUB; }
"*"     { return MUL; }
"/"     { return DIV; }

"|"     { return ABS; }
"&"     { return AND; }

[0-9]+"."[0-9]*{EXP}? |
    "."?[0-9]+{EXP}? { yylval.d = atof(yytext); return NUMBER; }
0x[a-f0-9]+     { yylval.d = strtol(yytext, NULL, 16); return NUMBER; }

"("     { return OP; }
")"     { return CP; }

"//".*  { }

\n      { return EOL; }
[ \t]   { }
.       { printf("Mystery character %c\n", *yytext); }
%%
