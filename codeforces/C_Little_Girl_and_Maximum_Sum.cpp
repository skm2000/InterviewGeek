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
    ll n,q,x,y;
    cin >> n >> q;
    vector<ll>diff(n+2,0);
    vector<ll>a(n+1);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    while(q--){
        cin >> x >> y;
        diff[x]++;
        diff[y+1]--;
    }
    for(ll i=1; i<=n; i++){
        diff[i] += diff[i-1];
    }
    sort(diff.begin(),diff.end());
    // for(ll i=1;i<=n;i++){
    //     cout<<diff[i]<<" ";
    // }
    sort(a.begin(),a.end());
    ll sum = 0;
    for(ll i=1; i<=n; i++){
        sum += (a[i]*diff[i+1]);
    }
    cout<<sum<<"\n";
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