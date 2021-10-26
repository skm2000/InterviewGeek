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

vector<ll>divisors;

void findDivisors(){
    ll n = 1000005;
    divisors.resize(n);
    for(ll i=1; i<=n; i++){
        for(ll j=i; j<=n; j+=i){
            divisors[j]++;
            divisors[j] %= MOD;
        }
    }
}
 

void solve(){
    ll n;
    cin >> n;
    vector<ll>dp(2*n+1), pre(2*n+1);
    dp[0] = pre[0] = 1;
    for(ll i=2; i<=2*n; i+=2){
        dp[i] = pre[i-2] + (divisors[i/2]-1);
        dp[i] %= MOD;
        pre[i] = pre[i-2] + dp[i];
        pre[i] %= MOD;
    }
    cout<<dp[2*n]<<"\n";
}


int main()
{
    findDivisors();
    fast_cin();
    ll t;
    t = 1;
    while(t--) {
        solve();
    }
    return 0;
}