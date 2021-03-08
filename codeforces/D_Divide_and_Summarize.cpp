#include<bits/stdc++.h>
#define ll long long
using namespace std;

void populateSum(vector<ll>&a,unordered_set<ll>&psum){
    ll sum = 0;
    for(ll i=0;i<a.size();i++){
        sum += a[i];
    }
    psum.insert(sum);
    ll maxm = *max_element(a.begin(),a.end());
    ll minm = *min_element(a.begin(),a.end());
    if(maxm == minm) return;
    ll mid = (maxm+minm)/2;
    vector<ll>lthan,gthan;
    for(ll i=0;i<a.size();i++){
        if(a[i]<=mid) lthan.push_back(a[i]);
        else gthan.push_back(a[i]);
    }
    populateSum(lthan,psum);
    populateSum(gthan,psum);
}

void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll>a(n);
    vector<ll>b(q);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<q;i++) cin>>b[i];
    unordered_set<ll>psum;
    populateSum(a,psum);
    for(ll i=0;i<q;i++){
        if(psum.count(b[i])==1) cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}        