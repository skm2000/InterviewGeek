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
    ll n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<ll>dp(n+1,0);
    dp[0] = 0;
    for(ll i=1; i<=n; i++){
        dp[i] = -INF;
        if(i >= a){
            dp[i] = max(dp[i],1+dp[i-a]);
        }
        if(i >= b){
            dp[i] = max(dp[i],1+dp[i-b]);
        }
        if(i >= c){
            dp[i] = max(dp[i],1+dp[i-c]);
        }
    }
    cout<<dp[n]<<"\n";
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