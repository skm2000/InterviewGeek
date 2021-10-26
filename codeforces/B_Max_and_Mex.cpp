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
    ll n, k;
    cin >> n >> k;
    vector<ll>a(n);
    set<ll>s;
    for(auto &i : a){
       cin >> i;
       s.insert(i);
    }
    ll mex=-1,max;
    sort(a.begin(),a.end());
    max = a[n-1];
    for(ll i=0; i<=max; i++){
        if(i != a[i]){
            mex = i;
            break;
        }
    }
    if(mex == -1){
        cout<<n+k<<"\n";
        return;
    }
    while(k){
        ll avg = ceil(((mex+max)*1.0)/(2*1.0));
        s.insert(avg);
        if(mex != avg){
            cout<<s.size()<<"\n";
            return;
        }
        if(mex == max+1){
            cout<<s.size()+k<<"\n";
            return;
        }
        while(1){
            mex = mex+1;
            if(s.count(mex)){
                break;
            }
        }
        k--;
    }
    cout<<s.size()<<"\n";
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