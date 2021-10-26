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
    ll n,l,r;
	cin >> n >> l >> r;
	ll ans = 0;
	vector<ll> a(n+1),b(n+1);
	
	for(ll i=0; i<l; i++){
		ll tmp;
		cin >> tmp;
		a[tmp]++;
	}
	for(ll i=0; i<r; i++){
		ll tmp;
		cin >> tmp;
		b[tmp]++;
	}
	
	ll rem = n;
	
	for(ll i=1; i<=n; i++){
		ll x = min(a[i],b[i]);
		a[i] -= x;
		b[i] -= x;
		rem -= 2*x;
	}
	
	if(r < l){
		swap(l,r);
		swap(a,b);
	}
	
	// r > l
	ll mx_prs = 0;
	for(ll i=1; i<=n; i++){
		mx_prs += b[i] / 2;
	}
	
	ll transfer = (r - l) / 2;
	ans += transfer;
	ll tmp = min(transfer,mx_prs);
	
	rem -= 2*tmp;
	ans += rem / 2;
	cout << ans << "\n";
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