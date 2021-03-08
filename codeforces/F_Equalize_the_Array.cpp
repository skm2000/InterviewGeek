#include <bits/stdc++.h>  
#define ll long long  
using namespace std;
ll MOD = 998244353;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    unordered_map<ll,ll>mp;
    for(auto &i : a){
        cin>>i;
        mp[i]++;
    }
    vector<ll>cnts;
    for(auto x:mp){
        cnts.push_back(x.second);
    }
    sort(cnts.begin(),cnts.end());
    ll ans = INF;
    for(ll i : cnts){
        ll small = lower_bound(cnts.begin(),cnts.end(),i) - cnts.begin();
        ll big = cnts.size() - small;
        ans = min(ans,n-i*big);
    }
    cout<<ans<<"\n";
}


int main()
{
    // fast_cin();
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}