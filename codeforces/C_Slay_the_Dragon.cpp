#include <bits/stdc++.h>

using namespace std;

using li = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  int n;
  cin >> n;
  vector<li> a(n);
  for (auto &x : a) cin >> x;
  sort(a.begin(), a.end());
  li sum = accumulate(a.begin(), a.end(), 0LL);
  int m;
  cin >> m;
  while (m--) {
    li x, y;
    cin >> x >> y;
    int i = lower_bound(a.begin(), a.end(), x) - a.begin();
    li ans = 2e18;
    if (i > 0) ans = min(ans, (x - a[i - 1]) + max(0LL, y - sum + a[i - 1]));
    if (i < n) ans = min(ans, max(0LL, y - sum + a[i]));
    cout << ans << '\n';
  }
}