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
        cin>>n;
        vector<ll>v(n),vv(n);
        map<ll,ll> mp,mpp;
        for(ll i=0;i<n;i++){
            cin>>v[i];
            mp[v[i]]++;
        }
        ll to=0,id=0;
        for(ll i=0;i<n;i++){
            if(mp[i]==0) {
                break;
            }
            mpp[id]++;
            vv[id]=i;
            id++;
        }
        for(ll i=0;i<=200;i++){
            for(ll j=mpp[i]+1;j<=mp[i];j++){
                vv[id]=i;
                id++;
            }
        }
        for(ll i=0;i<vv.size();i++) cout<<vv[i]<<" ";
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