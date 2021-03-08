#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long

ll dep[200];
vector<ll>a;

void rec(ll l,ll r,ll d){
    if(l>r) return;
    ll mm=0,ind=0;
    for(ll i=l;i<=r;i++){
        if(a[i]>mm){
            mm = a[i];
            ind = i;
        }
    }
    dep[ind] = d;
    rec(l,ind-1,d+1);
    rec(ind+1,r,d+1);
}

void solve(){
    ll n;
    cin>>n;
    a.resize(n);
    for(auto &i : a){
        cin>>i;
    }
    rec(0,n-1,0);
    for(ll i=0;i<n;i++){
        cout<<dep[i]<<" ";
    }
    cout<<"\n";
}


int main(){
    ll t;
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
}