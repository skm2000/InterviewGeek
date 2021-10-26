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
    ll n,who;
    cin >> n;
    vector<ll>a(n);
    for(auto &i : a){
       cin >> i;
    }
    if(n == 1){
        cout<<a[0]<<"\n";
        return;
    }
    ll dp[n][2];
    memset(dp,mod, sizeof(dp));
    dp[0][0] = a[0];
    dp[0][1] = INF;
    dp[1][0] = a[0] + a[1];
    dp[1][1] = a[0];
    for(ll  i=2; i<n; i++){
        dp[i][0] = min(dp[i-1][1]+a[i],dp[i-2][1]+a[i-1]+a[i]);
        dp[i][1] = min(dp[i-1][0],dp[i-2][0]);
    }
    cout<<min(dp[n-1][0],dp[n-1][1])<<"\n";
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