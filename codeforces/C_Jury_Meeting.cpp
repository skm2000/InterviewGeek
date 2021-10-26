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
 

void solve(){
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(auto &i : a){
       cin >> i;
    }
    int mx = *max_element(a.begin(), a.end());
    int cmx = count(a.begin(), a.end(), mx);
    int k = count(a.begin(), a.end(), mx - 1);
    int ans = 1, sub = 1;
    for (long long i = 1; i <= n; ++i) {
      ans = ans * i % MOD;
      if (i != k + 1) sub = sub * i % MOD;
    }
    if (cmx == 1) ans = (ans - sub + MOD) % MOD;
    cout << ans << '\n';
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