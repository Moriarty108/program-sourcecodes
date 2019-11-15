%{
    #include <iostream>
    #include <string.h>
    bool isPalindrome(char*);

%}

%%

(.)+     {if(isPalindrome(yytext)) std::cout << "\nPalindrome!\n"; else std::cout << "\nNot Palindrome!\n"; return 0;}

%%

bool isPalindrome(char* text){
    int len = strlen(text);
    int j = len - 1;
    bool isP = true;
    for(int i = 0; i < len / 2; i++){
        if(text[i] != text[j])
        {
            isP = false;
            break;
        }
        j--;
    }
    return isP;
}

int yywrap(){
    return 1;
}

int main(){
    yylex();
    return 0;
}