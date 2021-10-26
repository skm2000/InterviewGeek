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
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll>a(n);
    for(auto &i : a){
       cin >> i;
    }
    sort(a.begin(),a.end());
    vector<ll>mindiv;
    for(ll i=0; i<n-1; i++){
        ll d = a[i+1] - a[i];
        if(d > x){
            // d -= 1;
            ll v = d/x;
            mindiv.push_back(v);
        }
    }
    sort(mindiv.begin(), mindiv.end(), greater<ll>());
    
    while(mindiv.size()){
        if(k >= mindiv[mindiv.size()-1]){
            k -= mindiv[mindiv.size()-1];
            mindiv.pop_back();
        }else{
            break;
        }
    }
    ll ans = mindiv.size()+1;
    cout<<ans<<"\n";
}


int main()
{
    fast_cin();
    ll t;
    t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}



