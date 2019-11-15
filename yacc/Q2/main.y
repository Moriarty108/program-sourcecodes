%{
    #include <iostream>
    int yyerror(char*);
    extern int yylex();
%}

%union {float f;}
%start line
%token <f> num
%type <f> exp rec
%% 

line : exp              {std::cout << "\n" << $1 << "\n";}
    ;

exp : num '+' rec       {$$ = $1 + $3;}
    | num '-' rec       {$$ = $1 - $3;}
    | num '*' rec       {$$ = $1 * $3;}
    | num '/' rec       {$$ = $1 / $3;}
    ;
rec : num               {$$ = $1;}
    | num '+' rec       {$$ = $1 + $3;}
    | num '-' rec       {$$ = $1 - $3;}
    | num '*' rec       {$$ = $1 * $3;}
    | num '/' rec       {$$ = $1 / $3;}
    ;
%%

int yyerror(char *msg){
    std::cout << msg;
    return 1;
}

int main(){
    std::cout << "\nEnter Expression : ";
    yyparse();
    return 0;
}