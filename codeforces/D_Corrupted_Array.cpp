#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define vdbg(v) for(auto x : v) cout<<x<<" "
#define INF 2e18
const ll N = 1e5+7;
#define all(x) x.begin(),x.end()
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n,x = -1;
    cin >> n;
    vector<ll>a(n+2);
    for(ll i=0; i<n+2; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll sum = 0;
    for(ll i=0; i<n; i++){
        sum += a[i];
    }
    // dbg(sum);
    if(sum == a[n]){
        for(ll i=0; i<n; i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
        return;
    }else if(sum == a[n+1]){
        for(ll i=0; i<n; i++){
            cout<<a[i]<<" ";
        }
        // cout<<a[n+2]<<" "<<a[n+1]<<"\n";
        return;
    }
    for(ll i=0; i<n; i++){
        if(sum-a[i]+a[n] == a[n+1]){
            x = i;
            break;
        }
    }
    if(x != -1){
        for(ll i=0; i<n+1; i++){
            if(x != i){
                cout<<a[i]<<" ";
            }
        }
        cout<<"\n";
        // cout<<a[x]<<"\n";
        return;
    }
    cout<<-1<<"\n";
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