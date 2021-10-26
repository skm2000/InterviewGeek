#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
set<int>g[maxn],vis;//vis is a collection of non-directly connected edges 
int n,m,v[maxn],ans;
void dfs(int x)
{
	v[x]=1;
	vis.erase(x);
	vector<int>temp;
	for(int it:vis)
	if(!g[it].count(x)) temp.push_back(it);
	for(int i:temp) vis.erase(i);
	for(int i:temp) dfs(i);
	
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		g[u].insert(v);g[v].insert(u);
	}
	for(int i=1;i<=n;++i) vis.insert(i);
	for(int i=1;i<=n;++i)
	if(!v[i]) ans++,dfs(i);
	printf("%d\n",ans-1);
 } 
