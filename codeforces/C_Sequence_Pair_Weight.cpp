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
    ll n;
    cin >> n;
    vector<ll>a(n);
    set<ll>s;
    ll ans = 0;
    unordered_map<ll,ll>mp;
    for(auto &i : a){
       cin >> i;
       s.insert(i);
    }
    if(s.size() == 0){
        cout<<0<<"\n";
        return;
    }
    for(ll i=0; i<n; i++){
        if(mp.count(a[i]) == 0){
            mp[a[i]] = i+1;
        }else{
            ans += (n-i) * mp[a[i]];
            mp[a[i]] += i+1;
        }
    }
    cout<<ans<<"\n";
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