%{
    #include <iostream>    
%}

%%

(int)|(float)|(double)|(bool)|(for)|(while)|(do)|(extern)|(return)  {std::cout << "\nKeyword :" << yytext << "\n";}
!|\+|-|\*|\/|=|%|\?|<|>     {std::cout << "Operator :" << yytext << "\n";}
\/\/(.)*                       {std::cout << "Comment: " << yytext << "\n";}
(#include(" ")?<[a-zA-Z]+(\.h)?>) {}
(\*)?[a-zA-Z_][a-zA-Z0-9_]+  {std::cout << "Idenitifier :" << yytext << "\n";}
.                              {}

%%

int yywrap(){
    return 1;
}

int main(){
    yylex();
    return 0;
}