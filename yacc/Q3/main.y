%{
    #include <iostream>
    extern int yylex();
    int yyerror(char* msg);
    bool valid = true;
    int a_count = 0;
    int b_count = 0;
%}

%start str
%token charA
%token charB

%%

str : A B
    ;
A : charA A         {a_count++;}
    | charA         {a_count++;}
    ;
B : charB B         {b_count++;}
    | charB         {b_count++;}
    ;
%%

int yyerror(char* msg){
    valid = false;
    std::cout <<"--> Incorrect Input\n";
    return 1;
}

int main(){
    std::cout << "\nEnter a String : ";
    yyparse();
    if(valid){
        if(a_count == b_count)
            std::cout<< "--> Correct Input\n";
        else 
            std::cout << "--> Incorrect Input\n";
    }
    return 0;
}
