#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 1e18
const ll N = 1e5+7;
#define all(x) x.begin(),x.end()
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n;
    cin >> n;
    ll dp[n+1][8];
    for(ll i=0; i<n; i++){
        for(ll j=0; j<8; j++){
            dp[i][j] = INT_MAX;
        }
    }
    dp[0][0] = 0ll;
    ll ans = INT_MAX;
    for(ll i=0; i<n; i++){
        ll cost;
        string s;
        cin >> cost >> s;
        ll string_mask = 0;
        for(ll pos=0; pos<3; pos++){
            char c = 'C' - pos;
            bool have = 0;
            for(char d : s){
                if(c == d){
                    have = 1;
                }
            }
            if(have){
                string_mask += (1 << pos); //* 2^pos;
            }
        }
        for(ll mask=0; mask<8; mask++){
            dp[i+1][mask] = min(dp[i+1][mask], dp[i][mask]);
            dp[i+1][mask | string_mask] = min(dp[i+1][mask | string_mask], dp[i][mask] + cost);
        }
    }
    ans = dp[n][7];
    if(ans == INT_MAX) ans = -1;
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