#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

bool comp(pair<ll,ll>&a,pair<ll,ll>&b){
    if(a.first > b.first){
        return true;
    }
    if(a.first<b.first) return false;
    if(a.second>b.second) return false;
    return true;
}


void solve(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>>p;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        p.push_back({a[i],i});
    }
    sort(p.begin(), p.end(),comp);
    ll k=1;
    for(auto x:p){
        // cout<<x.first<<" "<<x.second<<"\n";
        // dbg(x.second);
        a[x.second] = k++;
    }
    for(auto x:a){
        cout<<x<<" ";
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