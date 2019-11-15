%{
    #include <iostream>
    bool found = false;
%}

id [a-zA-Z_][a-zA-Z0-9_]*
ws (" ")
number (-)?[0-9]+(\.[0-9]+)?
relop ("<=")|(">=")|("!=")|("==")
op    \+|-|\*|\/

%%
for\((int){ws}{id}{ws}?"="{ws}?{number}";"{id}{ws}?{relop}{ws}?{number}";"{id}("++"|"--")\)(\{(.)*\}|";")   {found = true; return 0;}
.         {}
\n        {if(!found) std::cout << "\nFor Loop Not Found\n"; return 1;}
%%

int yywrap(){
    return 1;
}

int main(){
    yylex();
    if(found) std::cout << "\nFor Loop Found\n";
    // else std::cout << "\nFor Loop Not Found\n";
    return 0;
}