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

    //          vll prt(n,1e14);
    //          for(i=0;i<n;i++){
    //              if(i==0){
    //                  if(nv[i]>0) prt[i]=nv[i];
    //                  con;
    //              }
    //              if(nv[i]>0){
    //                  prt[i]=min(prt[i],nv[i]);
    //              }
    //              prt[i]=min(prt[i],prt[i-1]+1);
    //          }
    //          for(i=n-1;i>=0;i--){
    //              if(i==n-1){
    //                  if(nv[i]>0) prt[i]=min(prt[i],nv[i]);
    //                  con;
    //              }
    //              if(nv[i]>0){
    //                  prt[i]=min(prt[i],nv[i]);
    //              }
    //              prt[i]=min(prt[i],prt[i+1]+1);
    //          }
    //          output(prt);
    //          cout nl;
             
             
             
             
    // }


 

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll>a(k);
    vector<ll>temp(k);
    for(auto &i : a){
       cin >> i;
    }
    for(auto &i : temp){
       cin >> i;
    }
    vector<ll>v(n,0);
    for(ll i=0;i<k;i++){
        v[a[i]-1]=temp[i];
    }
    // vector<ll>v(n,0);
    // for(ll i=0;i<k;i++){
    //     v[a[i]-1]=temp[i];
    // }
    // vector<ll> ans(n,1e14);
    // for(ll i=0;i<n;i++){
    //     if(i==0){
    //         if(v[i]>0) ans[i]=v[i];
    //     }
    //     if(v[i]>0){
    //         ans[i]=min(ans[i],v[i]);
    //     }
    //     ans[i]=min(ans[i],ans[i-1]+1);
    // }
    vector<ll> ans(n,1e14);
    for(ll i=0;i<n;i++){
        if(i==0){
            if(v[i]>0) ans[i]=v[i];
            continue;
        }
        if(v[i]>0){
            ans[i]=min(ans[i],v[i]);
        }
        ans[i]=min(ans[i],ans[i-1]+1);
    }
    // for(ll i=0;i<n;i++){
    //     if(i==0){
    //         if(v[i]>0) ans[i]=v[i];
    //     }
    //     if(v[i]>0){
    //         ans[i]=min(ans[i],v[i]);
    //     }
    //     ans[i]=min(ans[i],ans[i-1]+1);
    // }
    for(ll i=n-1;i>=0;i--){
        if(i==n-1){
            if(v[i]>0) ans[i]=min(ans[i],v[i]);
            continue;
        }
        if(v[i]>0){
            ans[i]=min(ans[i],v[i]);
        }
        ans[i]=min(ans[i],ans[i+1]+1);
    }
    vdbg(ans);
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