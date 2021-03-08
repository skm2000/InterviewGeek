#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll minm(ll a,ll b){
    return a < b ? a : b;
}

void solve(){
    ll n,x;
    cin>>n>>x;
    vector<ll>a(n),b(n),c(n);
    map<ll,ll>m;
    for(ll i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
        m[a[i]] += c[i];
        m[b[i]+1] -= c[i];
    }
    ll ans = 0, pre = 0, sum = 0;
	for(auto &it: m) {
		ans += minm(sum, x) * (it.first - pre);
		sum += it.second, pre = it.first;
	}
	cout << ans << '\n';
}

int main(){
    ll t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
}