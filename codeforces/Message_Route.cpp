#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long

ll n,m;
vector<ll>adj[1000000];

void bfs(ll s){
    queue<ll>q;
    vector<ll>d(n+1,0),p(n+1,-1); // d-distance,p-parent
    vector<bool>used(n+1,false);
    q.push(s);
    used[s] = true;
    while(!q.empty()){
        ll v = q.front();
        q.pop();
        for(ll u: adj[v]){
            if(!used[u]){
                used[u] = true;
                q.push(u);
                d[u] = d[v]+1;
                p[u] = v;
            }
        }
    }
    // cout<<d[n]+1;
    // for(auto it : p){
    //     cout<<it<<" ";
    // }
    if(!used[n]){
        cout<<"IMPOSSIBLE"<<"\n";
    }else{
        cout<<d[n]+1<<"\n";
        vector<ll>paths;
        for(ll i=n;i!=-1;i=p[i]){
            paths.push_back(i);
        }
        reverse(paths.begin(),paths.end());
        for(auto &it : paths){
            cout<<it<<" ";
        }
    }
}

void solve(){
    ll u,v;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
}


int main(){
    ll t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
}