%{
    #include "y.tab.h"
%}

%%

[a-z][a-z0-9_]* {return id;}
[0-9]+          {return number;}
[\+\-\*\/]       {return op;}
.               {return yytext[0];}
\n              {return 0;}
%%

int yywrap(){
    return 1;
}