#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define vdbg(v) for(auto x : v) cout<<x<<" ";
#define INF 2e18
const ll N = 1e5+7;
#define all(x) x.begin(),x.end()
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
ll fact[MAX]; 
ll invFact[MAX];
ll lp[N+1];
vector<ll> pr;


void sieveMinmPrimeFactor(){
    for (ll i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (ll j=0; j<(ll)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}


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
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(auto &i : a){
       cin >> i;
    }
    vector<ll>pre(n,0);
    vector<ll>suf(n,0);
    suf[0]=a[0];
    for(ll i=1;i<n;i++){
        if((a[i]&suf[i-1])==suf[i-1]){
            pre[i]=0;
            suf[i]=a[i];
            // con;
        }
        else{
            ll up=1;
            ll take=0;
            for(ll j=0;j<32;j++){
                if(((suf[i-1]>>j)&1)==1 && ((a[i]>>j)&1)==0){
                    take=take+up;
                }
                up=up*2;
            }
            pre[i]=take;
            suf[i]=pre[i]^a[i];
        }
    }
    vdbg(pre);
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