#ifndef __BFS_H__
#define __BFS_H__

#include <list>

class BFS
{
    int vertices;
    std::list<int> *adjList;
    bool *explored;

  public:
    BFS(int vertices);
    ~BFS();
    void addEdge(int vertex1, int vertex2);
    void traverseFrom(int vertex);
};

#endif