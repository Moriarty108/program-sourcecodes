%{
    #include<iostream>
    #include<string.h>
    int max = 0;
    char *longest = new char[20];
%}

%%
" " {}
[a-zA-Z]+ {if(max < yyleng) {max = yyleng; strcpy(longest,yytext);}}
%%

int yywrap(){
    return 1;
}

int main(){
    yylex();
    std::cout << "\nLongest Word  : " << longest << "\n";
    delete[] longest;
    return 0;
}