#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
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
    ll n,u,v;
    cin >> n >> u >> v;
    vector<ll>a(n);
    for(auto &i : a){
        cin >> i;
    }
    ll ans,flag1=0,f2=0;
    for(ll i=0;i<n-1;i++){
        ll x = abs(a[i]-a[i+1]);
        if(x>=2){
            cout<<0<<"\n";
            return;
        }else if(x==1){
            flag1 = 1;
        }else{
            f2 = 1;
        }
    }
    if(flag1){
        cout<<min(u,v)<<"\n";
        return;
    }
    if(f2){
        cout<<min(2*v,u+v)<<"\n";
        return;
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