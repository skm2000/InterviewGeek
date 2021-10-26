#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
const ll N = 1e5+7;
#define all(x) x.begin(),x.end()
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll Idconvert(string s1,string s2){
    ll m = s1.length(),n=s2.length(),lcs;
    ll dp[m+1][n+1];
    for(ll i=0;i<=m;i++){
        for(ll j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    ll maxm = 0;
    for(ll i=0;i<=m;i++){
        for(ll j=0;j<=n;j++){
            maxm = max(maxm,dp[i][j]);
        }
    }
    // lcs = dp[m][n];
    // cout<<"Minimum Insertions : "<<m-lcs<<"\n";
    // cout<<"Minimum Deletions : "<<n-lcs<<"\n";
    return m+n-(2*maxm);
}

 

void solve(){
    string a, b;
    cin >> a >> b;
    cout<<Idconvert(a,b)<<"\n";
}


int main()
{
    fast_cin();
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}