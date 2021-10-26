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
    ll n = 3;
    vector<pair<int,int>>p(n);
    for(ll i=0; i<n; i++){
        cin >> p[i].first >> p[i].second;
        // cout<<p[i].first << " " << p[i].second<<"\n";
    }
    if(p[0].first != p[1].first && p[0].second != p[1].second){
        cout<<abs(p[0].first - p[1].first) + abs(p[0].second - p[1].second)<<"\n";
        return;
    }
    if(p[0].first == p[1].first && p[0].first == p[2].first && ((p[0].second > p[2].second && p[2].second > p[1].second) || 
    (p[1].second > p[2].second && p[2].second > p[0].second))){
        cout<<abs(p[0].second - p[1].second) + 2 <<"\n";
        return;
    }
    if(p[0].second == p[1].second && p[0].second == p[2].second && ((p[0].first > p[2].first && p[2].first > p[1].first) || 
    (p[1].first > p[2].first && p[2].first > p[0].first))){
        cout<<abs(p[0].first - p[1].first) + 2 <<"\n";
        return;
    }
    cout<<abs(p[0].first - p[1].first) + abs(p[0].second - p[1].second)<<"\n";
    return;
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