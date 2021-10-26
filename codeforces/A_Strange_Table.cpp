#include <bits/stdc++.h>  
#define ll long long int
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
const ll N = 1e5+7;
#define all(x) x.begin(),x.end()
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n, m , x;
    cin >> n >> m >> x;
    if(x == 1){
        cout<<1<<"\n";
        return;
    }
    ll c = x/n;
    if(x%n == 0) c = c - 1;
    ll r = x-c*n;
    cout<<(r-1)*m + c + 1 <<"\n";
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