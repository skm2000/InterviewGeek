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
    vector<ll>b(n);
    vector<pair<ll,ll>>p;
    for(auto &i : a){
       cin >> i;
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
        p.push_back({a[i],b[i]});
    }
    sort(p.begin(),p.end());
    // for(auto x:p){
    //     cout<<x.first<<" "<<x.second<<"\n";
    // }
    ll sum=0,ans=0;
    for(ll i=n-1;i>=0;i--){
        sum += p[i].second;
        // dbg(sum);
        if(sum > p[i].first){
            ans = max(p[i].first,sum-p[i].second);
            break;
        }else if(sum == p[i].first){
            ans = p[i].first;
            break;
        }
    }
    if(ans != 0){
        cout<<ans<<"\n";
    }else{
        for(auto x:p){
            ans += x.second;
        }
        cout<<ans<<"\n";
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