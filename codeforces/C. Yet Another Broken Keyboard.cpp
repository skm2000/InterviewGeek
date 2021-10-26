#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
const ll N = 1e5+7;
#define all(x) x.begin(),x.end()
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<char>type(26,0);
    for(ll i=0; i<k; i++){
        char c;
        cin >> c;
        type[c-'a'] = 1;
    }
    vector<ll>dp(n+1,0);
    dp[0] = 0;
    ll ans = 0;
    for(ll i=1; i<=n; i++){
        if(type[s[i-1]-'a'] == 0){
            dp[i] = 0;
        }else{
            dp[i] = 1 + dp[i-1];
        }
        ans += dp[i];
    }
    cout<<ans<<"\n";
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