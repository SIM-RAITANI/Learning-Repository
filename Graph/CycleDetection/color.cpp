//Cycle Detection Using Coloring Technique
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
bool isCycleDetected(int node,unordered_map<int,vector<int>> &adjList,vector<int> &color){
    //under processing state
    color[node]=1;

    for (auto v:adjList[node]){
        //if the node is in the recursion stack
        if(color[v] == 1){
            return true;
        }
        //node is unvisited
        if (color[v] == 0 && isCycleDetected(v,adjList,color)){
            return true;
        }
    }
    //node is processed properly  with no back edge to this node;
    color[node]=2;
    return false;
}
void addEdges(int u,int v,unordered_map<int,vector<int>> &adjList){
    adjList[u].push_back(v);
}
int main(){
    unordered_map<int,vector<int>> adjList;
    int V=4;
    vector<int> color(V,0);
    addEdges(1,2,adjList);
    addEdges(2,0,adjList);
    addEdges(0,1,adjList);
    addEdges(2,3,adjList);

    if (isCycleDetected(0,adjList,color)){
        cout << "Cycle is Present in the Graph" << endl;
    }else{
        cout << "Cycle is not present in the Graph" << endl;
    }
}