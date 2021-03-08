#include <bits/stdc++.h>  
#define ll long long  
using namespace std;
ll MOD = 998244353;
#define dbg(x) cout<<#x<<" = "<<x<<"\n"
#define INF 2e18
const ll mod =  1000000007;
#define MAX 1000007
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll fact[MAX]; 
ll invFact[MAX];


void factorial(){
    fact[0] = 1;
    for(ll i=1;i<MAX;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
}


void modInverse(){
    invFact[0] = invFact[1] = 1;
    for(ll i=2;i<MAX;i++) invFact[i] = (mod - mod/i) * invFact[mod % i] % mod;
    for(ll i=1;i<MAX;i++) invFact[i] = (invFact[i-1] * invFact[i])%mod;
}


ll nCr(ll n, ll r){
   return (((fact[n]*invFact[r])%mod)*invFact[n-r])%mod;
}


 
bool check_good(ll s,ll a,ll b){
    // cout<<s<<" "<<a<<" "<<b<<"\n";
    while(s>0){
        ll k = s%10;
        // dbg(k);
        if(k!=a && k!=b) return false;
        s /= 10;
    }
    return true;
}

void solve(){
    ll a,b,n,ans=0;
    cin>>a>>b>>n;
    for(ll x=0;x<=n;x++){
        ll s = x*a + (n-x)*b;
        if(check_good(s,a,b)){
            ans = (ans + nCr(n,x))%mod;
        }
    }
    cout<<ans<<"\n";
}


int main()
{
    factorial();
    modInverse();
    fast_cin();
    ll t;
    // cin >> t;
    t = 1;
    while(t--) {
        solve();
    }
    return 0;
}