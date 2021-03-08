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
    ll n,m,c;
    cin >> n >> m >> c;
    vector<ll>a(n+1);
    vector<ll>b(m+1);
    vector<ll>diff(n+2,0);
    for(ll i=1; i<=n; i++){
        cin >> a[i];
    }
    for(ll i=1;i<=m;i++){
        cin >> b[i];
    }
    for(ll i=1;i<=m;i++){
        diff[i] += b[i];
        if(i+n-m<n){
            diff[i+n-m+1] -= b[i];
        }
    }
    for(ll i=1;i<=n;i++){
        diff[i] += diff[i-1];
    }
    // for(ll i=1;i<=n;i++){
    //     cout<<diff[i]<<" ";
    // }
    // cout<<"\n";
    for(ll i=1;i<=n;i++){
        a[i] = (a[i] + diff[i])%c;
        cout<<a[i]<<" ";
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
