#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
const ll N = 2e7+5;
#define all(x) x.begin(),x.end()
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


// * copied from uc coz of explanation
 
ll primes[N];
ll cnt[N];
void sieve(){
	for(int i=2;i<N;i++){
		if(primes[i]==0){
			for(int j=i;j<N;j+=i){
				primes[j]=1;
				cnt[j]++;
			}
		}
		primes[i]^=1;
	}
}

void solve(){
	// x is a multiple of gcd(a,b)
	
	// cL - dG = x
	
	// let y = x/G
	
	// cL/G - d = y
	
	// L/G = a/G * b/G
	
	// a/G and b/G are coprime
	
	
	// c(ab) = (y + d)
	
	// (ab) = z / c
	
	int c,d,x;
	cin >> c >> d >> x;
	
	vector<int> fact;
	for(int i = 1; i * i <= x; i++){
		if(x % i) continue;
		fact.push_back(i);
		if(i != x / i){
			fact.push_back(x / i);
		}
	}
	
	int ans = 0;
	for(int g:fact){
		int y = x / g;
		int z = y + d;
		if(z % c != 0){
			continue;
		}
		z /= c;
		ans += (1 << cnt[z]);
	}
	cout << ans << "\n";
}

int main()
{
    sieve();
    fast_cin();
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}