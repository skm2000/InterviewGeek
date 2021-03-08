#include <bits/stdc++.h>  
#define ll long long  
using namespace std;
ll MOD = 998244353;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
	ll n;
	cin>>n;
	vector<ll>a(n);
	vector<ll>f(3,0);
	for(auto &i :a){
		cin>>i;
		f[i%3]++;
	}
	ll moves=0;
	while(1){
		for(ll i=0;i<3;i++){
			if(f[i]>n/3){
				ll d = f[i]-n/3;
				f[(i+1)%3] += d;
				moves += d;
				f[i] -= d;
			}
		}
		bool stop=1;
		for(ll i=0;i<3;i++){
			if(f[i] != n/3){
				stop = 0;
				break;
			}
		}
		if(stop){
			break;
		}
	}
	cout<<moves<<"\n";
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