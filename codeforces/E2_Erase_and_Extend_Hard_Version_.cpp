#include <bits/stdc++.h>
#define ll long long 
#define ld long double
#define int long long
using namespace std;
const ll INF = 1e18;
const ll MOD = 998244353;

int t[2000000];

void build(int v, int tl, int tr) {
	if(tl == tr)	t[v] = INF;
	else {
		t[v] = INF;
	}
}

void update(int v, int tl, int tr, int pos, int val) {
	if(tl == tr)	t[v] = val;
	else {
		int tm = (tl + tr) / 2;
		if(pos <= tm) update(v*2, tl, tm, pos, val);
		else	update(v*2 + 1, tm + 1, tr, pos, val);
		t[v] = min(t[v*2], t[v*2 + 1]);
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if(l > r)	return INF;
	if(tl == l and tr == r)		return t[v];
	else {
		int tm = (tl + tr) / 2;
		return min(query(v*2, tl, tm, l, min(tm, r)), query(v*2 + 1, tm + 1, tr, max(tm + 1, l), r));
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> vec(n + 1);
	int l, r;
	build(1, 0, n);
	for(int i = 0; i < m; i++) {
		cin >> l >> r;
		vec[r].push_back(l);
	}
	update(1, 0, n, 0, 0);
	int res = INF;
	for(int i = 1; i <= n; i++) {
		int cur = INF;
		for(int li : vec[i]) {
			cur = min(cur, query(1, 0, n, li - 1, i - 1) + i - li + 1);
		}
		update(1, 0, n, i, cur);
	}
	int cur = query(1, 0, n, n, n);
	if(cur == INF) cout << -1 << "\n";
	else	cout << cur << "\n";
}

