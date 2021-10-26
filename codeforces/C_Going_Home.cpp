#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 100000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll M = 5e6+10; 
pair<ll,ll>p[M];
void solve(){
    ll n;
    cin >> n;
    vector<ll>a(n+1);
    for(ll i=1; i<=n; i++){
        cin >> a[i];
    }
    for(ll i=1; i<=n; i++){
        for(ll j=i+1; j<=n; j++){
            ll tmp = a[i] + a[j];
            if(!p[tmp].first) p[tmp] = {i,j};
            else{
                if(i!=p[tmp].first && i!=p[tmp].second && j!=p[tmp].first && j!=p[tmp].second){
                    cout<<"YES"<<"\n";
                    cout<<i<<" "<<j<<" "<<p[tmp].first<<" "<<p[tmp].second<<"\n";
                    return;
                }
            }
        }
    }
    cout<<"NO"<<"\n";
}


int main()
{
    fast_cin();
    ll t;
    // cin >> t;
    t = 1;
    while(t--) {
        solve();
    }
    return 0;
}