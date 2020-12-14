#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<char>>c(n,vector<char>(n));
    vector<vector<int>>dp(n,vector<int>(n,1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>c[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(c[i][0]=='*') dp[i][0] = 0;
    }
    for(int i=0;i<n;i++){
        if(c[0][i]=='*') dp[i][0] = 0;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(c[i][j]=='.') dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
            else dp[i][j] = 0;
        }
    }
    if(dp[0][0] == 0 || dp[n-1][n-1] == 0) cout<<0<<"\n"; 
    else cout<<dp[n-1][n-1]<<"\n";
}