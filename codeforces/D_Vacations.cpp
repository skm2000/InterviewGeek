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
    ll n;
    cin >> n;
    vector<ll>a(n+1);
    for(ll i=1; i<=n; i++){
        cin >> a[i];
    }
    ll dp[n+1][3];
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(ll i=1; i<=n; i++){
        dp[i][0] = 1 + min({dp[i-1][0],dp[i-1][1],dp[i-1][2]});

        if(a[i]%2 == 1){
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        }else{
            dp[i][1] = INT_MAX;
        }

        if(a[i]/2 == 1){
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
        }else{
            dp[i][2] = INT_MAX;
        }
    }
    cout<<min({dp[n][0],dp[n][1],dp[n][2]})<<"\n";
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