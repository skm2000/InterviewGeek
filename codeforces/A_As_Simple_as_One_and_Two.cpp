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
    s = '$'+s;
    vector<ll>ind;
    for(ll i=1; i<=s.length(); i++){
        string x = s.substr(i,5);
        if(x == "twone"){
            s[i+2] = 'x';
            ind.push_back(i+2);
            i += 4;
        }
    }
    for(ll i=1; i<=s.length(); i++){
        string x = s.substr(i,3);
        if(x == "two" || x == "one"){
            // s[i+2] = 'x';
            ind.push_back(i+1);
            i += 2;
        }
    }
    cout<<ind.size()<<"\n";
    for(auto x : ind){
        cout<<x<<" ";
    }
    cout<<"\n";
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