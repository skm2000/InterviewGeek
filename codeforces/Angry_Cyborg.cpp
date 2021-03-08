#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n,q,l,r;
    cin >> n >> q;
    vector<ll>diff(n+2,0);
    vector<pair<ll,ll>>query(q);
    for(ll i=1; i<=q; i++){
        cin >> l >> r;
        query.push_back({l,r});
    }
    for(auto x : query){
        ll l = x.first;
        ll r = x.second;
        diff[l]++;
        diff[r+1]--;
    }
    for(ll i=1; i<=n; i++){
        diff[i] += diff[i-1];
    }
    for(auto x : query){
        ll l = x.first;
        ll r = x.second;
        diff[r+1] -= r-l+1;
    }
    for(ll i=1; i<=n; i++){
        diff[i] += diff[i-1];
    }
    for(ll i=1; i<=n; i++){
        cout<<diff[i]<<" ";
    }
    cout<<"\n";
}


int main()
{
    fast_cin();
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}