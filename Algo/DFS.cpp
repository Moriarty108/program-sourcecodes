#include "DFS.hpp"
#include <iostream>

DFS::DFS(int vertices)
{
    this->vertices = vertices;
    adjList = new std::list<int>[this->vertices];
    explored = new bool[this->vertices];
}

DFS::~DFS()
{
    delete[] adjList;
    delete[] explored;
}

void DFS::addEdge(int vertex1, int vertex2)
{
    adjList[vertex1].push_back(vertex2);
    adjList[vertex2].push_back(vertex1);
}

void DFS::traverseFrom(int vertex)
{
    explored[vertex] = true;
    std::cout << vertex << " ";
    for (std::list<int>::iterator iter = adjList[vertex].begin(); iter != adjList[vertex].end(); iter++)
    {
        if (!explored[*iter])
        {
            traverseFrom(*iter);
        }
    }
}
