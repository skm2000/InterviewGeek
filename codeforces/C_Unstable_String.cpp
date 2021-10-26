#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
const int mod = 1000000007;
using namespace std;
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	vector<int> dp(n, 0);
	vector<int> pref(n, 0);
	pref[0] = s[0] == '?';
	for(int i = 1; i < n; i++){
		if(s[i] == '?') pref[i] = pref[i - 1] + 1;
	}
	dp[0] = 1;
	int count = 1;
	for(int i = 1; i < n; i++){
		if(s[i] != s[i - 1]){
			if(pref[i - 1] > 0){
				if(pref[i - 1] % 2 == 0){
					if(i - pref[i - 1] - 1 >= 0 and s[i - pref[i - 1] - 1] == s[i]){
						dp[i] = pref[i - 1] + 1;
					}
					else{
						dp[i] = dp[i - 1] + 1;
					}
				}
				else{
					if(i - pref[i - 1] - 1 >= 0 and s[i - pref[i - 1] - 1] != s[i]){
						dp[i] = pref[i - 1] + 1;
					}
					else{
						dp[i] = dp[i - 1] + 1;
					}
				}
			}
			else{
				dp[i] = dp[i - 1] + 1;
			}

		}
		else if(s[i] == '?'){
			dp[i] = dp[i - 1] + 1;
		}
		else{
			dp[i] = 1;
		}
	}
	for(int i = 0; i < n; ++i){
		count += dp[i];
	}
	cout << count - 1 << "\n";


}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++){
		solve();
	}
	return 0;
}

