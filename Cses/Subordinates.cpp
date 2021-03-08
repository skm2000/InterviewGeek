#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>tree[200001];

void dfs(ll src,ll par,vector<ll>&ans){
    ll subords = 0;
    for(ll child: tree[src]){
        if(child != par){
            dfs(child,src,ans);
            subords += (1+ans[child]);
        }
    }
    ans[src] = subords;
}

void solve(){
    ll n,x;
    cin>>n;
    vector<ll>ans(n+1);
    for(ll i=2;i<n+1;i++){
        cin>>x;
        tree[x].push_back(i);
        tree[i].push_back(x);
    }
    dfs(1,0,ans);
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}


int main(){
    ll t;
    t = 1;
    while(t--){
        solve();
    }
}