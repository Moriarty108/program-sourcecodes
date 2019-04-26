#ifndef __DFS_H__
#define __DFS_H__

#include <list>
class DFS
{
    int vertices;
    std::list<int> *adjList;
    bool *explored;

  public:
    DFS(int vertices);
    ~DFS();
    void addEdge(int vertex1, int vertex2);
    void traverseFrom(int vertex);
};

#endif