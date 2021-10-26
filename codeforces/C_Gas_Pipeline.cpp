#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 100000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vector<ll>v(n+1);
    for(ll i=1; i<=n; i++){
        v[i] = s[i-1]-'0';
    }
    ll dp[n+2][2];
    dp[0][0] = b;
    dp[0][1] = INF;
    dp[n][1] = INF;
    for(ll i=1; i<=n; i++){

        dp[i][1] = min(dp[i-1][1] + a + 2*b,dp[i-1][0] + 2*a + 2*b);

        if(v[i] == 1 || (i != n && v[i+1] == 1)){
            dp[i][0] = INF;
        }

        else if(i!=1 && v[i-1] == 1){
            dp[i][0] = dp[i-1][1] + 2*a + b;
        }
        
        else{
            dp[i][0] = min(dp[i-1][1] + 2*a + b, dp[i-1][0] + a + b);
        }
        
    }
    cout<<dp[n][0]<<"\n";
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