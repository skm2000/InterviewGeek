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
 

ll n, m;
vector<ll>adj[1000000];
vector<ll>parent;
vector<ll>color;
ll cycle_start, cycle_end;

bool dfs(ll v){
    color[v] = 1;

    for(auto u: adj[v]){
        if(color[u] == 0){
            parent[u] = v;
            if(dfs(u)){
                return true;
            }
        }else if(color[u] == 1){
            cycle_start = u;
            cycle_end = v;
            return true;
        }
    }

    color[v] = 2;
    return false;
}


void solve(){
    cin >> n >> m;

    parent.resize(n,-1);
    color.resize(n,0);
    cycle_start = -1;

    for(ll i=0; i<m; i++){
        ll a, b;
        cin >> a >> b;
        a--,b--;
        adj[a].push_back(b);
    }

    for(ll v=0; v<n; v++){
        if(color[v]==0 && dfs(v)){
            break;
        }
    }

    if(cycle_start == -1){
        cout<<"IMPOSSIBLE"<<"\n";
        return;
    }

    vector<ll>cycle;
    cycle.push_back(cycle_start+1);
    for(ll v=cycle_end; v!=cycle_start; v=parent[v]){
        cycle.push_back(v+1);
    }
    // * since the value of nodes is 0 based
    cycle.push_back(cycle_start+1);
    reverse(cycle.begin(),cycle.end());
    cout<<cycle.size()<<"\n";
    for(auto x : cycle){
        cout<<x<<" ";
    }
    cout<<"\n";
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