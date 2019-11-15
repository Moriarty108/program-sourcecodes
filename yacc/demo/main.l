%{
    #include <iostream>
    #include <string.h>
    #include "y.tab.h"
    char* buffer = new char[40];
%}

%%

"let "                         {return let_command;}
"print "                       {return print_command;}
"exit"                        {return exit_command;}
[a-zA-Z_][a-zA-Z0-9_]*       {strcpy(buffer,yytext);  yylval.identifier = buffer; return id;}
[0-9]+(\.[0-9]+)?            {yylval.number = atof(yytext); return num;}
" "                         {return -1;}                   
.                           {return yytext[0];}
\n                          {return 0;}

%%

int yywrap(){
    return 1;
}