#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<"\n";
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(auto &i : a){
        cin>>i;
    }
    ll max = *max_element(a.begin(),a.end());
    ll min = *min_element(a.begin(),a.end());
    vector<ll>possible;
    for(ll i=1;i<=max;i++){
        if(min+i == max-i){
            possible.push_back(max-i);
        }
    }
    possible.push_back(min);
    possible.push_back(max);
    for(ll i=0;i<possible.size();i++){
        ll x = max-possible[i],f=1;
        for(ll j=0;j<n;j++){
            if(a[j]+x != possible[i] && a[j]-x != possible[i] && a[j] != possible[i]){
                f=0;
                break;
            } 
        }
        if(f){
            cout<<x<<"\n";
            return;
        }
    }
    cout<<-1<<"\n";
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