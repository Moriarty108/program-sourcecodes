%{
    #include <iostream>
    
    int words = 0;
    int chars = 0;
    int ws = 0;
    int lines = 0;
%}

%%

" " {ws++;}
\n {lines++;}
[a-zA-Z]+ {words++; chars+=yyleng; std::cout << "\nWord :" << yytext << " ";}
. {chars++;} 


%%

int yywrap(){
    return 1;
}

int main(){
    yylex();

    std::cout << "\n Number of Whitespaces : " << ws;
    std::cout << "\n Number of Lines : " << lines;
    std::cout << "\n Number of Words : " << words;
    std::cout << "\n Number of Characters : " << chars << "\n";

    return 0;
}