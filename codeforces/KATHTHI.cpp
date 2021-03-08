#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long

ll n,m;
vector<vector<char>>mat;
vector<vector<ll>>dis;
ll a[] = {0, -1, 0, 1}, b[] = {-1, 0, 1, 0};

bool isValid(ll x,ll y){
    if(x<0 || x>=n || y<0 || y>=m) return false;
    return true;
}

void bfs(ll startX,ll startY,ll endX,ll endY){
    dis[startX][startY] = 0;
    deque<pair<ll,ll>>dq;
    dq.push_front({startX,startY});
    pair<ll,ll>p;
    while(!dq.empty()){
        p = dq.front();
        dq.pop_front();
        ll x = p.first;
        ll y = p.second;
        for(ll i=0;i<4;i++){
            ll tmpX = x+a[i];
            ll tmpY = y+b[i];
            if(isValid(tmpX,tmpY)){
                // cout<<tmpX<<" "<<tmpY<<"\n";
                if(mat[tmpX][tmpY] == mat[x][y] && dis[tmpX][tmpY]>dis[x][y]){
                    dq.push_front({tmpX,tmpY});
                    dis[tmpX][tmpY] = dis[x][y];
                }else if(mat[tmpX][tmpY] != mat[x][y] && dis[tmpX][tmpY] > dis[x][y]+1){
                    dq.push_back({tmpX,tmpY});
                    dis[tmpX][tmpY] = dis[x][y] + 1;
                }
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    mat.resize(n);
    dis.resize(n);
    for(ll i=0;i<n;i++){
        mat[i].resize(m);
        dis[i].resize(m);
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>mat[i][j];
            dis[i][j] = INT_MAX;
        }
    }
    bfs(0,0,n,m);
    // for(ll i=0;i<n;i++){
    //     for(ll j=0;j<m;j++){
    //         cout<<dis[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<dis[n-1][m-1]<<"\n";
}


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
    ll t;
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
}