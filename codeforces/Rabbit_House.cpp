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

ll mat[501][501];
ll tmp[501][501];
// ll ans = 0;

void dfs(ll x, ll y, ll n, ll m){
    // for(ll i=0; i<n; i++){
    //     for(ll j=0; j<m; j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    if(x<0 || y<0 || x>=n || y>=m) return;
    // cout<<mat[x][y]<<" ";
    if(mat[x][y] - mat[x-1][y] > 1 && x-1 >= 0) { mat[x-1][y] = mat[x][y] - 1; dfs(x-1,y,n,m); dfs(x+1,y,n,m); dfs(x,y+1,n,m); dfs(x,y-1,n,m); }
    // else return;
    if(mat[x][y] - mat[x+1][y] > 1 && x+1 < n) { mat[x+1][y] = mat[x][y] - 1; dfs(x-1,y,n,m); dfs(x+1,y,n,m); dfs(x,y+1,n,m); dfs(x,y-1,n,m); }
    // else return;
    if(mat[x][y] - mat[x][y+1] > 1 && y+1 <= m) { mat[x][y+1] = mat[x][y] - 1; dfs(x-1,y,n,m); dfs(x+1,y,n,m); dfs(x,y+1,n,m); dfs(x,y-1,n,m); }
    // else return;
    if(mat[x][y] - mat[x][y-1] > 1 && y-1 >= 0) { mat[x][y-1] = mat[x][y] - 1; dfs(x-1,y,n,m); dfs(x+1,y,n,m); dfs(x,y+1,n,m); dfs(x,y-1,n,m); }
    // dbg(ans);
    // else return;
}


int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(ll i=1; i<=t; i++){
        ll n, m, x = -1, y = -1, mxm = INT_MIN;
        // memset(mat,INT_MAX, sizeof(mat));
        cin >> n >> m;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                cin >> mat[i][j];
                tmp[i][j] = mat[i][j];
                if(mat[i][j] > mxm){
                    mxm = mat[i][j]
                }
            }
        }
        // dbg(x);
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                if(mxm == mat[i][j]){
                    dfs(i,j,n,m);
                }
            }
        }
        for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    //     for(ll i=0; i<n; i++){
    //     for(ll j=0; j<m; j++){
    //         cout<<tmp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    ll ans=0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            ans += mat[i][j]-tmp[i][j];
        }
    }
        cout<<"Case #"<<i<<":"<<" "<<ans<<"\n";
    }
    return 0;
}