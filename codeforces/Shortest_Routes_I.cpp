#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long

ll n,e,w;
vector<vector<pair<ll,ll>>>G;
vector<ll>p,d;
vector<bool>mark;

void restore_paths(ll s,ll t){
    vector<ll>path;
    for(ll x=t; x!=s; x=p[x]){
        path.push_back(x);
    }
    path.push_back(s);
    reverse(path.begin(),path.end());
    for(auto &it : path){
        cout<<it<<" ";
    }
    // cout<<"\n";
}

void djikstra(ll s){
    p.resize(n+1,-1);
    mark.resize(n+1,false);
    d.resize(n+1,INF);
    d[s] = 0;
    using pii = pair<ll,ll>;
    priority_queue<pii,vector<pii>, greater<pii>>pq;
    pq.push({d[s],s});
    while(!pq.empty()){
        ll v = pq.top().second;
        pq.pop();
        if(mark[v] == false){
            mark[v] = true;
            for(auto edge : G[v]){
                ll to = edge.first;
                ll len = edge.second;
                if(d[v]+len < d[to]){
                    d[to] = d[v] + len;
                    p[to] = v;
                    pq.push({d[to],to});
                }
            }
        }
    }
    for(ll i=1;i<=n;i++){
        cout<<d[i]<<" ";
    }
    // if(d[n] == INF){
    //     cout<<-1<<"\n";
    //     return;
    // }
    // restore_paths(1,n);
}

void solve(){
    ll u,v;
    cin>>n>>e;
    G.resize(n+1);
    for(ll i=0;i<e;i++){
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        // G[v].push_back({u,w});
    }
    djikstra(1);
}


int main(){
    ll t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}