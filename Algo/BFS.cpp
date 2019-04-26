#include "BFS.hpp"
#include <queue>
#include <iostream>

BFS::BFS(int vertices)
{
    this->vertices = vertices;
    adjList = new std::list<int>[this->vertices];
    explored = new bool[this->vertices];
}

BFS::~BFS()
{
    delete[] adjList;
    delete[] explored;
}

void BFS::addEdge(int vertex1, int vertex2)
{
    adjList[vertex1].push_back(vertex2);
    adjList[vertex2].push_back(vertex1);
}

void BFS::traverseFrom(int vertex)
{
    explored[vertex] = true;
    std::queue<int> q;
    q.push(vertex);

    while (!q.empty())
    {
        int temp = q.front();
        std::cout << temp << " ";
        q.pop();
        for (std::list<int>::iterator iter = adjList[temp].begin(); iter != adjList[temp].end(); iter++)
        {
            if (!explored[*iter])
            {
                explored[*iter] = true;
                q.push(*iter);
            }
        }
    }
}