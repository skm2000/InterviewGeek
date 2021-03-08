#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n,k;
    cin>>n>>k;
    string ans(n,'a');
    for(ll i=n-2;i>=0;i--){
        if(k <= (n-i-1)){
            ans[i] = 'b';
            ans[n-k] = 'b';
            cout<<ans<<"\n";
            return;
        }
        k -= (n-i-1);
    }
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