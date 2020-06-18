// link :https://codeforces.com/problemset/problem/910/A

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n ,d;
    cin>>n>>d;
    string s;
    cin>>s;
    queue<pair<int,int>>q;
    q.push({0,0});
    int ans = -1;
    vector<int>vis(n+1);
    while(q.size()) {
        pair<int, int> p = q.front();
        q.pop();
        int pos = p.first;
        int dist = p.second;
        vis[pos] = 1;
        if(pos == n - 1) {
            ans = dist;
            break;
        }
        for(int i = 1 ; i <= d ;i++) {
            int x = i + pos;
            if(x < n and !vis[x] and (s[x] -'0')) {
                q.push({x, 1 + dist});
            }
        }
    }
    cout<<ans<<"\n";
}