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

vector<ll>tree[100001];
vector<pair<ll,ll>>v;
ll dp[100001][2];

void dfs(ll u, ll par){
    for(auto x : tree[u]){
        if(x != par){
            dfs(x,u);
            dp[u][0] += max(abs(v[u-1].first-v[x-1].first)+dp[x][0], abs(v[u-1].first-v[x-1].second)+dp[x][1]);
            dp[u][1] += max(abs(v[u-1].second-v[x-1].first)+dp[x][0], abs(v[u-1].second-v[x-1].second)+dp[x][1]);
        }
    }
}

void solve(){
    ll n;
    cin >> n;
    v.clear();
    for(ll i=1; i<=n; i++){
        tree[i].clear();
        dp[i][0] = dp[i][1] = 0;
    }
    for(ll i=1; i<=n; i++){
        ll x, y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    for(ll i=1; i<=n-1; i++){
        ll x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1,0);
    cout<<max(dp[1][0], dp[1][1])<<"\n";
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

