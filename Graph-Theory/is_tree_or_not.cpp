#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100001];
int visited[100001];

void dfs(int node){
    visited[node]=0;
    for(int child:adj[node]){
        if(!visited[child]){
            dfs(node);
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
    int cc=0;//count of connected components
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            cc++;
        }
    }
    if(cc==1 && e==n-1){
        cout<<"Yes it is a Tree"<<"\n";
    }
    else{
        cout<<"Not a Tree"<<"\n";
    }
}