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
   vector<ll>a(10);
   for(ll i=0;i<10;i++){
       cin>>a[i];
   }
   ll k,x;
   cin >> k;
   for(ll i=9;i>=0;i--){
       x = k;
       if(a[i]>0 && x>0){
           k -= a[i];
           if(a[i] >= x){
               a[i] -= x;
           }else{
               a[i] = 0;
           }
        //    k -= a[i];
       }
   }
   for(ll i=10;i>=0;i--){
       if(a[i]>0){
           cout<<i+1<<"\n";
           return;
       }
   }
//    cout<<"\n";
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