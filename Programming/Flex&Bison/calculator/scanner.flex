%{
    #include "calculator.tab.h"
%}

%%
"+"     { return ADD; }
"-"     { return SUB; }
"*"     { return MUL; }
"/"     { return DIV; }
"|"     { return ABS; }
[0-9]+  { yylval = atoi(yytext); return NUMBER; }

"("     { return OP; }
")"     { return CP; }

"//".*  { }

\n      { return EOL; }
[ \t]   { }
.       { printf("Mystery character %c\n", *yytext); }
%%
