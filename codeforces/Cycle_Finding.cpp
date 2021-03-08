#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

struct Edge{
    ll u,v,cost;
};

vector<Edge>edges;
ll n,m;

void bellman_ford(){
    vector<ll>d(n+1,0);
    vector<ll>p(n+1,-1);
    ll x;
    for(ll i=0;i<n;i++){
        x = -1;
        for(Edge e : edges){
            if(d[e.u]+e.cost < d[e.v]){
                d[e.v] = d[e.u]+e.cost;
                p[e.v] = e.u;
                x = e.v;
            }
        }
    }
    if(x == -1){
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    for(ll i=0;i<n;i++){
        x = p[x];
    }
    vector<ll>cycle;
    for(ll v=x;;v=p[v]){
        cycle.push_back(v);
        if(v == x && cycle.size()>1){
            break;
        }
    }
    reverse(cycle.begin(),cycle.end());
    for(ll y=1;y<cycle.size();y++){
        cout<<cycle[y]<<" ";
    }
    cout<<cycle[1];
}

void solve(){
    cin >> n >> m;
    edges.resize(m+1);
    for(ll i=0;i<m;i++){
        struct Edge e;
        cin>>e.u >> e.v >> e.cost;
        edges[i] = e;
    }
    bellman_ford();
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