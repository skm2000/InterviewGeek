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
 

// void solve(){
//     ll n;
//     cin >> n;
//     vector<ll>a(n);
//     for(auto &i : a){
//        cin >> i;
//     }
//     set<ll>s;
//     ll curr = 0, ans = 0;
//     s.insert(0);
//     for(ll i=0; i<n; i++){
//         curr += a[i];
//         if(s.find(curr) != s.end()){
//             ans++;
//             s.clear();
//             s.insert(0);
//             curr = a[i];
//         }
//         s.insert(curr);
//     }
//     cout << ans << "\n";
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

// bool isPrime(int n){
//     if(n%3 == 0 || n%5 == 0 || n%7 == 0) return true;
//     return false;
// }

// void solve(){
//     string s;
//     cin >> s;
//     int n = s.size();
//     int diff1 = 0, diff2 = 0, diff = 0;
//     for(int i=0; i<n; i++){
//         if(i & 1){
//             diff1 += int(s[i]);
//             // dbg(diff1);
//         }
//         else{
//             diff2 += int(s[i]);
//             // dbg(diff2);
//         }
//     }
//     dbg(diff1);
//     dbg(diff2);
    
//     diff = abs(diff1 - diff2);
//     dbg(diff);
//     if(isPrime(diff)){
//         cout << "Prime String\n";
//     }
//     else{
//         cout << "Casual String\n";
//     }
// }


void dfs(int v, int p, vector<pair<int, int>> t[], int h, vector<int>&ans)
{
	for(pair<int, int> u : t[v])
	{
		if (u.first == p)
			continue;
		dfs(u.first, v, t, h + u.second, ans);
	}
	ans[v] = h;
}
void solving(int n, int h, vector<int>&hide, int edges[][3])
{
	vector<pair<int, int>> t[n];
    vector<vector<int>>all;
    unordered_set<int>vis_h;
    for(auto &x : hide){
        vis_h.insert(x);
    }
	for(int i = 0; i < n - 1; i++)
	{
		t[edges[i][0]].push_back({edges[i][1], edges[i][2]});
		t[edges[i][1]].push_back({edges[i][0], edges[i][2]});
	}
    unordered_set<int>keep;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		vector<int>ans(n);
		dfs(i, -1, t, 0, ans);
		all.push_back(ans);
	}
    // for(auto &x : vis_h){
    //     cout << x << " " << endl;
    // }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << all[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    using pii = pair<int, pair<int,int> >;
    vector<int>put_max;
    priority_queue<pii>pq;
    for(int i = 0; i < n; i++){
        if(vis_h.count(i) > 0){
            int maxm = -1, ind = -1;
            for(int j = 0; j < n; j++){
                if(vis_h.count(j) > 0){
                    pq.push({all[i][j], {i,j}});
                }
            }
        }
    }
    while(!pq.empty()) {
        int f = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cnt = 0;
        // cout << f << " " << x << " " << y << endl;
        if(keep.count(x) == 0 && keep.count(y) == 0 && cnt <= h/2){
            keep.insert(x);
            keep.insert(y);
            sum += f;
            cnt++;
        }
        pq.pop();
    }
    cout << sum << "\n";
}

void solve(){
    ll n, h;
    cin >> n >> h;
    vector<int>hide(h);
    for(auto &i : hide){
        cin >> i;
        i--;
    }
    int edges[n-1][3];
    for(int i=0; i<n-1; i++){
        int u,v;
        cin >> u >> v;
        u--, v--;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = 1;
    }
    solving(n, h, hide, edges);
}

int main()
{
    int t;
    t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
