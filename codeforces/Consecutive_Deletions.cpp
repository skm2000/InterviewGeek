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
    ll n, k;
    cin >> n >> k;
    vector<ll>a(n);
    vector<ll>prefix(n+1);
    prefix[0] = 0;
    for(ll i=0; i<n; i++){
        cin >> a[i];
        prefix[i+1] = prefix[i] + a[i];
    }
    ll total = prefix[n];
    ll min_ones = k, sum;
    for(ll i=k; i<=n; i++){
        sum = prefix[i] - prefix[i-k];
        min_ones = min(min_ones,sum);
    }
    ll ans = ((min_ones*(min_ones+1))/2) + total - min_ones;
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