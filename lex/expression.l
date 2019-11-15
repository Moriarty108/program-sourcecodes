%{
    #include <iostream>
%}

%%

((([a-zA-Z_][a-zA-Z0-9_]*)|([0-9]+))(" = "))?(([0-9]+)|([a-zA-Z_][a-zA-Z0-9_]*))(" ")?((\+)|(\*)|(-)|(\/)|(%))(" ")?(([0-9]+)|([a-zA-Z_][a-zA-Z0-9_]*))  {std::cout << "\n--> Valid Expression\n"; return 0;}
.  {std::cout << "\n--> Invalid Expression\n"; return -1;}

%%

int yywrap(){
    return 1;
}

int main(){
    std::cout << "\nEnter Expression : ";
    yylex();
}