#include <bits/stdc++.h>  
#define ll long long int 
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


ll XX(ll n, ll x) 
{    
    if(x>n) 
       return x; 
  
    n = n + x/2; 
    n = n - (n%x); 
    return n; 
} 
 

void solve(){
    ll p,a,b,c,ans,x=2;
    cin>>p>>a>>b>>c;
    ll x1 = XX(p,a);
    ll x2 = XX(p,b);
    ll x3 = XX(p,c);
    if(x1<p){
        x1 += a;
    }
    if(x2<p){
        x2 += b;
    }
    if(x3<p){
        x3 += c;
    }
    cout<<min({(x1-p),(x2-p),(x3-p)})<<"\n";
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