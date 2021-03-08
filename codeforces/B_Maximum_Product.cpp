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
    ll n,ans=1;
    cin >> n;
    vector<ll>a(n);
    for(ll i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    // * all +ve
    ll ans1 = a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5];
    // * 2 -ve 3 +ve
    ll ans2 = a[0]*a[1]*a[n-1]*a[n-2]*a[n-3];
    // * 4 -ve 1 +ve
    ll ans3 = a[0]*a[1]*a[2]*a[3]*a[n-1];
    cout<<max({ans1,ans2,ans3})<<"\n";
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