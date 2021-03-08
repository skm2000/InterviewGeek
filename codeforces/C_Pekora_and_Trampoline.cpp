#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n,ans=0;
    cin >> n;
    vector<ll>s(n+1);
    for(ll i=1; i<=n; i++){
        cin >> s[i];
    }
    vector<ll>a(n+2,0);
    for(ll i=1; i<=n; i++){
        if(s[i] != 1){
            if(i+s[i] >= n){
                for(ll j=i+2; j<=n; j++){
                    a[j]++;
                }
            }else{
                for(ll j=i+2; j<=i+s[i]; j++){
                    a[j]++;
                }
            }
        }
    }
    // for(ll i=1;i<=n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";
    for(ll i=1; i<=n; i++){
        if(s[i]-1-a[i]>0){
            ans += (s[i]-1-a[i]);
        }else{
            a[i+1] += (a[i]-s[i]+1);
        }
    }
    cout<<ans<<"\n";
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