//Code for cycle detection using Topological sorting
#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
bool isCycleDetected(int V,unordered_map<int,vector<int>> &adjList){
    vector<int> indegree(V,0);
    for (int i=0;i<V;i++){
        for (auto v:adjList[i]){
            indegree[v]++;
        }
    }
    queue<int> q;
    for (int i=0;i<V;i++){
        if (indegree[i]==0) q.push(i);
    }
    int count=0;
    while (!q.empty()){
        int node=q.front();
        q.pop();
        count++;
        for (auto v:adjList[node]){
            indegree[v]--;
            if (indegree[v]==0) q.push(v);
        }
    }
    return count!=V;
}
void addEdges(int u,int v,unordered_map<int,vector<int>> &adjList){
    adjList[u].push_back(v);
}
int main(){
    unordered_map<int,vector<int>> adjList;
    int V=4;
    addEdges(1,2,adjList);
    addEdges(2,0,adjList);
    addEdges(0,1,adjList);
    addEdges(2,3,adjList);

    if (isCycleDetected(V,adjList)){
        cout << "Cycle is Present in the Graph" << endl;
    }else{
        cout << "Cycle is not present in the Graph" << endl;
    }
}