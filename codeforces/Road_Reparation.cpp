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

vector<pair<ll,ll>>v[100000];
vector<bool>visited;


// * PRIM'S ALGORITHM
 

void solve(){
    
    ll n,m;
    cin >> n >> m;
    visited.resize(n, false);

    for(ll i=0; i<m; i++){

        ll x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        v[x].push_back({y, w});
        v[y].push_back({x, w});

    }

    using pii = pair<ll,ll>;
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    pq.push({0,0}); // weight, node

    ll ans = 0;
    while(!pq.empty()){
        
        auto best = pq.top();
        pq.pop();

        ll to = best.second;
        ll w = best.first;

        if(visited[to]) continue;
        visited[to] = true;
        ans += w;


        for(auto x : v[to]){
            if(visited[x.first] == false){
                pq.push({x.second, x.first});
            }
        }

    }

    for(ll i=0; i<visited.size(); i++){
        if(!visited[i]){
            cout<<"IMPOSSIBLE"<<"\n";
            return;
        }
    }
    
    cout << ans << "\n";

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