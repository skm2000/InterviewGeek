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
    ll n,ans;
    cin >> n;
    vector<ll>a(n);
    vector<ll>p;
    for(auto &i : a){
       cin >> i;
    }
    ans = (n-1)/2;
    sort(a.begin(),a.end(),greater<ll>());
    for(ll i=0; i<n/2; i++){
        p.push_back(a[i]);
        p.push_back(a[n-i-1]);
    }
    if(n%2 == 1){
        p.push_back(a[n/2]);
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