#include <bits/stdc++.h>  
#define ll long long int
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n,k,c=0;
    cin >> n >> k;
    vector<ll>a(n+1);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        if(a[i] == 1){ 
            c++;
        }
    }
    for(ll i=1;i<=k;i++){
        ll x,y;
        cin >> x >> y;
        if(x == 1){
            a[y] = 1 - a[y];
            if(a[y] == 0){
                c--;
            }else{
                c++;
            }
        }else if(x == 2){
            if(y>c){
                cout<<0<<"\n";
            }else{
                cout<<1<<"\n";
            }
        }
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