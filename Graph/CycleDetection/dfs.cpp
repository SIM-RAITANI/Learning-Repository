// Code for cycle detection in directed graph using DFS
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
bool isCycleDetected(int node,unordered_map<int,vector<int>> &adjList,vector<int> &vis,vector<int> &recStack){
    
    if (recStack[node]) return true;
    if (vis[node]) return false;

    recStack[node]=1;
    vis[node]=1;

    for (auto v:adjList[node]){
        if (isCycleDetected(v,adjList,vis,recStack)) return true;
    }
    recStack[node]=0;
    return false;
}
void addEdges(int u,int v,unordered_map<int,vector<int>> &adjList){
    adjList[u].push_back(v);
}
int main(){
    unordered_map<int,vector<int>> adjList;
    int V=4;
    vector<int> vis(V,0);
    vector<int> recStack(V,0);
    addEdges(1,2,adjList);
    addEdges(2,0,adjList);
    addEdges(0,1,adjList);
    addEdges(2,3,adjList);

    if (isCycleDetected(0,adjList,vis,recStack)){
        cout << "Cycle is Present in the Graph" << endl;
    }else{
        cout << "Cycle is not present in the Graph" << endl;
    }
}