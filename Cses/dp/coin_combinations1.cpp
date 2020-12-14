#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>c(n);
    for(int &i:c) cin>>i;
    vector<int>dp(x+1,0);
    dp[0] = 1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if((i-c[j]) >= 0) dp[i] = (dp[i] + dp[i-c[j]])%mod;
        }
    }
    cout<<dp[x]<<"\n";
}