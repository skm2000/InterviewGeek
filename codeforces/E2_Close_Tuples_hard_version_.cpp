#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll sum(ll n){
    ll res = n*(n+1)/2;
    return res;
}
/* not solved */

void solve(){
    ll n,m,k,total = 0;
    cin>>n>>m>>k;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(ll i=0;i<n;i++){
        ll x = a[i];
        ll y = k+x;
        ll u = upper_bound(a.begin(),a.end(),y)-a.begin();
        --u;
        if(u-i >= 1){
            total += sum(u-i-1);
        }
    }
    cout<<total<<"\n";
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}    