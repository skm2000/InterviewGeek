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
    ll arr[n];
    ll ind[n+1];
    for(ll i = 0; i < n; ++i){
        cin >> arr[i];
        ind[arr[i]] = i;
    }
//    cout << "l";
    bool vis[n+1];
    ll en = n;
    memset(vis, false, sizeof(vis));
    for(ll i = n; i >= 1; --i){
        if(!vis[i]) {
            for (ll j = ind[i]; j < en; ++j){
                cout << arr[j] << " ";
                vis[arr[j]] = true;
            }
            en = ind[i];
        }
    }

    cout << "\n";
}


int main()
{
    fast_cin();
    ll t;
    cin >> t;
    // t = 1;
    while(t--) {
        solve();
    }
    return 0;
}