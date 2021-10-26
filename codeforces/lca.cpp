#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

// vector<int> ar[10001];
// const int maxN = 20;
// int level[10001] , LCA[10001][maxN+1];


// void dfs(int node , int lvl , int par)
// {
// 	level[node] = lvl;
// 	LCA[node][0] = par;
	
// 	for(int child : ar[node])
// 	if(child != par)
// 	{
// 		dfs(child , lvl+1 , node);
// 	}
// }


// void init(int n)
// {
// 	dfs(1 , 0 , -1);
	
// 	for(int i=1;i<=maxN;i++)
// 	{
// 		for(int j=1;j<=n;j++)
// 		if(LCA[j][i-1] != -1)
// 		{
// 			int par = LCA[j][i-1];
// 			LCA[j][i] = LCA[par][i-1];
// 		}
// 	}
// }

// int getLCA(int a , int b)
// {
// 	if(level[b] < level[a]) swap(a , b);
	
// 	int d = level[b] - level[a];
	
// 	while(d > 0)
// 	{
// 		int i = log2(d);
// 		b = LCA[b][i];
		
// 		d -= 1 << i;
// 	}
	
// 	if(a == b) return a;
	
// 	for(int i=maxN;i>=0;i--)
// 	if(LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
// 	{
// 		a = LCA[a][i] , b = LCA[b][i];
// 	}
	
// 	return LCA[a][0];
// }


// int getDist(int a , int b)
// {
// 	int lca = getLCA(a , b);
// 	return level[a] + level[b] - 2*level[lca];
// }

// int main()
// {
// 	int n ,a , b , q;
	
// 	cin>>n;
	
// 	for(int i=1;i<=n;i++)
// 	{
// 		for(int j=0;j<=maxN;j++)
// 		LCA[i][j] = -1;
// 	}
	
// 	for(int i=1;i<n;i++)
// 	cin>>a>>b , ar[a].pb(b) , ar[b].push_back(a);
	
// 	init(n);
	
// 	cin>>q;
	
// 	while(q--)
// 	{
// 		cin>>a>>b;
//         cout<<getLCA(a,b)<<"\n";
// 		cout<<getDist(a , b)<<endl;
// 	}
// }


// float maximumCompatiblityFactor(char *input1[], int input2){
// 	vector<int>a;
// 	for(int i=0; i<input2; i++){
// 		if(input1[i] != nullptr){
// 			a.push_back(atoi(input1[i]));
// 		}
// 	}
// 	sort(a.begin(), a.end());
// }



vector<int> maxS(vector<int>& nums, int k) {
	deque<int>dq;
	vector<int>ans;
	for(int i=0;i<nums.size();i++){
		if(!dq.empty() && dq.front()==i-k) dq.pop_front();
		while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
		dq.push_back(i);
		if(i>=k-1) ans.push_back(dq.front());
	}
	return ans;
}


long long solve(int n, int k, vector<int>w, vector<int>t){
	long long ans, maxAns = -1;
	while(n--){
		vector<int>temp = maxS(w, k);
		int j = 0, ans = 0;
		for(int i=0; i<t.size(); i++){
			ans += t[temp[j++]];
		}
		if(ans >= maxAns){
			maxAns = ans;
		}
		w.erase(w.begin());
	}
	return maxAns;
}

int main(){
	int n , k;
	cin >> n >> k;
	vector<int>w(n), t(n);
	for(int i=0; i<n; i++){
		cin >> w[i];
	}
	for(int i=0; i<n; i++){
		cin >> t[i];
	}
	cout << solve(n,k,w,t) << endl;
}