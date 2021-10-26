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
    ll n, m, k;
    cin >> n >> m >> k;
    bool flag;
    --k;
    if (k < 1) {
      flag = false;
    } else if (k == 1) {
      flag = (n == 1);
    } else if (k == 2) {
      flag = (n <= 2 || m == n * (n - 1) / 2);
    } else {
      flag = true;
    }
    flag &= (m <= n * (n - 1) / 2);
    flag &= (m >= n - 1);
    cout << (flag ? "YES" : "NO") << '\n';
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
