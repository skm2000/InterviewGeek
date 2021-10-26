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
    ll x = floor(log10(n))+1;
    ll ans = 0;
    if (n>=1000) ans+=n-999;
    if (n>=1000000) ans+=n-999999;
    if (n>=1000000000) ans+=n-999999999;
    if (n>=1000000000000) ans+=n-999999999999;
    if (n>=1000000000000000) ans+=n-999999999999999;
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