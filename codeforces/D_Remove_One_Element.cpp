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
    vector<ll>a(n);
    for(ll i=0; i<n; i++){
        cin >> a[i];
    }
    vector<ll>right(n,1);
    vector<ll>left(n,1);
    ll ans = 1;
    for(ll i=n-2; i>=0; i--){
        if(a[i]<a[i+1]){
            right[i] = right[i+1]+1;
        }
    }
    for(ll i=1; i<n; i++){
        if(a[i]>a[i-1]){
            left[i] = left[i-1]+1;
            ans = max(ans,left[i]);
        }
    }
    for(ll i=0;i<n-2;i++){
        if(a[i]<a[i+2]){
            ans = max(ans,left[i]+right[i+2]);
            ans = max(ans,right[i]);
        }
    }
    cout<<ans<<"\n";
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