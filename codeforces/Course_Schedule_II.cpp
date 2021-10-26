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

ll n, m;
vector<ll>adj[1000000];
vector<ll>topo_sort, indegree;
 

void solve(){

    cin >> n >> m;
    indegree.resize(n,0);

    for(ll i = 0;i < m;i++){
        ll a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<ll>q;

    for(ll i=0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        ll u = q.front();
        q.pop();
        topo_sort.push_back(u);
        for(ll v: adj[u]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }

    if(topo_sort.size() != n){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for(auto v: topo_sort){
        cout << v + 1 << " ";
    }
    cout << "\n";

}


int main()
{
    fast_cin();
    ll t;
    t = 1;
    while(t--) {
        solve();
    }
    return 0;
}

// #include <bits/stdc++.h>
// #define ll long long 
// #define ld long double
// #define int long long
// using namespace std;
// const ll INF = 1e18;
// const ll MOD = 998244353;

// void solve() {
// 	int n;
// 	cin >> n;
// 	vector<pair<int, pair<int, int>>> vec;
// 	int l, r, k;
// 	for(int i = 0; i < n; i++) {
// 		cin >> l >> r >> k;
// 		vec.push_back({l, {0, k}});
// 		vec.push_back({r, {1, k}});
// 	}
// 	sort(vec.begin(), vec.end());
//     for(auto x: vec){
//         cout << x.first << " " << x.second.first << " " << x.second.second << endl;
//     }
// 	int ans = 0, pref = 0;
// 	for(auto x: vec) {
// 		if(x.second.first) {
// 			pref = max(pref, x.second.second);
// 		} else {
// 			ans = max(ans, pref + x.second.second);
// 		}
// 	}
// 	cout << ans;
// }

// int32_t main() {
// 	ios::sync_with_stdio(!cin.tie(NULL));

// 	solve();
// }


// given Inorder and Preorder traversals.
// #include<bits/stdc++.h>
// using namespace std;

// struct Result {
//     Result() : output1(){};
//     int output1[100];
// };

// struct Result decrypt(int input1[], int input2[], int input3){
//     int n = input3;
//     map<int,int> hm ;
//     Result result;
//     int preIndex = 0, x = 0;
//     for (int i = 0; i < n; i++) hm[input1[i]] = i;
//     printPost(int in[], int pre[], int inStrt,
//                 int inEnd, map<int, int> hm, Result result, int x, int preIndex);

//     return result;
// }

// void printPost(int in[], int pre[], int inStrt,
//             int inEnd, map<int, int> hm, Result result, int x, int preIndex)
// {
//     if (inStrt > inEnd)
//         return;
//     int inIndex = hm[pre[preIndex++]];
//     printPost(in, pre, inStrt, inIndex - 1, hm);
//     printPost(in, pre, inIndex + 1, inEnd, hm);
//     // cout << in[inIndex] << " ";
//     result.output1[x++] = in[inIndex];
// }


 

 
// void decrypt(int in[], int pre[],int n)
// {
    
// }
 
// Driver code
// int main()
// {
//     int in[] = { 4, 2, 5, 1, 3, 6 };
//     int pre[] = { 1, 2, 4, 5, 3, 6 };
//     int n = sizeof(pre)/sizeof(pre[0]);
     
//     decrypt(in, pre, n);
//     return 0;
// }

