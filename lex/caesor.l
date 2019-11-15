%{
    #include <iostream>
    void shift(char *text);
%}

%%

" " {std::cout << " ";}
.   {shift(yytext);std::cout << yytext[0];}

%%

void shift(char *text){
    text[0] += 3;
    if(text[0] > 122 && text[0] < 126){
        text[0] = 97 + (text[0] - 122);
    }
    else if(text[0] > 90 && text[0] < 94){
        text[0] = 65 + (text[0] - 90);
    }
}

int yywrap(){
    return 1;
}

int main(){
    yylex();
}