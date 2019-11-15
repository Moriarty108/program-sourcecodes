%{
    #include <iostream>
    void printPattern(char* text);
%}

%%

(.)+ {printPattern(yytext);}

%%

void printPattern(char* text){
    int len = yyleng;
    std::cout << "\nPattern :\n";
    for(int i = 0 ; i < len; i++){
        for(int j = 0; j < len - i; j++)
        std::cout << text[j];
        std::cout << "\n";
    }
}

int yywrap(){
    return 1;
}

int main(){
    yylex();
    return 0;
}