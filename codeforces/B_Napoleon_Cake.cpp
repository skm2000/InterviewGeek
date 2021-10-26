#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
 


int main()
{
    // fast_cin();
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll>a(n);
        for(ll i=0;i<n;i++){
            cin >> a[i];
            // cout<<a[i]<<" ";
        }
        bool f = 0;
        for(ll i=n-1; i>=0; i--){
            ll sum = a[i];
            while(sum>0 && i>=0){
                a[i] = 1;
                sum--;
                i--;
                sum = max(sum,a[i]);
                f = 1;
            }
            if(f == 1){
                i++;
                f = 0;
            }
            // i++;
        }
        for(ll i=0; i<n; i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    // return 0;
}