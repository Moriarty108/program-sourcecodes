#include <iostream>
#include "DFS.hpp"

int main(int argc, char const *argv[])
{
    DFS dfs(9);
    dfs.addEdge(0, 1);
    dfs.addEdge(0, 4);
    dfs.addEdge(1, 2);
    dfs.addEdge(2, 5);
    dfs.addEdge(1, 4);
    dfs.addEdge(0, 3);
    dfs.addEdge(3, 6);
    dfs.addEdge(6, 7);
    dfs.addEdge(7, 8);
    dfs.addEdge(4, 6);

    dfs.traverseFrom(0);
    return 0;
}