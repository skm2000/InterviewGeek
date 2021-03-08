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
    ll n,x;
    cin>>n>>x;
    vector<ll>a(n);
    vector<ll>b(n);
    for(auto &i : a){
       cin >> i;
    }
    for(auto &i : b){
       cin >> i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(),greater<ll>());
    for(ll i=0;i<n;i++){
        if(a[i]+b[i] > x){
            cout<<"No"<<"\n";
            return;
        }
    }
    cout<<"Yes"<<"\n";
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