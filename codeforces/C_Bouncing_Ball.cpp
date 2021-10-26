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
    ll n, p, k, curr, ans = INF, x, y;
    cin >> n >> p >> k;
    string s;
    cin >> s;
    cin >> x >> y;
    vector<ll>dp(n+k,0);
    for(ll i=n-1; i>=0; i--){
        if(s[i] == '0'){
            dp[i] = dp[i+k] + 1;
        }else{
            dp[i] = dp[i+k];
        }
    }
    // for(ll i=0; i<n; i++) cout<<dp[i]<<" ";
    // cout<<"\n";
    p--;
    for(ll i=p; i<n; i++){
        dp[i] = x*dp[i] + (i-p)*y;
        ans = min(dp[i],ans);
    }
    cout<<ans<<"\n";
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