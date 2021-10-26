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
    ll n, m;
    cin >> n >> m;
    vector<ll>a(n);
    for(auto &i : a){
       cin >> i;
    }
    sort(a.begin(), a.end());
    vector<ll>dp(n,0);
    for(ll i=0; i<n; i++){
        if(i<m){
            dp[i] = a[i];
        }else{
            dp[i] = a[i] + dp[i-m];
        }
    }
    ll s = 0;
    for(ll i=0; i<n; i++){
        s += dp[i];
        cout<<s<<" ";
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