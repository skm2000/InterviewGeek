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
 

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>>a(n, vector<ll>(m));
    vector<pair<ll,pair<ll,ll>>>v;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin >> a[i][j];
            v.push_back({a[i][j],{i,j}});
        }
    }
    sort(v.begin(), v.end());
    vector<vector<bool>>vis(n, vector<bool>(m));
    vector<vector<ll>>ans(n, vector<ll>(m));
    for(ll i=0; i<m; i++){
        ll val = v[i].first;
        ll curi = v[i].second.first;
        ll curj = v[i].second.second;
        vis[curi][curj] = 1;
        ans[curi][i] = val;
    }
    for(ll i=0; i<n; i++){
        vector<ll>temp;
        for(ll j=0; j<m; j++){
            if(vis[i][j] == 0){
                temp.push_back(a[i][j]);
            }
        }
        ll l = 0;
        for(ll j=0; j<m; j++){
            if(ans[i][j] == 0){
                ans[i][j] = temp[l++];
            }
        }
    }
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
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