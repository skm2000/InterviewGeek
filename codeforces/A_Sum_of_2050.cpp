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
    if(n % 2050 != 0){
        cout<<-1<<"\n";
        return;
    }
    ll e = floor(log10(n)) + 1 - 4;
    ll x = 2050 * pow(10,e);
    // dbg(x);
    ll c = 0, p, m;
    while(n != 0){
        if(n%x == 0){
            p = (n/x);
            c += p;
            p = (p*x);
            n = 0;
        }else{
            m = n/x;
            n -= (m*x);
            c += m;
            x /= 10;
        }
    }
    cout<<c<<"\n";
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