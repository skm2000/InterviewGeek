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
    ll a[2][n];
    ll dp[2][n];
    for(ll i=0; i<2; i++){
        for(ll j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    dp[0][0] = a[0][0];
    dp[1][0] = a[1][0];

    for(ll i=1;i<n;i++){
        for(ll j=0; j<2; j++){
            dp[j][i] = max(dp[j][i-1],a[j][i]+dp[(j+1)%2][i-1]);
        }
    }
    // for(ll i=0; i<2; i++){
    //     for(ll j=0; j<n; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<max(dp[0][n-1],dp[1][n-1])<<"\n";
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