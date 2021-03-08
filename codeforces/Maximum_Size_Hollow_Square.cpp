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
    ll n,m,k;
    cin >> n >> m >>k;
    string s;
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
    for(ll i=1;i<=n;i++){
        cin>>s;
        for(ll j=1;j<=m;j++){
            ll val = s[j-1] - '0';
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + val;
        }
    }
    ll totalZero = n*m - dp[n][m];
    // dbg(totalZero);
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            ll l = 0,r = min(n-i,m-j);
            while(l <= r){
                ll mid = (l+r)>>1;
                ll ones = dp[i+mid][j+mid] - dp[i+mid][j-1] - dp[i-1][j+mid] + dp[i-1][j-1];
                ll zeros = (mid+1)*(mid+1) - ones;
                if(zeros + k >= (mid+1)*(mid+1) && totalZero-zeros >= (mid+1)*(mid+1) - zeros){
                    ans = max(ans,mid+1);
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        }
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