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
    ll n,m,k,x,y;
    cin >> n >> m >> k;
    vector<ll>a(n+2);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<pair<ll,ll>>ops(m+2); // number of operations
    vector<ll>val(m+2); 
    for(ll i=1;i<=m;i++){
        cin >> ops[i].first >> ops[i].second >> val[i];
    }
    vector<ll>opsCount(m+2,0);
    while(k--){
        cin >> x >> y;
        y++;
        opsCount[x]++;                          // diff array is diff[l] += updateValue
        opsCount[y]--;                          // diff array is diff[r+1] -= updateValue
    }
    for(ll i=1;i<=m;i++){
        opsCount[i] += opsCount[i-1];
    }
    vector<ll>diff(n+2,0);
    for(ll i=1;i<=m;i++){
        if(opsCount[i]){
            ll l=ops[i].first,r=ops[i].second;
            r++;
            diff[l] += opsCount[i] * val[i];
            diff[r] -= opsCount[i] * val[i];
        }
    }
    for(ll i=1;i<=n;i++){
        diff[i] += diff[i-1];
        a[i] += diff[i];
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
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