%{
    #include "calculator.tab.h"
%}

%%
"+"     { return ADD; }
"-"     { return SUB; }
"*"     { return MUL; }
"/"     { return DIV; }

"|"     { return ABS; }
"&"     { return AND; }

[0-9]+          { yylval = atoi(yytext); return NUMBER; }
0x[a-f0-9]+     { yylval = strtol(yytext, NULL, 16); return NUMBER; }

"("     { return OP; }
")"     { return CP; }

"//".*  { }

\n      { return EOL; }
[ \t]   { }
.       { printf("Mystery character %c\n", *yytext); }
%%
