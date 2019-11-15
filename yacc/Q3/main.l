%{
    #include "y.tab.h"    
%}

%%

a       {return charA;}
b       {return charB;}
.       {return yytext[0];}
\n      {return 0;}

%%

int yywrap(){
    return 1;
}