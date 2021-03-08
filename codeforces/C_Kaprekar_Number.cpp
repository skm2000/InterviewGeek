#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
vector<ll>p,q,r;
set<ll>s;

bool isInrease(vector<ll>&r){
    for(ll i=0;i<r.size()-1;i++){
        if()
    }
}

void decimal(ll n){
    p.clear();
    q.clear();
    r.clear();
    ll x;
    while(n>0){
        x = n%10;
        p.push_back(x);
        q.push_back(x);
        // dbg(x);
        n /= 10;
    }
    sort(p.begin(),p.end());
    sort(q.begin(),q.end(),greater<ll>());
    for(ll i=0;i<p.size();i++){
        r.push_back(q[i]-p[i]);
    }
}

void solve(){
    ll n,k;
    cin >> n >> k;
    for(ll i=1;i<=k;i++){
        
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