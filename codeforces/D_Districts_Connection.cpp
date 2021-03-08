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
    vector<ll>a(n);
    for(auto &i : a){
       cin >> i;
    }
    ll idx = -1;
    vector<pair<ll,ll>>ans;
    for(ll i=1;i<n;i++){
        if(a[i] != a[0]){
            idx = i+1;
            ans.push_back({1,i+1});
        }
    }
    if(idx == -1){
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    for(ll i=1;i<n;i++){
        if(a[i] == a[0]){
            ans.push_back({idx,i+1});
        }
    }
    for(auto x : ans){
        cout<<x.first<<" "<<x.second<<"\n";
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