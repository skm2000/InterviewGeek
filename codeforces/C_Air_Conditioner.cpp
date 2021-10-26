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
    ll n, m;
    cin >> n >> m;
    vector<ll>t(n),l(n),r(n);
    ll mx = m, mn = m;
    for(ll i=0; i<n; i++){
        cin >> t[i] >> l[i] >> r[i];
    }
    ll prev = 0;
    for(ll i=0; i<n; i++){
        mx += t[i] - prev;
        mn -= t[i] - prev;
    }
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