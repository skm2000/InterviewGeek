#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100001];
int visited[10001];
void dfs(int v){
    visited[v]=1;
    for(int u:adj[v]){
        if(!visited[u]){
            dfs(u);
        }
    }
}

int main(){
    int n,e,u,v;
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cc=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            cc++;
        }
    }
    cout<<cc<<"\n";
}