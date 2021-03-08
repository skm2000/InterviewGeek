#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

ll a1[26],a2[26][26];

void solve(){
    string s;
    cin >> s;
    for(ll i=0; i<s.size(); i++){
        int c = s[i]-'a';
        for(ll j=0; j<26; j++){
            a2[c][j] += a1[j];
        }
        a1[c]++;
    }
    ll ans = 0;
    for(ll i=0; i<26; i++){
        ans = max(ans,a1[i]);
    }
    for(ll i=0; i<26; i++){
        for(ll j=0; j<26; j++){
            ans = max(ans,a2[i][j]);
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