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

bool comp(const pair<ll,ll> &a,
              const pair<ll,ll> &b)
{
    return a.first > b.first;
}

void knap(vector<ll>w, vector<ll>val, ll m, ll n){
    vector<pair<ll,ll>>p;
    for(ll i=0; i<n; i++){
        p.push_back({val[i], w[i]});
    }
    sort(p.begin(), p.end(), comp);
    // ll x = 0, ans = 0, j=0;
    // dbg(p.size());
    for(auto x:p){
        cout<<x.first<<" "<<x.second<<"\n";
    }
    vector<ll>f(n);
    for(ll i=0; i<n; i++){
        f[i] = p[i].second;
    }
    ll ans = 0, sum = 0, k = 0;
    for(ll i=0; i<n; i++){
        sum += f[i];
        if(sum <= m){
            ans += p[k++].first;
        }else{
            sum -= f[i];
        }
    }
    dbg(sum);
    cout<<ans<<"\n";
}

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll>w(n),v(n);
    for(auto &i : w){
       cin >> i;
    }
    for(auto &i : v){
       cin >> i;
    }
    knap(w,v,m,n);
}


int main()
{
    fast_cin();
    ll t;
    cin >> t;
    // t = 1;1
    while(t--) {
        solve();
    }
    return 0;
}