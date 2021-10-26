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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll sum = 0,left = 0,ans = 0;
    for(ll i=0; i<n; i++){
        if(s[i] == 'b'){
            sum++;
        }
        while(sum > k){
            if(s[left++] == 'b'){
                sum--;
            }
        }
        ans = max(ans,i-left+1);
    }
    sum = 0,left = 0;
    for(ll i=0; i<n; i++){
        if(s[i] == 'a'){
            sum++;
        }
        while(sum > k){
            if(s[left++] == 'a'){
                sum--;
            }
        }
        ans = max(ans,i-left+1);
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