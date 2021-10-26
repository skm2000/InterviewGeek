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
 

void solve(){
    ll n, k, f, l, ans = 0;
    cin >> n >> k;
    string s,t;
    cin >> s;
    f = 0, l = n-1;
    for(ll i=0; i<n; i++){
        if(s[i] == '*'){
            ans++;
            s[i] = 'X';
            break;
        }
    }
    for(ll i=n-1; i>=0; i--){
        if(s[i] == '*'){
            ans++;
            s[i] = 'X';
            break;
        }
    }
    t = s;
    ll tans = 2;
    for(ll i=0; i<n; i++){
        if(s[i] == 'X'){
            for(ll j= min(n-1,i+k); j>=i+1; j--){
                if(s[j] == 'X') break;
                if(s[j] == '*'){
                    ans++;
                    s[j]='X';
                    break;
                }
            }
        }
    }
    s = t;
    reverse(s.begin(),s.end());
    for(ll i=0; i<n; i++){
        if(s[i] == 'X'){
            for(ll j= min(n-1,i+k); j>=i+1; j--){
                if(s[j] == 'X') break;
                if(s[j] == '*'){
                    tans++;
                    s[j]='X';
                    break;
                }
            }
        }
    }
    cout<<min(ans,tans)<<"\n";
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