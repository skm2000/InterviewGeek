#include <bits/stdc++.h>
#define ll long long 
#define ld long double
#define int long long
using namespace std;
const ll INF = 1e18;
const ll MOD = 998244353;
 
 
 
int32_t main() {
	ios::sync_with_stdio(!cin.tie(NULL));
 
	int tc;
	cin >> tc;
	while(tc--) {
		int n, k;
		cin >> n >> k;
		int sum;
		cin >> sum;
		int res = 0;
		int tmp;
		for(int i = 1; i < n; i++) {
			cin >> tmp;
			int now = (tmp * 100ll) - (k * sum);
			if(now > 0) res = max(res, (now + k - 1) / k);
			sum += tmp;
		}
		cout << res << "\n";
	}
}