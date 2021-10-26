#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
const ll N = 1e5+7;
#define all(x) x.begin(),x.end()
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
	ll n;
	cin >> n;
	ll g;
	g=n;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0) g =__gcd(g,__gcd(i,n/i));
	}
	cout<<g<<"\n";
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