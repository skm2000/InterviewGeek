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
    ll n, x;
    cin >> n >> x;
    vector<ll>a(n);
    ll eq=0,pos=0,neg=0;
    for(ll i=0; i<n; i++){
        cin >> a[i];
        if(a[i] == x){
            eq++;
        }
        if(a[i] > x){
            pos += abs(a[i]-x);
        }
        if(a[i] < x){
            neg += abs(a[i]-x);
        }
    }
    // cout<<pos<<" "<<neg<<endl;
    if(pos == neg){
        if(pos == 0){
            cout<<0<<"\n";
        }else{
            cout<<1<<"\n";
        }
    }else{
        if(eq >= 1){
            cout<<1<<"\n";
        }else{
            cout<<2<<"\n";
        }
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