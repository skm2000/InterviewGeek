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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if(n%2 == 1){
        for(ll i=0; i<n; i+=2){
            if((s[i]-'0')%2 == 1){
                cout<<1<<"\n";
                return;
            }
        }
        cout<<2<<"\n";
    }
    else{
        for(ll i=1; i<n; i+=2){
            if((s[i]-'0')%2 == 0){
                cout<<2<<"\n";
                return;
            }
        }
        cout<<1<<"\n";
    }
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