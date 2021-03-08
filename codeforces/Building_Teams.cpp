#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long

ll n,m;
vector<ll>adj[1000000];
vector<ll>color;
vector<bool>vis;

bool dfs(ll v,ll col){
    vis[v] = true;
    color[v] = col;
    for(int g:adj[v]){
        if(!vis[g]){
            if(!dfs(g,col^1)){
                return false;
            }
        }
        if(color[g] == color[v]) return false;
    }
    return true;
}

bool color_all(){
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            if(!dfs(i,color[i])){
                return false;
            }
        }
    }
    return true;
}

void solve(){
    ll u,v;
    cin>>n>>m;
    color.resize(n+1,1);
    vis.resize(n+1,false);
    for(ll i=1;i<=m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans = color_all();
    if(ans == false){
        cout<<"IMPOSSIBLE"<<"\n";
        return;
    }
    for(ll i=1;i<=n;i++){
        if(color[i] == 0){
            color[i] = 2;
        }
        cout<<color[i]<<" ";
    }
}


int main(){
    ll t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
}