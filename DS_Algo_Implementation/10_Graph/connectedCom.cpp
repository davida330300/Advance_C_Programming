#include "iostream"
#include "vector"
#include "list"
#include "queue"
#include "iomanip"

#include "Graph.h"

using namespace std;
class Connect
{

public:
    int num_vertex;
    vector<list<int>> AdjList;
    int *color, *distance, *predecessor, *discover, *finish;
    Graph G;

    Connect() : num_vertex(0){};
    Connect(int N) : num_vertex(N) { AdjList.resize(num_vertex); };

    void CCDFS(int vertex); // 利用DFS
    void CCBFS(int vertex); // 利用BFS, 兩者邏輯完全相同
    void SetCollapsing(int vertex);
    void PrintPredecessor();
};
void Connect::CCDFS(int vertex)
{
    G.DFS(vertex);
    Connect::PrintPredecessor();

    for (int i = 0; i < num_vertex; i++)
    {
        Connect::SetCollapsing(i);
    }
    Connect::PrintPredecessor();

    int num_cc = 0;
    for (int i = 0; i < num_vertex; i++)
    {
        if (predecessor[i] < 0)
        {
            cout << "Component#" << ++num_cc << ":" << i << " ";
            for (int j = 0; j < num_vertex; j++)
            {
                if (predecessor[j] == i)
                {
                    cout << j << " ";
                }
            }
        }
    }
}
void Connect::CCBFS(int vertex = 0)
{
    G.BFS(vertex);
    Connect::PrintPredecessor();

    for (int i = 0; i < num_vertex; i++)
    {
        Connect::SetCollapsing(i);
    }
    Connect::PrintPredecessor();

    int num_cc = 0;
    for (int i = 0; i < num_vertex; i++)
    {
        if (predecessor[i] < 0)
        {
            cout << "Component#" << ++num_cc << ":" << i << " ";
            for (int j = 0; j < num_vertex; j++)
            {
                if (predecessor[j] == i)
                {
                    cout << j << " ";
                }
            }
        }
    }
}
void Connect::SetCollapsing(int current)
{
    int root; // root
    for (root = current; predecessor[root] >= 0; root = predecessor[root])
        ;

    while (current != root)
    {
        int parent = predecessor[current];
        predecessor[current] = root;
        current = parent;
    }
}
void Connect::PrintPredecessor()
{
    cout << "predecessor:" << endl;
    for (int i = 0; i < num_vertex; i++)
        cout << setw(4) << i;
    cout << endl;
    for (int i = 0; i < num_vertex; i++)
        cout << setw(4) << predecessor[i];
    cout << endl;
}
int main()
{
    Connect g3(9);
    g3.G.AddEdgeList(0, 1);
    g3.G.AddEdgeList(1, 0);
    g3.G.AddEdgeList(1, 4);
    g3.G.AddEdgeList(1, 5);
    // AdjList[2] empty
    g3.G.AddEdgeList(3, 6);
    g3.G.AddEdgeList(4, 1);
    g3.G.AddEdgeList(4, 5);
    g3.G.AddEdgeList(5, 1);
    g3.G.AddEdgeList(5, 4);
    g3.G.AddEdgeList(5, 7);
    g3.G.AddEdgeList(6, 3);
    g3.G.AddEdgeList(6, 8);
    g3.G.AddEdgeList(7, 5);
    g3.G.AddEdgeList(8, 6);

    g3.PrintPredecessor();
    g3.CCDFS(0);
    std::cout << std::endl;
    g3.CCBFS(0);
    std::cout << std::endl;

    system("pause");
    return 0;
}