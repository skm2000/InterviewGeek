#include<bits/stdc++.h>
using namespace std;
#define ll long long


vector<ll>tree[200001];
ll dp[200001][2];


void dfs(ll src,ll par){
    vector<ll>prefix,suffix;
    dp[src][0]=0,dp[src][1]=0;
    bool leaf = true;

    for(ll child : tree[src]){
        if(child != par){
            leaf = false;
            dfs(child,src);
        }
    }

    if(leaf) return;
    for(ll child : tree[src]){
        if(child != par){
            prefix.push_back(max(dp[child][0],dp[child][1]));
            suffix.push_back(max(dp[child][0],dp[child][1]));
        }
    }

    for(ll i=1;i<prefix.size();i++){
        prefix[i] += prefix[i-1];
    }
    for(ll i=suffix.size()-2;i>=0;i--){
        suffix[i] += suffix[i+1];
    }

    dp[src][0] = suffix[0];
    ll c_i = 0;
    for(ll child : tree[src]){
        if(child != par){
            ll leftChild = (c_i == 0) ? 0 : prefix[c_i-1];
            ll rightChild = (c_i == suffix.size()-1) ? 0 : suffix[c_i+1];
            dp[src][1] = max(dp[src][1],1+leftChild+rightChild+dp[child][0]);
            c_i++;
        }
    }

}

void solve(){
    ll n,u,v;
    cin>>n;
    for(ll i=2;i<=n;i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,0);
    cout<<max(dp[1][0],dp[1][1]);
}


int main(){
    ll t;
    t = 1;
    while(t--){
        solve();
    }
}

