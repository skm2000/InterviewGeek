#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long


void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>G(n);
    ll u,v,c;
    for(ll i=0;i<m;i++){
        cin>>u>>v>>c;
        u--,v--;
        G[u].push_back({c,v});
    }
    for(ll i=0;i<n;i++){
        vector<ll>dis(n+1,-1);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0,i});
        while(!pq.empty()){
            ll x = pq.top().first;
            ll y = pq.top().second;
            pq.pop();
            if(dis[y] == -1){
                if(x>0){
                    dis[y] = x;
                }
                for(auto e : G[y]){
                    ll w = e.second;
                    if(dis[w] == -1){
                        pq.push({x+e.first,w});
                    }
                }
            }
        }
        cout<<dis[i]<<"\n";
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







