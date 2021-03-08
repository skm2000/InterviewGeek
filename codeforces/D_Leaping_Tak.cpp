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
    ll n,k;
    cin >> n >> k;
    vector<ll>dp(n+2,0);
    vector<pair<ll,ll>>p;
    for(ll i=0; i<k; i++){
        ll l,r;
        cin >> l >> r;
        p.push_back({l,r});
    }
    dp[1] += 1;
    dp[2] -= 1;
    for(ll i=1; i<=n; i++){
        dp[i] += dp[i-1];
        for(ll j=0; j<k; j++){
            ll l = p[j].first;
            ll r = p[j].second;
            if(i+l <= n){
                dp[i+l] = (dp[i+l] + dp[i])%MOD;
            }
            if(i+r+1 <= n+1){
                dp[i+r+1] = (dp[i+r+1] - dp[i])%MOD;
            }
        }
    }
    cout<<dp[n]%MOD;
}


int main()
{
    fast_cin();
    ll t;
    // cin >> t;
    t = 1;
    while(t--) {
        solve();
    }
    return 0;
}