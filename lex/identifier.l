%{
    #include <iostream>
    int id = 0;
%}
%%

(int)|(float)|(double)|(bool)|(for)|(while)|(do)|(extern)|(return)|(char)|(const) {}
(#include(" ")?<[a-zA-Z]+(\.)?(h)?>) {}
\/\/(.)* {}
[a-zA-Z_][a-zA-Z0-9_]+\( {}
((\*)?[a-zA-Z_][a-zA-Z0-9_]+) {id++; std::cout << "\nIdentifier :" << yytext << " ";}
. {}
%%

int yywrap(){
    return 1;
}

int main(){
    yylex();
    std::cout << "\n Number of Identifiers :" << id << "\n";
    return 0;
}