#include<bits/stdc++.h>  
using namespace std;

#define mp(a,b) (make_pair(a,b))
#define ff 	 		first	
#define ss 	 		second
#define pb 	 		push_back
#define go(i,start,end) for(int i=start;i<=end;i++)




int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
const int inf=100004;
vector<vector<char> >grid;
bool is_valid(int i,int j,int n,int m){
	if(i>=0 and i<=n-1 and j>=0 and j<=m-1 and grid[i][j]!='1')
		return true;
	return false;
}
void _bfs(int x,int y,int &n,int &m,vector<vector<int> >&dp){
	deque<pair<int,int> >dq;
	dp.resize(n+1,vector<int>(m+1,inf));
	bool processed[n+1][m+1];
	memset(processed,false,sizeof(processed));
	dp[x][y]=0;
	dq.push_front(mp(x,y));
	while(!dq.empty()){
		pair<int,int>src=dq.front();
		dq.pop_front();
		if(processed[src.ff][src.ss])
			continue;
		processed[src.ff][src.ss]=true;
		for(int i=0;i<4;i++){
			int x=src.ff+dx[i];
			int y=src.ss+dy[i];
			if(is_valid(x,y,n,m)){
				int cost=grid[x][y]=='X'?1:0;
				if(dp[x][y]>dp[src.ff][src.ss]+cost){
					dp[x][y]=dp[src.ff][src.ss]+cost;
					if(cost==0)
						dq.push_front(mp(x,y));
					else
						dq.push_back(mp(x,y));
				}
			}
		}
	}
}

void print(int &n,int &m,vector<vector<int> >&dp){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dp[i][j] == inf) dp[i][j] = -1;
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
	int n,m;cin>>n>>m;
	grid.resize(n+1,vector<char>(m+1));
	pair<int,int> A_pos,B_pos;
	go(i,0,n-1)
		go(j,0,m-1){
		cin>>grid[i][j];
		if(grid[i][j]=='A')
			A_pos.ff=i,A_pos.ss=j;
		if(grid[i][j]=='B')
			B_pos.ff=i,B_pos.ss=j;
	}
	vector<vector<int> >dp1;
	vector<vector<int> >dp2;
	vector<vector<int> >dp3;
	_bfs(0,0,n,m,dp1);
    // print(n,m,dp1);
	_bfs(A_pos.ff,A_pos.ss,n,m,dp2);
    // print(n,m,dp2);
	_bfs(B_pos.ff,B_pos.ss,n,m,dp3);
    // print(n,m,dp3);
	int ans=INT_MAX;
	go(i,0,n-1)
		go(j,0,m-1)
			ans=min(ans,dp1[i][j]+dp2[i][j]+dp3[i][j]);
	assert(ans!=INT_MAX);
	cout<<ans<<endl;

}

