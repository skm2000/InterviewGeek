#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


ll second_min(ll a,ll b,ll c){
    
} 

void solve(){
    ll n;
    cin >> n;
    vector<ll>a(n);
    queue<ll>q;
    set<ll>s;
    for(auto &i : a){
       cin >> i;
       q.push(i);
    }
    ll m1 = q.front();
    q.pop();
    while(!q.empty()){
        ll m2 = q.front();
        q.pop();
        
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