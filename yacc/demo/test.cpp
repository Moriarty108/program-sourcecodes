#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, char> example;
    example.insert_or_assign(std::string("one"), 'a');
    example.insert_or_assign(std::string("one"), 'v');

    auto search = example.find(std::string("one"));
    if (search != example.end())
        std::cout << "Found " << search->first << " " << search->second << '\n';
}