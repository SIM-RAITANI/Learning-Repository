//Code for cycle detection using Bellman Ford Algorithm
#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
bool isCycleDetected(int V,vector<vector<int>> &edges){
    vector<int> dist(V,INT_MAX);
    dist[0]=0;
    for (int i=0;i<V-1;i++){
        for (auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            if (dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
    for (auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            if (dist[u]+wt<dist[v]){
                return true;
            }
        }
    return false;
}
int main(){
    int V=3;
    vector<vector<int>> edges = {{0, 1, -1}, {1, 2, -2}, {2, 0, -3}};
    if (isCycleDetected(V,edges)){
        cout << "Cycle is Present in the Graph" << endl;
    }else{
        cout << "Cycle is not present in the Graph" << endl;
    }
}