#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll max(ll a,ll b) {
    return (a>=b) ? a : b;
}

void solve(){
    ll n,m;
    cin>>n;
    vector<ll>r(n);
    for(auto &i : r){
        cin>>i;
    }
    cin>>m;
    vector<ll>b(m);
    for(auto &i : b){
        cin>>i;
    }
    vector<ll>rp(n);
    rp[0]=r[0];
    ll rmax=rp[0];
    for(ll i=1;i<n;i++){
        rp[i] = rp[i-1] + r[i];
        rmax = max(rp[i],rmax);
    }
    rmax = max(0,rmax);
    vector<ll>bp(m);
    bp[0]=b[0];
    ll bmax=bp[0];
    for(ll i=1;i<m;i++){
        bp[i] = bp[i-1] + b[i];
        bmax = max(bp[i],bmax);
    }
    bmax = max(0,bmax);
    // cout<<rmax<<" "<<bmax<<"\n";
    cout<<max(0,rmax+bmax)<<"\n";
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}