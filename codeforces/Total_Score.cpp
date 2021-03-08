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
    ll n,k,tot=0;
    string s;
    cin>>n>>k;
    vector<ll>marks(k);
    for(auto &i : marks){
       cin >> i;
    }
    for(ll i=0;i<n;i++){
        cin>>s;
        // dbg(s);
        tot = 0;
        for(ll j=0;j<s.length();j++){
            if(s[j]=='1'){
                tot += marks[j];
            }
        }
        cout<<tot<<"\n";
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