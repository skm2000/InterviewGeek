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
    vector<ll>p(n,0);
    for(auto &i : a){
       cin >> i;
    }
    sort(a.begin(),a.end());
    ll j=1, l = n/2;
    for(ll i=0; i<l; i++){
        p[j] = a[i];
        j += 2;
    }
    j = 0;
    for(ll i=l; i<n; i++){
        p[j] = a[i];
        j += 2;
    }
    for(ll i=1; i<n-1; i++){
        if(p[i]<p[i-1] && p[i]<p[i+1]){
            ans++;
        }
    }
    cout<<ans<<"\n";
    for(auto x: p){
        cout<<x<<" ";
    }
    cout<<"\n";
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