#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    int dp[n+2][m+2];
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int x=1;x<=m;x++){
            if(i == 1){
                if(a[i]==0 || a[i]==x) dp[i][x] = 1;
                else dp[i][x] = 0;
            }else{
                if(a[i]==0 || a[i]==x) dp[i][x] = ((dp[i-1][x-1] + dp[i-1][x])%mod + dp[i-1][x+1]%mod)%mod;
                else dp[i][x] = 0;
            }
        }
    }
    int ans = 0;
    for(int x=1;x<=m;x++){
        ans = (ans + dp[n][x])%mod;
    }
    cout<<ans;
}