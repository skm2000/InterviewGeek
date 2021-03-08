#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll n,x; 
    cin >> n >> x;
    vector<ll>a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll sum = 0, sum2 = 0;
    for(ll i = 0; i < n; i++) {
        sum += a[i];
        sum2 += ceil((double)a[i]/(double)x);
    }
    sum = ceil((double)sum/(double)x);
    cout << sum << " " << sum2 << "\n";
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}