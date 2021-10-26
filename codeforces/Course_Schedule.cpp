// #include <bits/stdc++.h>  
// #define ll long long  
// const ll mod = 1000000007;  
// using namespace std;
// ll MOD = 998244353;
// #define MAX 1000007
// #define dbg(x) cout<<#x<<" = "<<x<<endl
// #define vdbg(v) for(auto x : v) cout<<x<<" "
// #define INF 2e18
// const ll N = 1e5+7;
// #define all(x) x.begin(),x.end()
// #define mem0(a) memset(a,0,sizeof(a))
// #define mem1(a) memset(a,-1,sizeof(a))
// #define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


// ll n,m,k;
// vector<ll>adj[100001];
// vector<bool>visited;
// vector<ll>top_sort;

// void dfs(ll v){
//     for(auto u : adj[v]){
//         if(!visited[u]){
//             visited[u] = true;
//             dfs(u);
//         }
//     }
//     top_sort.push_back(v);
// }


// void compute(){

//     for(ll i=0; i<n; i++){
//         if(!visited[i]){
//             visited[i] = true;
//             dfs(i);
//         }
//     }

//     reverse(top_sort.begin(),top_sort.end());
// }
 

// void solve(){
//     cin >> n >> m;
//     visited.resize(n, false);
//     for(ll i=0; i<m; i++){
//         ll a,b;
//         cin >> a >> b;
//         a--, b--;
//         adj[a].push_back(b);
//     }
//     compute();
//     vector<ll> ind(n);
// 	for (ll i = 0; i < n; i++) ind[top_sort[i]] = i;
// 	for (ll i = 0; i < n; i++) for (ll j: adj[i]) if (ind[j] <= ind[i]) {
// 		cout << "IMPOSSIBLE\n";
// 		return;
// 	}
//     for(auto x : top_sort) {
//         cout << x+1 << " ";
//     }
//     cout << "\n";
// }


// int main()
// {
//     fast_cin();
//     ll t;
//     // cin >> t;
//     t = 1;
//     while(t--) {
//         solve();
//     }
//     return 0;
// }



// * TOPOLOGICAL SORT USING BFS(ALSO KNOWN AS KHAN'S ALGORITHM)

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
vector<ll>topo_sort, indegree;


void solve(){
    
    cin >> n >> m;
    indegree.resize(n,0);

    for(ll i=0; i<m; i++){
        ll a, b;
        cin >> a >> b;
        a--,b--;
        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<ll>q;
    for(ll i=0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        ll u = q.front();
        q.pop();
        topo_sort.push_back(u);
        for(auto v : adj[u]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }

    if(topo_sort.size() != n){
        cout << "IMPOSSIBLE\n";
        return;
    }

    for(auto x : topo_sort) {
        cout << x+1 << " ";
    }
    cout << "\n";


}


int main()
{
    fast_cin();
    ll t;
    t = 1;
    while(t--) {
        solve();
    }
    return 0;
}

