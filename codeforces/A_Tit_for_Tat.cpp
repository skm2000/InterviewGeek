#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define vdbg(v) for(auto x : v) cout<<x<<endl
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
    for(auto &i : a){
       cin >> i;
    }
    for(ll i=0; i<n-1; i++){
        if(a[i] < k){
            k -= a[i];
            a[n-1] += a[i];
            a[i] = 0;
        }else{
            a[i] -= k;
            a[n-1] += k;
            k = 0;
        }
    }
    for(auto &i : a){
        cout<<i<<" ";
    }
    cout<<"\n";
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