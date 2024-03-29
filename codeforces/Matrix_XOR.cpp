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
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    for(ll i=1; i<=n; i++){
        if(min(i,m)%2 == 1){
            ans ^= k+i+1;
        }
    }
    for(ll i=2; i<=m; i++){
        if(min(n,m-i+1)%2 == 1){
            ans ^= k+i+n;
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