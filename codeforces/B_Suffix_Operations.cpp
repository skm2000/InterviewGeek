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
    ll n,ans=0;
    cin >> n;
    vector<ll>a(n);
    for(auto &i : a){
       cin >> i;
    }
    for(ll i=1;i<n;i++){
        ans += abs(a[i]-a[i-1]);
    }
    ll mx = max(abs(a[0]-a[1]),abs(a[n-1]-a[n-2]));
    for(ll i=1;i<n-1;i++){
        mx = max(mx, abs(a[i]-a[i-1]) + abs(a[i+1]-a[i]) - abs(a[i+1]-a[i-1]) );
    }
    cout<<ans-mx<<"\n";
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