%{
    #include<iostream>
    int lineCount = 0;
    int charCount= 0;
%}

%%
"\n"    {lineCount++;}
.       {charCount++;}
%%

int yywrap(){
    return -1;
}

int main(){
    yylex();
    lineCount += 1;
    std::cout << "\nNo. of Lines :" << lineCount;
    std::cout << "\nNo. of Characters :" << charCount - lineCount << "\n";
    return 0;
}