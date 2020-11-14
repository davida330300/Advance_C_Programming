#include "Graph.h"
#include "iostream"
#include "vector"
#include "list"
#include "queue"

using namespace std;

void Graph::BFS(int start){
    color = new int[num_vertex];
    distance = new int[num_vertex];
    predecessor = new int[num_vertex];

    for(int i =0;i<num_vertex;i++){
        color[i] = 0;
        distance[i] = 0;
        predecessor[i] = -1;
    }

    queue<int>  q;
    int i = start;

    for(int j = 0;j<num_vertex;j++){
        if(color[i]==0){
            q.push(i);
            color[i] = 1;
            while(!q.empty()){
                int u = q.front();
                for(list<int>::iterator itr = AdjList[u].begin();itr != AdjList[u].end();itr++){
                    if(color[*itr] ==0){
                        color[*itr] = 1;
                        distance[*itr] = distance[u]+1;
                        predecessor[*itr] = u;

                        q.push(*itr);
                    }
                }
                q.pop();
                color[u] = 2;
            }
            
        }
        i = j;//
    }
    delete [] color;
    delete [] distance;
    delete [] predecessor;
}
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