#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n,k;
    cin>>n>>k;
    if(k>n){
        cout<<"NO"<<"\n";
        return;
    }else{
        ll x = n-k+1;
        if(x&1 && x>0){
            cout<<"YES"<<"\n";
            for(ll i=0;i<k-1;i++){
                cout<<1<<" ";
            }
            cout<<x<<"\n";
            return;
        }
        x = n-(2*(k-1));
        if(x%2==0 && x>0){
            cout<<"YES"<<"\n";
            for(ll i=0;i<k-1;i++){
                cout<<2<<" ";
            }
            cout<<x<<"\n";
            return;
        }
        cout<<"NO"<<"\n";
        return;
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