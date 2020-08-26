#include <bits/stdc++.h>
using namespace std;

vector<int>adj[100001];
int visited[100001];

void dfs(int node){
    visited[node] = 0;
    for(int child:adj[node]){
        if(!visited[child]){
            dfs(child);
        }
    }
}


int main(){
    int n,e,u,v;
    cin>>n>>e ;
    for(int i=1;i<=e;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cc = 0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(i);
            cc++;
        }
    }
    cout<<"Connected components"<<"\n";
}