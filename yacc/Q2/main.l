%{
    #include <stdlib.h>
    #include "y.tab.h"
%}

%%

[0-9]+(\.[0-9]+)?  {yylval.f = atof(yytext); return num;}
.                   {return yytext[0];}
\n                  {return 0;}

%%

int yywrap(){
    return 1;
}