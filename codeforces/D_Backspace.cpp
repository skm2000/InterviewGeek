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
 

void solve(){
    string s, t;
    cin >> s >> t;
    ll i = 0, j = 0, k = 0, n = s.size(), m = t.size();
    if(n < m) {
        cout << "NO\n"; 
        return;
    }
    // dbg(p);
    ll p = (n-m)&1;
    for(i=p; i<n; i++){
        if(k == 1){
            k = 0; 
            continue;
        }
        if(j < m && s[i] == t[j]){
            j++;
        }else{
            k++;
        }
    }
    if(j == m) cout << "YES\n"; else cout << "NO\n";
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