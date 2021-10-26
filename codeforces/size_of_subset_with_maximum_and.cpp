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
    ll n, ans = 0;
    cin >> n;
    vector<ll>bits(32,0);
    for(ll i = 0; i<n; i++){
        ll x;
        cin >> x;
        for(ll j=0; j<=31; j++){
            if(x & (1 << (j-1))){
                bits[j]++;
            }
            ans = max(ans, bits[j]);
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