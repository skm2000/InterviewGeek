#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll>dp(n+1,0);
    dp[0] = 1;
    for(ll i=1;i<=n;i++){
        for(int x=1;x<=6;x++){
            if(x <= i){
                dp[i] = (dp[i] + dp[i-x])%mod;
            }
        }
    }
    cout<<dp[n]<<"\n";
}