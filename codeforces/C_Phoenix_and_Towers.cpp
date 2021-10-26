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
    ll n, m, x;
    cin >> n >> m >> x;
    vector<pair<ll,ll>>p(n);
    for(ll i=0; i<n; i++){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p.begin(), p.end());
    // for(ll i=0; i<n; i++){
    //     cout<<p[i].first<<" "<<p[i].second<<"\n";
    // }
    vector<ll>ans(n);
    for(ll i=0; i<n; i++){
        ans[p[i].second] = i%m + 1;
    }
    cout<<"YES"<<"\n";
    for(auto it : ans){
        cout<<it<<" ";
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