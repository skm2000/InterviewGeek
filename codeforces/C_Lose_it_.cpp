#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    vector<ll>b{4,8,15,16,23,42};
    for(ll i=0;i<n;i++){
        cin>>a[i];
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        // cout<<a[i]<<" ";
    }
    vector<ll> seq(6);
	for (ll i = 0; i < n; ++i) {
		if (a[i] == 0) {
			++seq[0];
		} else {
			if (seq[a[i] - 1] > 0) {
				--seq[a[i] - 1];
				++seq[a[i]];
			}
		}
	}
    // for(ll i=0;i<6;i++){
    //     cout<<seq[i]<<" ";
    // }
	cout << n - seq[5] * 6 << endl;
}

int main(){
    ll t;
    // cin >> t;
    t=1;
    while(t--){
        solve();
    }
}