%{
    #include <iostream>
    #include <stdlib.h>
    #include <string>
    #include <string.h>
    #include <unordered_map>
    std::unordered_map<std::string, float> sym_tab;
    int yyerror(char *msg);
    extern int yylex();
    extern float getValue(const char*);
    extern void assign(const char*,float);
%}

%union {char* identifier; float number;}
%start line
%token <identifier> id
%token <number> num
%token let_command
%token print_command
%token exit_command
%type <number> exp
%type <identifier> assignment
%%

line : assignment ';'                   {;}
    | print_command id ';'          {std::cout << getValue($2) << "\n";}
    | print_command num ';'         {std::cout << $2;}
    | exit_command ';'                  {exit(0);}
    | let_command assignment ';'    {;}
    ;

assignment : id '=' assignment      {assign($1,getValue($3));}
            | id '=' exp            {assign($1,$3);}
            ;

exp :  exp '+' id                   {$$ = $1 + getValue($3);}
      | exp '+' num                 {$$ = $1 + $3;}
      | exp '-' id                  {$$ = $1 + getValue($3);}
      | exp '-' num                 {$$ = $1 - $3;}
      | exp '*' id                  {$$ = $1 * getValue($3);}
      | exp '*' num                 {$$ = $1 * $3;}
      | exp '/' id                  {$$ = $1 / getValue($3);}
      | exp '/' num                 {$$ = $1 / $3;}
      | id                          {$$ = getValue($1);}
      | num                         {$$ = $1;}
      ;
%%

int yyerror(char *msg){
    std::cout << msg;
    return 1;
}