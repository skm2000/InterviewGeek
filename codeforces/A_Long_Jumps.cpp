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
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<ll>dp(n+1,0);
    for(ll i=n; i>=1; i--){
        if(i+a[i] <= n){
            dp[i] += dp[i+a[i]] + a[i];
        }else{
            dp[i] = a[i];
        }
    }
    // for(ll i=1;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<"\n";
    cout<<*max_element(dp.begin(),dp.end())<<"\n";
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