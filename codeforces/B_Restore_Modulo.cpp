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

ll add(ll a, ll b){
    ll c = a+b;
    return c;
}

 

void solve(){
    ll n;
    cin >> n;
    vector<ll>a(n);

    for(auto &i : a){
       cin >> i;
    }

    if(n == 1 && a[0] == 1){
        cout<<0<<"\n";
        return;
    }

    set<ll> s;
    
    for(ll i = 1; i < n; ++i){
        ll y = a[i] - a[i-1];
        s.insert(y);
    }

    ll size = s.size();

    if(size > 2){
        cout << -1 << "\n";
        return;
    }

    if(size == 1){
        cout << 0 << "\n";
        return;
    }

    ll M = 0, c = -1;

    for(auto it: s){
        M += abs(it);
        if(it > 0) c = it;
    }

    if(a[0] > M){
        cout << -1 << "\n";
        return;
    }

    if(c == - 1){
        cout << -1 << "\n";
        return;
    }
    
    ll p[n];

    p[0] = a[0];

    for(ll i = 1; i < n; ++i){
        p[i] = (p[i-1] + c) % M;
        if(p[i] != a[i]) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << M << " " << c << "\n";
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