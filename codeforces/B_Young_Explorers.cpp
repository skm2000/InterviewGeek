#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll n,k;
vector<ll>a;


void solve(){
    cin>>n;
    a.resize(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll ans = 0, cur = 0;
    for (ll i = 0; i < n; i++) {
        if (++cur == a[i]) {
            ans++;
            cur = 0;
        }
    }
    cout << ans << '\n';
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}