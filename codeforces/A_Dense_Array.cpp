#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long


void solve(){
    ll n;
    cin>>n;
    vector<ll>p(n);
    for(auto &i :p){
        cin>>i;
    }
    ll ans=0;
    // cout<<p.size();
    for(ll i=0;i<n-1;i++){
        ll mx = max(p[i],p[i+1]);
        ll mn = min(p[i],p[i+1]);
        ll x = ceil((mx*1.0)/(mn*1.0));
        // cout<<mx<<" "<<mn<<" "<<x<<"\n";
        while(x>2){
            mn = 2*mn;
            ans++;
            x = ceil((mx*1.0)/(mn*1.0));
        }
    }
    cout<<ans<<"\n";
}


int main(){
    ll t;
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
}