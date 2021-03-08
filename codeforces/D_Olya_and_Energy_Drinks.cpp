#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define INF INT_MAX

ll n,m,k;
vector<vector<char>>mat;
vector<vector<ll>>dis;
ll a[] = {0, -1, 0, 1}, b[] = {-1, 0, 1, 0};

bool isValid(ll x,ll y){
    if(x<0 || x>=n || y<0 || y>=m || mat[x][y]=='#') return false;
    return true;
}

void printMat(ll r,ll c,vector<vector<ll>>&a){
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void bfs(ll startX,ll startY,ll endX,ll endY){
    dis[startX][startY] = 0;
    queue<pair<ll,ll>>q;
    q.push({startX,startY});
    pair<ll,ll>p;
    while(!q.empty()){
        p = q.front();
        q.pop();
        ll x = p.first;
        ll y = p.second;
        for(ll i=0;i<4;i++){
            for(ll j=1;j<=k;j++){
                ll tmpX = x+j*a[i];
                ll tmpY = y+j*b[i];
                // cout<<tmpX<<" "<<tmpY<<"\n";
                if(!isValid(tmpX,tmpY)) break;
                if(dis[tmpX][tmpY] != -1 && dis[tmpX][tmpY]<dis[x][y]+1) break;
                if(dis[tmpX][tmpY] == -1){
                    dis[tmpX][tmpY] = dis[x][y]+1;
                    q.push({tmpX,tmpY});
                }
            }
        }
    }
}

void solve(){
    cin>>n>>m>>k;
    mat.resize(n);
    dis.resize(n);
    // cout<<dis.size();
    for(ll i=0;i<n;i++){
        mat[i].resize(m);
        dis[i].resize(m);
        for(ll j=0;j<m;j++){
            cin>>mat[i][j];
            dis[i][j] = -1;
        }
    }
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    x1--;y1--;x2--;y2--;
    bfs(x1,y1,x2,y2);
    cout<<dis[x2][y2]<<"\n";
}


int main(){
    ll t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
}