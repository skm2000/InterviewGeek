#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, target;
  cin >> n >> target;
  vector<int> c(n);
  for (int&v : c) cin >> v;

  vector<int> dp(target+1,1e9);
  dp[0] = 0;
  for (int i = 1; i <= target; i++) {
    for (int j = 0; j < n; j++) {
      if (i-c[j] >= 0) {
	dp[i] = min(dp[i], dp[i-c[j]]+1);
      }
    }
  }
  cout << (dp[target] == 1e9 ? -1 : dp[target]) << endl;
}