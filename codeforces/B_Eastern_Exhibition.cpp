#include <bits/stdc++.h>
#define ll long long 
#define ld long double
#define int long long
using namespace std;
const ll INF = 1e18;
const ll MOD = 998244353;
 
void solve() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	if(n&1)		{
		cout << 1 << "\n";
		return;
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int a = x[(n / 2)] - x[(n / 2) - 1];
	int b = y[(n / 2)] - y[(n / 2) - 1];
	a++, b++;
	cout << a * b << "\n";
}
 
int32_t main() {
	ios::sync_with_stdio(!cin.tie(NULL));
		
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}