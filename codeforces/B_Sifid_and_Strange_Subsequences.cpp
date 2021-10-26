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
	vector<ll> arr(n);
	for(ll &i:arr){
		cin >> i;
	}
	if(n == 1){
		cout<<"1\n";
		return;
	}
	sort(arr.begin(),arr.end());
	if(arr[0] > 0){
		cout<<"1\n";
		return;
	}
	ll minDiff = arr[1] - arr[0];
	ll ans = 1;
	for(ll i=1;i<n;i++){
		minDiff = min(arr[i] - arr[i-1],minDiff);
		if(arr[i] <= minDiff){
			ans++;
		}else{
			break;
		}
	}
	cout<<ans<<"\n";
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