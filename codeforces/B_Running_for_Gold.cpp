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

ll miN(vector<ll>a){
    // vdbg(a);
    // cout << "\n";
    int n = a.size(), minm = a[0], ind = 0;
    for(ll i=1; i<n; i++){
        if(a[i] < minm){
            ind = i;
            minm = a[i];
        }
    }
    return ind+1;
}
 

void solve(){
    ll n;
    cin >> n;
    vector<vector<ll>>a(n, vector<ll>(5));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<5; j++){
            cin >> a[i][j];
        }
    }
    if(n == 1){
        cout << "1\n";
        return;
    }
    vector<ll>temp(n+1,0);
    for(ll i=0; i<5; i++){
        vector<ll>a1;
        for(ll j=0; j<n; j++){
            a1.push_back(a[j][i]);
        }
        ll x = miN(a1);
        // dbg(x);
        temp[x]++;
    }
    vdbg(temp);
    cout << "\n";
    ll maxm = *max_element(temp.begin(),temp.end());
    ll cnt = 0, ans;
    for(ll i=0; i<temp.size(); i++) {
        if(temp[i] == maxm){
            cnt++;
            ans = i;
        }
    }
    if(maxm < 3){
        cout << "-1\n";
    }else{
        cout << ans << "\n";
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