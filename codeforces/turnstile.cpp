// #include <bits/stdc++.h>  
// #define ll long long  
// const ll mod = 1000000007;  
// using namespace std;
// ll MOD = 998244353;
// #define MAX 1000007
// #define dbg(x) cout<<#x<<" = "<<x<<endl
// #define vdbg(v) for(auto x : v) cout<<x<<endl
// #define INF 2e18
// const ll N = 1e5+7;
// #define all(x) x.begin(),x.end()
// #define mem0(a) memset(a,0,sizeof(a))
// #define mem1(a) memset(a,-1,sizeof(a))
// #define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// vector<ll> getTimeStamps(vector<ll>&time, vector<ll>&dir) {
//     ll n = time.size();
//     time.push_back(1e9);
//     vector<ll> out(n);
//     queue<ll> q[2]; // enter(0), exit(1)
//     ll t = time[0], fl = -1;
//     for (ll i = 0; i < n; i++) {
//         q[dir[i]].push(i);
//         while (t < time[i + 1]) {
//             if (!q[0].empty() && fl == 0) {
//                 out[q[0].front()] = t++;
//                 q[0].pop();
//                 fl = 0;
//             }
//             else if (!q[1].empty()) {
//                 out[q[1].front()] = t++;
//                 q[1].pop();
//                 fl = 1;
//             }
//             else if (!q[0].empty()) {
//                 out[q[0].front()] = t++;
//                 q[0].pop();
//                 fl = 0;
//             }
//             else {
//                 t = time[i + 1];
//                 fl = -1;
//             }
//         }
//     }
//     return out;
// }
 

// void solve(){
//     ll n;
//     cin >> n;
//     vector<ll>time(n);
//     vector<ll>dir(n);
//     for(auto &i : time){
//        cin >> i;
//     }
//     for(auto &i : dir){
//        cin >> i;
//     }

//     auto ans = getTimeStamps(time, dir);
//     for(auto &i : ans){
//         cout << i << " ";
//     }
//     cout << "\n";
// }


// int main()
// {
//     fast_cin();
//     ll t;
//     cin >> t;
//     while(t--) {
//         solve();
//     }
//     return 0;
// }

// class Node{
// public:
//     int val;
//     vector<Node*> children;
    
//     Node() {}
//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };
// double ans=INT_MIN;
// Node *res;
// vector<double> dfs(Node *node){
//     if(!node){
//         return {0,0};
//     }
//     double currVal=node->val;
//     double count=1;
//     for(auto child:node->children){
//         vector<double> temp=dfs(child);
//         count+=temp[1];
//         currVal+=temp[0];
//     }
//     double avg=currVal/count;
//     if(count>1 && avg>ans){
//         ans=avg;
//         res=node;
//     }
//     return {currVal,count};
// }
// int maximumAverageSubtree(Node *root){
//     if(!root){
//         return 0;
//     }
//     dfs(root);
//     return res->val;
// }
// int main() {
//     Node *node0=new Node(20);
//     Node *node1=new Node(12);
//     Node *node2=new Node(18);
//     Node *node3=new Node(11);
//     Node *node4=new Node(2);
//     Node *node5=new Node(3);
//     Node *node6=new Node(15);
//     Node *node7=new Node(8);
//     node0->children={node1,node2};
//     node1->children={node3,node4,node5};
//     node2->children={node6,node7};
//     int ans=maximumAverageSubtree(node0);
//     cout << ans << endl;
//     return 0;
// }


// #include <bits/stdc++.h>  
// #define ll long long  
// const ll mod = 1000000007;  
// using namespace std;
// ll MOD = 998244353;
// #define MAX 1000007
// #define dbg(x) cout<<#x<<" = "<<x<<endl
// #define vdbg(v) for(auto x : v) cout<<x<<endl
// #define INF 2e18
// const ll N = 1e5+7;
// #define all(x) x.begin(),x.end()
// #define mem0(a) memset(a,0,sizeof(a))
// #define mem1(a) memset(a,-1,sizeof(a))
// #define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

// void solve(){
//     int n, k;
//     cin >> n >> k;
//     vector<int>a(n);
//     unordered_map<int, unordered_set<int>>mp;
//     for(auto &i : a){
//        cin >> i;
//     }
//     int x = 1, j=-1;
//     for(int i=0; i<n; i++){
//         if(x <= k){
//             if(mp[x].count(a[i]) == 0){
//                 mp[x].insert(a[i]);
//             }else{
//                 x++;
//                 if(x <= k) mp[x].insert(a[i]);
//             }
//         }else{
//             mp[k].insert(a[i]);
//         } 
//     }
//     int ans = 0;
//     for(auto x: mp){
//         ans += x.second.size();
//     }
//     cout << ans << "\n";
// }


// int main()
// {
//     fast_cin();
//     ll t;
//     cin >> t;
//     while(t--) {
//         solve();
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<long long> count_triplets(int n, vector<int>a, int b){
    vector<long long>ans(b,0);
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                int m = (a[i] + a[j] + a[k]) % b;
                cout << m << " ";
                ans[m]++;
            }
        }
    }
    return ans;
}


// int main()
// {
//     ll t;
//     cin >> t;
//     while(t--) {
//         ll n, b;
//         cin >> n;
//         vector<int>a(n);
//         for(auto x: a) {
//             cin >> x;
//         }
//         cin >> b;
//         vector<ll> ans = count_triplets(n, a, b);
//         // for(auto x: ans) {
//         //     cout << x << " ";
//         // }
//         // cout << endl;
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;


// void solve(vector<int> a, int n, int b){
//     vector<int> ans(b,0);
//     for(int i=0;i<n-2;i++){
//         for(int j=i+1; j<n-1;j++){
//             for(int k=j+1;k<n;k++){
//                 int t = (a[i] + a[j] + a[k]) % b;
//                 ans[t]++;
//             }
//         }
//     }
//     for(auto x : ans)
//         cout<<x<<" ";
// }


// int main(){

//     int n = 4;
//     vector<int> a {4, 8, 9, 8};
//     int b = 5;

    
//      solve(a,n,b);

// }