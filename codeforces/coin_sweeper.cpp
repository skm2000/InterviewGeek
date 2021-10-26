#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define vdbg(v) for(auto x : v) cout<<x<<endl
#define INF 2e18
const ll N = 1e5+7;
#define all(x) x.begin(),x.end()
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


ll dfs(vector<vector<ll>>&matrix, vector<vector<ll>>&dp, ll n, ll m, ll i, ll j, ll prev){

    if(i<0 || i>=n || j<0 || j>=m || prev >= matrix[i][j]) return 0;

    else if(dp[i][j] != 0) return dp[i][j];

    ll path1 = dfs(matrix, dp, n, m, i+1, j, matrix[i][j]);
    ll path2 = dfs(matrix, dp, n, m, i, j+1, matrix[i][j]);
    ll path3 = dfs(matrix, dp, n, m, i-1, j, matrix[i][j]);
    ll path4 = dfs(matrix, dp, n, m, i, j-1, matrix[i][j]);

    dp[i][j] = matrix[i][j] + max({ path1, path2, path3, path4 });

    return dp[i][j];

}
 

void solve(){

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>>matrix(n, vector<ll>(m));
    vector<vector<ll>>dp(n, vector<ll>(m,0));

    ll ans = 0;

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin >> matrix[i][j];
        }
    }

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(dp[i][j] == 0){
                dfs(matrix, dp, n, m, i, j, INT_MIN);
                ans = max(ans, dp[i][j]);
            }
        }
    }

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
        

    cout << ans << "\n";


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

