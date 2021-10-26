#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

char mat[505][505];

ll check(ll x1, ll y1, ll x2, ll y2){
    return (mat[x1][y1]=='.' && mat[x2][y2]=='.');
}

void solve(){
    ll n, m;
    cin >> n >> m;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=m; j++){
            cin >> mat[i][j];
        }
    }
    ll dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for(ll i=1; i<=n; i++) dp[i][1] = check(i-1,1,i,1) + dp[i-1][1];
    for(ll i=1; i<=m; i++) dp[1][i] = check(1,i-1,1,i) + dp[1][i-1];
    for(ll i=2; i<=n; i++){
        for(ll j=2; j<=m; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + check(i-1,j,i,j) + check(i,j-1,i,j);
        }
    }
    // for(ll i=0; i<=n; i++){
    //     for(ll j=0; j<=m; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    ll q, ans = 0;
    cin >> q;
    while(q--){
        ll x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ans = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        for(ll i=x1; i<=x2; i++) ans -= check(i,y1,i,y1-1);
        for(ll i=y1; i<=y2; i++) ans -= check(x1,i,x1-1,i);
        cout<<ans<<"\n"; 
    }
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