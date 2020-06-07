#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100001];
int visited[10001],dis[10001];
void dfs(int node,int d){
    visited[node]=1;
    dis[node]=d;
    for(int child : adj[node]){
        if(!visited[child]){
            dfs(child,dis[node]+1);
        }
    }
}

//n:no of nodes,e:no of edges,u-v:nodes,d:distance,
//k:given node from where we have to find shortest path;
int main(){
    int n,e,u,v,d,k;
    cin>>n>>e;
    cin>>k;
    for(int i=1;i<=e;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(k,0);
}