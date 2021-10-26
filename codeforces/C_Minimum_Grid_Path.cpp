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
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(auto &i : a){
       cin >> i;
    }
    ll ans = a[0]*n + a[1]*n;
    ll minR = a[0] , minU = a[1];
    ll sumR = a[0] , sumU = a[1];
    ll n1 = 1, n2 = 1;
    for(ll i=2; i<n; i++){
        if(i%2 == 0){
            n1++;
            sumR += a[i];
            minR = min(minR, a[i]);
        }else{
            n2++;
            sumU += a[i];
            minU = min(minU, a[i]);
        }
        ans = min(ans, sumR + (n-n1)*minR + sumU + (n-n2)*minU);
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