%{
    #include <iostream>
    int yyerror(char*);
    extern int yylex();
    int valid = 0;
%}

%start line
%token number
%token id
%token op

%%

line : id A
    | number A
    ;
A : op id A
    | op number A
    | op id
    | op number
    ;
%%

int yyerror(char* msg){
    std::cout << msg;
    return 1;
}

int main(){
    std::cout << "\nEnter an Expression : ";
    return yyparse();
}