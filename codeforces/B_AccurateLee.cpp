#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n,f=1;
    cin>>n;
    string s,ans="";
    cin>>s;
    for(ll i=0;i<n-1;i++){
        if(s[i]>s[i+1]){
            f = 0;
            break;
        }
    }
    if(f){
        cout<<s<<"\n";
        return;
    }
    for(ll i=0;i<n;i++){
        if(s[i] == '1') break;
        ans.push_back('0');
    }
    ans.push_back('0');
    for(ll i=n-1;i>=0;i--){
        if(s[i] == '0') break;
        ans.push_back('1');
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