#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>adj[100000];
vector<bool>used(100000,false);
vector<ll>comp;

void dfs(ll v){
    used[v] = true;
    for(ll u:adj[v]){
        if(!used[u]){
            dfs(u);
        }
    }
}

ll findComp(ll n){
    ll c=0;
    for(ll i=1;i<=n;i++){
        if(!used[i]){
            dfs(i);
            comp.push_back(i);
            c++;
        }
    }
    return c;
}

void solve(){
    ll n,m,u,v;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<findComp(n)-1<<"\n";
    for(ll i=1;i<=comp.size();i++){
        cout<<comp[i-1]<<" "<<comp[i]<<"\n";
    }
}


int main(){
    ll t;
    t=1;
    while(t--){
        solve();
    }
}