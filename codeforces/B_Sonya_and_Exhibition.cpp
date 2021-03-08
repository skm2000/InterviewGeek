#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,m,u,v;
    cin>>n>>m;
    vector<ll>ans(n+1);
    for(ll i=0;i<m;i++){
        cin>>u>>v;
    }
    for(ll i=1;i<=n;i+=2){
        ans[i]=1;
    }
    for(ll i=1;i<=n;i++){
        cout<<ans[i];
    }
    cout<<"\n";
}


int main(){
    ll t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}