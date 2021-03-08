#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long

ll n,m;
vector<vector<pair<ll,ll>>>path;
vector<vector<bool>>vis;
ll sx,sy,ex,ey;
vector<pair<ll,ll>>moves = {{-1,0},{1,0},{0,1},{0,-1}};

bool isValid(ll x,ll y){
    if(x<0 || x>=n || y<0 || y>=m || vis[x][y]==true) return false;
    return true;
}


void printPath(){
    vector<pair<ll,ll>>ans;
    pair<ll,ll>end = {ex,ey};
    // cout<<end.first<<" "<<end.second;
    while(end.first != sx or end.second != sy)
	{
		ans.push_back(path[end.first][end.second]);
		end.first -= ans.back().first;
		end.second -= ans.back().second;	
	}
    // for(auto x: ans){
    //     cout<<x.first<<" "<<x.second<<"\n";
    // }
 
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto c: ans)
	{
		if(c.first == 1 and c.second ==0)
		{
			cout << 'D';
		}
		else if(c.first == -1 and c.second ==0)
		{
			cout << 'U';
		}
		else if(c.first == 0 and c.second == 1)
		{
			cout << 'R';
		}
		else if(c.first == 0 and c.second == -1)
		{
			cout << 'L';
		}
	}
}


void bfs(){
    queue<pair<ll,ll>>q;
    q.push({sx,sy});
    while(!q.empty()){
        ll cx = q.front().first;
        ll cy = q.front().second;
        q.pop();
        for(auto mv : moves){
            ll mvx = mv.first;
            ll mvy = mv.second;
            if(isValid(cx+mvx,cy+mvy)){
                q.push({cx+mvx,cy+mvy});
                vis[cx+mvx][cy+mvy] = true;
                path[cx+mvx][cy+mvy] = {mvx,mvy};
            }
        }
    }
    if(vis[ex][ey] == false){
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    printPath();
}

void solve(){
    cin>>n>>m;
    path.resize(n);
    vis.resize(n);
    for(ll i=0;i<n;i++){
        path[i].resize(m);
        vis[i].resize(m);
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            path[i][j] = {-1,-1};
            char c;
            cin>>c;
            if(c == '#'){
                vis[i][j] = true;
            }else if(c == 'A'){
                sx = i;
                sy = j;
            }else if(c == 'B'){
                ex = i;
                ey = j;
            }
        }
    }
    bfs();
    // for(ll i=0;i<n;i++){
    //     for(ll j=0;j<m;j++){
    //         cout<<"{"<<path[i][j].first<<" "<<path[i][j].second<<"}"<<" ";
    //     }
    //     cout<<"\n";
    // }
}


int main(){
    ll t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
}