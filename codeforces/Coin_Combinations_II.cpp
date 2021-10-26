#include<bits/stdc++.h>
const int mod = 1000000007;
using namespace std;
int n, k;
int arr[105];
 
int solve(int i, int left, vector<vector<int>> &dp) {
    if(left < 0) return 0;
    if (left == 0) return 1;
    if (i >= n) return 0;
    if (dp[i][left] != 0) return dp[i][left];
    dp[i][left] = solve(i + 1, left, dp) % mod;
    return dp[i][left] += solve(i, left - arr[i], dp) % mod;
}
int main() {
    cin >> n >> k;
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    cout << solve(0, k, dp);
}