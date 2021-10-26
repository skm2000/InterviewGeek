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
    string s;
    cin >> s;
    for(ll i=1; i<n; i++){
        if(i != n-1){
            if(s[i] == s[i+1] && s[i] == s[i-1]){
                if(s[i-1] == 'R') s[i] = 'B';
                if(s[i-1] == 'B') s[i] = 'G';
                if(s[i-1] == 'G') s[i] = 'R';
                ans++;
            }
            else if(s[i] == s[i-1]){
                if(s[i-1] == 'R' && s[i+1] == 'B') s[i] = 'G';
                if(s[i-1] == 'R' && s[i+1] == 'G') s[i] = 'B';
                if(s[i-1] == 'B' && s[i+1] == 'R') s[i] = 'G';
                if(s[i-1] == 'B' && s[i+1] == 'G') s[i] = 'R';
                if(s[i-1] == 'G' && s[i+1] == 'R') s[i] = 'B';
                if(s[i-1] == 'G' && s[i+1] == 'B') s[i] = 'R';
                ans++;
            }
        }else{
            if(s[i] == s[i-1]){
                if(s[i-1] == 'R') s[i] = 'B';
                if(s[i-1] == 'B') s[i] = 'G';
                if(s[i-1] == 'G') s[i] = 'R';
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    cout<<s<<"\n";
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