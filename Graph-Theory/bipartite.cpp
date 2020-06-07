#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100001];
int visited[100001];
int col[100001];//colour can either be zero or one & hence we are inverting the colour using XOR operation
bool dfs(int node,int colour){
    visited[node]=1;
    col[node]=1;
    for(int child:adj[node]){
        if(!visited[child]){
            if(dfs(node,colour^1)==false){
                return false;
            }
        }
        else{
            if(col[node]==col[child]){
                return false;
            }
        }
    }
    return true;
}



int main(){
    int n,e,u,v;
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool flag=true,res;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            res = dfs(i,0);//initially taking the color as zero
            if(res==false){
                flag=false;
            }
        }
    }
    if(flag==false){
        cout<<"NO"<<"\n";
    }
    else{
        cout<<"YES"<<"\n";
    }
}