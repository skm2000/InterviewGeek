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
    ll n,x;
    cin >> n >> x;
    vector<ll>a(n);
    for(auto &i : a){
       cin >> i;
    }
    sort(a.begin(), a.end(),greater<ll>());
    ll curr = 1,ans = 0;
    for(ll i=0; i<n; i++){
        if(curr*a[i] >= x){
            ans++;
            curr = 1;
        }else{
            curr++;
        }
    }
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