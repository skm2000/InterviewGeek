
 
#include <bits/stdc++.h>
using namespace std;
 
#define int    int64_t
const int MOD = 1000000007;
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin>>T;
  for(int t=1;t<=T;t++) {
    int n,k,p;
    cin>>n>>k>>p;
    int dp[n+1][p+1];
    int a[n+1][k+1];
    memset(dp,0,sizeof(dp));
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++)
      for(int j=1;j<=k;j++)
        cin>>a[i][j];
    for(int i=1;i<=n;i++) {
      int sum=0;
      for(int j=0;j<=min(p,k);j++) {
        sum+=a[i][j];
        for(int z=j;z<=p;z++) {
          dp[i][z]=max(dp[i][z],dp[i-1][z-j]+sum);
        }
      }
    }
    cout<<"Case #"<<t<<": "<<dp[n][p]<<"\n";
  }
}