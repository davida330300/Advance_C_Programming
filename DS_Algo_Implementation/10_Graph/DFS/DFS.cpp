#include "iostream"
#include "vector"
#include "list"
#include "queue"
#include "iomanip"
using namespace std;

class Graph{
    private:
    public:
        int num_vertex;
        vector<list<int>> AdjList;
        int *color, *predecessor,*discover, *finish;

        Graph():num_vertex(0){};
        Graph(int N):num_vertex(N){AdjList.resize(num_vertex);};
        void AddEdgeList(int from,int to);
        void DFS(int start);
        void DFSVisit(int vertex, int &time);
};

void Graph::DFS(int start){
    color = new int{num_vertex};
    discover = new int[num_vertex];
    finish = new int[num_vertex];
    predecessor = new int[num_vertex];

    int time = 0;
    for(int i =0;i<num_vertex;i++){
        color[i] = 0;
        discover[i] = 0;
        finish[i] = 0;
        predecessor[i] = -1;
    }

    int i = start;
    for(int j = 0;j< num_vertex;j++){
        if(color[i]==0){
            DFSVisit(i, time);
        }
        i=j;
    }
}
void Graph::DFSVisit(int vertex, int &time){
    color[vertex]=1;
    discover[vertex] = ++time;
    for(list<int>::iterator itr = AdjList[vertex].begin();itr!=AdjList[vertex].end();itr++){
        if(color[*itr] ==0){
            predecessor[*itr] = vertex;
            DFSVisit(*itr, time);
        }
    }
    color[vertex] = 2;
    finish[vertex] = ++time;
}
void Graph::AddEdgeList(int from, int to){
    AdjList[from].push_back(to);
}

int main(){
    // 定義一個具有八個vertex的Graph
    Graph g2(8);
    // 建立如圖三之Graph
    g2.AddEdgeList(0, 1);g2.AddEdgeList(0, 2); 
    g2.AddEdgeList(1, 3);
    g2.AddEdgeList(2, 1);g2.AddEdgeList(2, 5);
    g2.AddEdgeList(3, 4);g2.AddEdgeList(3, 5);
    // AdjList[4] is empty
    g2.AddEdgeList(5, 1);
    g2.AddEdgeList(6, 4);g2.AddEdgeList(6, 7);
    g2.AddEdgeList(7, 6);

    g2.DFS(0);    // 以vertex(0), 也就是vertex(A作為DFS()的起點

    system("pause");
    return 0;
}