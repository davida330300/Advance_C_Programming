#ifndef Graph_h
#define Graph_h
#include "iostream"
#include "vector"
#include "list"

#include "Graph.h"

using namespace std;

class Graph
{
private:
    int num_vertex;
    vector<list<int>> AdjList;
    int *color, *distance, *predecessor, *discover, *finish;

public:
    Graph() : num_vertex(0){};
    Graph(int N) : num_vertex(N) { AdjList.resize(num_vertex); }
    void AddEdgeList(int from, int to)
    {
        AdjList[from].push_back(to);
    }
    void BFS(int start);
    void DFS(int start);
    void DFSVisit(int vertex, int &time);
};
#endif
