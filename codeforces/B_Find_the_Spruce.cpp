#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>>a(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] == '*') dp[i][j] = 1;
            }
        }
        int ans = 0;
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<m-1;j++){
                if(dp[i][j] == 1) dp[i][j] = 1 + min({dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans += dp[i][j];
            }
        }
        cout<<ans<<"\n";
    }
}