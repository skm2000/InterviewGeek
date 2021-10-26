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
    ll x = INT_MAX, ind;
    for(ll i=0; i<n; i++){
        cin >> a[i];
        if(a[i] < x){
            ind = i;
            x = a[i];
        }
    }
    ll m1 = 1e9+7, m2 = 1e9+9;
    bool alt = false;
    cout<<n-1<<"\n";
    for(ll i=0; i<ind; i++){
        if(alt){
            a[i] = m1;
            cout<<i+1<<" "<<ind+1<<" "<<a[i]<<" "<<x<<"\n"; 
        }else{
            a[i] = m2;
            cout<<i+1<<" "<<ind+1<<" "<<a[i]<<" "<<x<<"\n"; 
        }
        alt = !alt;
    }
    for(ll i=ind+1; i<n; i++){
        if(alt){
            a[i] = m1;
            cout<<i+1<<" "<<ind+1<<" "<<a[i]<<" "<<x<<"\n"; 
        }else{
            a[i] = m2;
            cout<<i+1<<" "<<ind+1<<" "<<a[i]<<" "<<x<<"\n"; 
        }
        alt = !alt;
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