#include<bits/stdc++.h>
using namespace std;
vector<int>ar[100001];
int visited[100001];
bool dfs(int node,int par){
    visited[node]=1;
    for(int child:ar[node]){
        if(!visited[child]){
            if(dfs(child,node)==true){
                return true;
            }
        }
        else{
            if(child!=par){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,e,u,v;
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        cin>>u>>v;
        ar[u].push_back(v);
        ar[v].push_back(u);
    }
    bool ans;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            ans=dfs(i,-1);//since for initial node there is no parent hence we take parent as -1
        }
    }
    cout<<ans<<"\n";
}