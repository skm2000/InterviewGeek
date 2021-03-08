#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
ll j=1;
void solve(){
    ll n,k;
    cin >> n >> k;
    vector<ll>a(n);
    for(auto &i : a){
       cin >> i;
    }
    vector<ll>p(n,1);
    for(ll i=1;i<n;i++){
        if(a[i-1]-a[i] == 1){
            p[i] = p[i-1] + 1;
        }
    }
    // dbg(p.size());
    // for(auto x: p){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";
    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(i != n-1){
            if(p[i] >= k && a[i]==1){
                ans++;
            }
        }else{
            if(p[i] == k){
                ans++;
            }
        }
    }
    cout<<"Case #"<<j<<":"<<" "<<ans<<"\n";
    j++;
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