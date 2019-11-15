#include <iostream>
#include <unordered_map>
#include <string>
#include <string.h>

extern int yylex();
extern int yyparse();
extern int yyerror(char *msg);
extern std::unordered_map<std::string, float> sym_tab;

void assign(const char *var_name, float value)
{
    sym_tab.insert_or_assign(std::string(var_name), value);
}

float getValue(const char *var_name)
{
    auto search = sym_tab.find(std::string(var_name));
    if (search != sym_tab.end())
    {
        return search->second;
    }
    else
    {
        char *err_msg = new char[40];
        strcat(err_msg, var_name);
        strcat(err_msg, " undefined");
        int err_status = yyerror(err_msg);
        delete[] err_msg;
        return err_status;
    }
}

int main()
{
    sym_tab.insert_or_assign("null", -11);
    while (true)
    {
        std::cout << "\n--> ";
        yyparse();
    }
    return 0;
}