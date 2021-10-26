#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define vdbg(v) for(auto x : v) cout<<x<<endl
#define INF 2e18
const ll N = 1e5+7;
#define all(x) x.begin(),x.end()
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool checkPartitionPossible(vector<ll>&a) {
    ll sum=0, n = a.size();
    for(ll i=0;i<n;i++){
        sum+=a[i];
    }
    if(sum%2!=0) return false;
    bool dp[n+1][sum/2+1];
    for(ll i=0;i<=sum/2;i++){
        dp[0][i] = false;
    }
    for(ll i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=sum/2;j++){
            if(a[i-1]<=j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum/2];
}

vector<ll> convert(ll n){

    vector<ll>arr;
    while(n){
        arr.push_back(n%10);
        n/=10;
    }

    return arr;

}


void solve(){

    ll a, b;
    cin >> a >> b;
    ll ans = 0;

    for(ll i=a; i<=b; i++){
        vector<ll>arr = convert(i);
        if(checkPartitionPossible(arr)){
            ans++;
        }
    }

    cout << ans << "\n";

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