#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>prices(n);
    vector<int>pages(n);
    for(int i=0;i<n;i++) cin>>prices[i];
    for(int i=0;i<n;i++) cin>>pages[i];
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(prices[i-1] <= j) dp[i][j] = max(dp[i-1][j],pages[i-1]+dp[i-1][j-prices[i-1]]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][x]<<"\n";
}