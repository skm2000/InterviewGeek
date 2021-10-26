#include <bits/stdc++.h>  
#define ll long long  
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

vector<ll>psquare;


void solve(){
    for(auto it : psquare){
        cout<<it<<endl;
        fflush(stdout);
        ll status;
        cin >> status;
        if(status == 1) return;
        else if(status == -1) exit(0);
    }
}


int main()
{
    // fast_cin();
    ll t;
    cin >> t;
    for(ll i=1; i<=1000; i++){
        psquare.push_back(i*i);
    }
    while(t--) {
        solve();
    }
    return 0;
}