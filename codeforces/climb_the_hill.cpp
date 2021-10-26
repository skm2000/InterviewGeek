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
    for(auto &i : a){
       cin >> i;
    }

    ll ans1 = 0, ans2 = 0;

    priority_queue<ll, vector<ll>, greater<ll>>min_heap;
    for(ll i=0; i<n; i++){
        if(!min_heap.empty() && min_heap.top() < a[i]){
            ll diff = a[i]-min_heap.top();
            ans1 += diff;
            min_heap.pop();
        }
        min_heap.push(a[i]);
    }

    priority_queue<ll>max_heap;
    for(ll i=0; i<n; i++){
        if(!max_heap.empty() && max_heap.top() > a[i]){
            ll diff = max_heap.top()-a[i];
            ans2 += diff;
            max_heap.pop();
        }
        max_heap.push(a[i]);
    }

    //cout << ans1 << " " << ans2 << endl;
    cout << min(ans1,ans2) << "\n";
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