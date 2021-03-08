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
    string s;
    cin >> s;
    ll ans = 0;
    for(ll i=0; i<s.length(); i++){
        if((s[i]-'0')%4 == 0){
            ans++;
        }
        if(i >= 1){
            if(((s[i-1]-'0')*10 + (s[i]-'0'))%4 == 0){
                ans += i;
            }
        }
    }
    cout<<ans<<"\n";
}


int main()
{
    fast_cin();
    ll t;
    // cin >> t;
    t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
