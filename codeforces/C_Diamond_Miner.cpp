#include<bits/stdc++.h>
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



int main()
{
    fast_cin();
    //////////////////////////////////
    ll t;
    cin >> t;
    while(t--)
    {
        ll i,n;
        cin>>n;
        vector<ll> minimum,diag;
        for(i=0;i<2*n;i++){
            ll x,y;
            cin>>x>>y;
            if(x==0) minimum.push_back(abs(y));
            else diag.push_back(abs(x));
        }
        sort(minimum.begin(),minimum.end());
        sort(diag.begin(), diag.end());
        double anss=0.0;
        for(i=0;i<n;i++){
            anss+=(double)(sqrt(minimum[i]*minimum[i]+diag[i]*diag[i]));
        }
        cout<<fixed<<setprecision(18)<<anss<<"\n";

    }
    //////////////////////////////////
    // cer;


}