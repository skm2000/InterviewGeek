#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

struct node{
    ll w,v;
}a[55]; 

bool comp(node a, node b){
    if(a.v != b.v) return a.v > b.v;
    return a.w < b.w;
}

void solve(){
    ll n, m, q, l, r;
    cin >> n >> m >> q;
    for(ll i=0; i<n; i++){
        cin >> a[i].w >> a[i].v;
    }
    sort(a,a+n,comp);
    // for(ll i=0; i<n; i++){
    //     cout<<a[i].w<<" "<<a[i].v<<"\n";
    // }
    ll x[55];
    for(ll i=0; i<m; i++){
        cin >> x[i];
    }
    vector<ll>temp;
    while(q--){
        temp.clear();
        cin >> l >> r;
        l--;
        for(ll i=0; i<l; i++) temp.push_back(x[i]);
        for(ll i=r; i<m; i++) temp.push_back(x[i]);
        sort(temp.begin(),temp.end());
        ll ans = 0;
        for(ll i=0; i<n; i++){
            if(lower_bound(temp.begin(),temp.end(),a[i].w) != temp.end()){
                ans += a[i].v;
                temp.erase(lower_bound(temp.begin(),temp.end(),a[i].w));
            } 
        }
        cout<<ans<<"\n";
    }
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