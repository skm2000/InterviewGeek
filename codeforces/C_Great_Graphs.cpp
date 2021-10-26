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
    ll n;
    cin >> n;
    vector<ll>a(n);
    ll sum = 0;
    for(auto &i : a){
       cin >> i;
       sum += i;
    }
    sort(a.begin(), a.end());
    // if(n%2 == 0) cout<<0<<"\n";
    // cout<<(-1*sum)<<"\n";
    ll k=0, x=0;
    for(ll i=2; i<=n-1; i++){
        // if(n%2 == 0) cout<<0<<"\n";
    // cout<<(-1*sum)<<"\n";
        x += a[i-2];
        k -= (a[i]*(i-1));
        k += x;
        // if(n%2 == 0) cout<<0<<"\n";
    // cout<<(-1*sum)<<"\n";
    }
    cout<<k<<"\n";
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