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
    map<ll,ll>cnt;
    for(auto &i : a){
       cin >> i;
       cnt[i%m]++;
    }
    ll ans = 0;
    for(auto x : cnt){
        if(x.first == 0) ans++;
        else if(2*x.first == m) ans++;
        else if(2*x.first < m || cnt.find(m-x.first) == cnt.end()){
            ll f = x.second;
            ll s = cnt[m-x.first];
            ll diff = abs(f-s);
            ans += 1 + max(0LL,diff-1);
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