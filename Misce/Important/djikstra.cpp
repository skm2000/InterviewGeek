#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,from,next,cost;
		cin>>n>>m;
		vector<pair<int,int>>v[n+1];
		for(int i=1;i<m+1;i++){
			cin>>from>>next>>cost;
			v[from].push_back({cost,next});
		}
		int visited[n+1];
		int dis[n+1];
		for(int i=0;i<n+1;i++){
			visited[i] = 0;
			dis[i] = 1e9;
		}
		priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > q;
		q.push({0,1});
		dis[1] = 0;
		while(!q.empty()){
			auto x = q.top();
			q.pop();
			// int wi = x.first;
			int ei = x.second;
			for(int i=0;i<v[ei].size();i++){
				int e = v[ei][i].first;
				int r = v[ei][i].second;
				if(visited[r] == 0 && dis[ei]+e<dis[r]){
					dis[r] = dis[ei] + e;
					q.push({dis[r],r});
				}
			}
		}
		int qu,a,k;
		cin>>qu;
		while(qu--){
			cin>>a>>k;
			if(k < dis[a]){
				cout<<0<<"\n";
			}
			else{
				cout<<k-(2*dis[a])<<"\n";
			}
		}
	}
}