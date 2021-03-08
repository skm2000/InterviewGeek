#include<bits/stdc++.h>
using namespace std;
#define ll long long int


void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll>a(n);
    vector<ll>ans;
    for(auto &i :a){
        cin>>i;
        if(i != x){
            ans.push_back(i);
        }
    }
    for(auto &i : ans){
        cout<<i<<" ";
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