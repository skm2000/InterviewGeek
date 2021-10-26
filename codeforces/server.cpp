// #include <bits/stdc++.h>  
// #define ll long long  
// const ll mod = 1000000007;  
// using namespace std;
// ll MOD = 998244353;
// #define MAX 1000007
// #define dbg(x) cout<<#x<<" = "<<x<<endl
// #define vdbg(v) for(auto x : v) cout<<x<<endl
// #define INF 2e18
// #define all(x) x.begin(),x.end()
// #define mem0(a) memset(a,0,sizeof(a))
// #define mem1(a) memset(a,-1,sizeof(a))
// #define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


// vector<bool> is_prime;

// void sieve(int N){
//     is_prime.resize(N+1, true);
//     is_prime[0] = is_prime[1] = false;
//     for (int i = 2; i * i <= N; i++) {
//         if (is_prime[i]) {
//             for (int j = i * i; j <= N; j += i)
//                 is_prime[j] = false;
//         }
//     }
// }


// void solve(){
//     int n, k;
//     cin >> n >> k;
//     vector<int>a(n);
//     for(auto &i : a){
//        cin >> i;
//     }
//     int maxm = *max_element(a.begin(),a.end());
//     sieve(maxm);
//     vector<int>primes;
//     vector<int>ans(n,-1);

//     for(int i=0; i<n; i++){
//         if(is_prime[a[i]]){
//             ans[i] = 0;
//             primes.push_back(i);
//         }
//     }

//     int sum = 0;

//     if(primes.size() == 0){
//         cout << 0 << "\n";
//         return;
//     }

//     int now = 0;
//     for(int i=0; i<n; i++){
//         if(abs(primes[now]-i) <= k && ans[i] == -1){
//             ans[i] = abs(primes[now]-i);
//         }
//     }

// }


// int main()
// {
//     fast_cin();
//     ll t;
//     cin >> t;
//     while(t--) {
//         solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>  
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(auto &i : a){
       cin >> i;
    }
    vector<int>lmin(n);
    vector<int>rmax(n);
    lmin[0] = a[0];
	for (int i = 1; i < n; ++i)
		lmin[i] = min(a[i], lmin[i - 1]);

	rmax[n - 1] = a[n - 1];
	for (int j = n - 2; j >= 0; --j)
		rmax[j] = max(a[j], rmax[j + 1]);

	int i = 0, j = 0, maxDiff = -1;
	while (j < n && i < n) {
		if (lmin[i] <= rmax[j]) {
			maxDiff = max(maxDiff, j - i);
			j = j + 1;
		}
		else
			i = i + 1;
	}
    cout << maxDiff << "\n";
}


// int main()
// {
//     solve();
//     return 0;
// }


int main()
{
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}