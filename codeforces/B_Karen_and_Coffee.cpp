#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
vector<ll>cnt(200012,0);
vector<ll>sum(200012,0);

void solve(){
    ll n,k,q,x,y,q1,q2;
    cin >> n >> k >> q;
    for(ll i=1;i<=n;i++){
        cin >> x >> y;
        cnt[x]++;
        cnt[y+1]--;
    }
    for(ll i=1;i<=200012;i++){
        cnt[i] += cnt[i-1];
        if(cnt[i] >= k){
            sum[i]++;
        }
    }
    for(ll i=1;i<=200012;i++){
        sum[i] += sum[i-1];
    }
    while(q--){
        cin >> q1 >> q2;
        cout<<sum[q2]-sum[q1-1]<<"\n";
    }
    // cout<<"\n";
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