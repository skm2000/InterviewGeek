#include<bits/stdc++.h>
#define ll long long int
using namespace std;


void solve(){
    ll n,k,q;
    cin>>n>>k;
    vector<ll>x(n);
    unordered_set<ll>s;
    for(auto &i : x){
        cin>>i;
    }
    vector<ll>dp(n);
    dp[n-1] = 1;
    s.insert(x[n-1]);
    for(ll i=n-2;i>=0;i--){
        if(s.count(x[i]) == 0){
            dp[i] = dp[i+1]+1;
            s.insert(x[i]);
        }else{
            dp[i] = dp[i+1];
        }
    }
    for(ll i=0;i<k;i++){
        cin>>q;
        cout<<dp[q-1]<<"\n";
    }
}

int main(){
    ll t;
    t = 1;
    while(t--){
        solve();
    }
}