#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;


int main(){
    int n,x;
    cin>>n>>x;
    vector<int>c(n);
    for(int &i:c) cin>>i;
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    for(int i=0;i<=n;i++) dp[i][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(c[i-1] <= j){
                dp[i][j] = (dp[i-1][j] + dp[i][j-c[i-1]])%mod;
            }
            else{
                dp[i][j] = dp[i-1][j]%mod;
            }
        }
    }
    cout<<dp[n][x]<<"\n";
}
