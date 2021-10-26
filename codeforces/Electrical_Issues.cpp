    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define INF 10000000
    #define ii pair<int, int>
    #define pA first
    #define pB second
    #define vi vector<int>
    #define pb push_back
     
    int A[25000];
    vi adj[25000];
     
    int getAns(int u) {
        queue<pair<int, pair<int, int>>> q; q.push({u, {u, 0}});
        while (!q.empty()) {
            auto v = q.front(); q.pop();
            for (auto x : adj[v.pA]) {
                if (x == v.pB.pA) continue;
                if (A[x] != A[u]) {
                    return v.pB.pB + 1;
                }
                q.push({x, {v.pA, v.pB.pB+1}});
            }
        }
        return -1;
    }
     
    int main() {
        int n, m; cin >> n >> m; assert(m <= 10); assert(n <= 25000);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n-1; i++) {
            int a, b; cin >> a >> b;
            adj[--a].pb(--b); adj[b].pb(a);
        }
        int q; cin >> q; assert(q <= 100000);
        for (int i = 0; i < q; i++) {
            int t; cin >> t;
            if (t == 1) {
                int x; cin >> x;
                cout << getAns(x-1) << endl;
            } else {
                int x, y; cin >> x >> y;
                A[x-1] = y;
            }
        }
        
        assert(cin.eof());
    }