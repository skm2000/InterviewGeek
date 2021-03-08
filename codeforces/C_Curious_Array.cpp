#include <bits/stdc++.h>  
#define ll long long  
#define mod 1000000007  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<"\n"
#define INF 2e18
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



void solve(){
    ll n,m,l,r,k;
    cin>>n>>m;
    vector<ll>a(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<m;i++){
        cin>>l>>r>>k;
        for(ll j=l;j<=r;j++){
            ll x = j-l+k;
            a[j] = (a[j] + nCr(x,k))%mod;    
        }
    }
    for(ll i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
}


int main()
{
    factorial();
    modInverse();
    fast_cin();
    ll t;
    t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}