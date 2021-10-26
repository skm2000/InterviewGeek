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

vector<vector<ll>>adj;
vector<ll>color;

void dfs(ll u, ll p, ll curr_color){
    color[u] = curr_color;
    for(auto v : adj[u]){
        if(v == p) continue;
        dfs(v,u,curr_color);
    }
} 

void solve(){
    ll n, m;
    cin >> n >> m;
    m--;
    adj.resize(n);
    color.resize(n);
    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll cur_color = 0;
    for(ll j : adj[m]){
        dfs(j, m, cur_color++);
    }
    ll q;
    cin >> q;
    while(q--){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        if(u == m || v == m || color[u] != color[v]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}


int main()
{
    fast_cin();
    ll t;
    // cin >> t;
    t = 1;
    while(t--) {
        solve();
    }
    return 0;
}

