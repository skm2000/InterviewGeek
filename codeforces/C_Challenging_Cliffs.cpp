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
    vector<ll>ans(n);
    for(auto &i : a){
       cin >> i;
    }
    sort(a.begin(),a.end());
    ll minm = INT_MAX;
    ll x,y,k,j=1;
    for(ll i=1; i<n; i++){
        if((a[i]-a[i-1]) < minm){
            minm = a[i] - a[i-1];
            x = a[i];
            y = a[i-1];
            k = i;
        }
    }
    ans[0] = y;
    ans[n-1] = x;
    a[k] = a[k-1] = -1;
    for(ll i=0; i<n; i++){
        if(a[i]>=x && a[i] != -1){
            ans[j++] = a[i];
        }
    }
    for(ll i=0; i<n; i++){
        if(a[i]<x && a[i] != -1){
            ans[j++] = a[i];
        }
    }
    for(auto x: ans){
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