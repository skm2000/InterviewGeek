// #include <bits/stdc++.h>  
// #define ll long long  
// const ll mod = 1000000007;  
// using namespace std;
// ll MOD = 998244353;
// #define MAX 1000007
// #define dbg(x) cout<<#x<<" = "<<x<<endl
// #define vdbg(v) for(auto x : v) cout<<x<<endl
// #define INF 2e18
// const ll N = 1e5+7;
// #define all(x) x.begin(),x.end()
// #define mem0(a) memset(a,0,sizeof(a))
// #define mem1(a) memset(a,-1,sizeof(a))
// #define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// pair<ll,ll> Ratio(ll d, ll k){
//     ll g = __gcd(d,k);
//     d /= g;
//     k /= g;
//     return {d,k};
// }
 

// void solve(){
//     ll n;
//     cin >> n;
//     string s;
//     cin >> s;
//     ll d = 0, k = 0;
//     map<pair<ll,ll>,ll>mp;
//     for(char c : s){
//         if(c == 'D') d++;
//         else k++;
//         cout << ++mp[Ratio(d,k)] << " ";
//     }
//     cout << "\n";
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
    ll n, k;
    cin >> n >> k;
    vector<ll>a(n);
    ll ev = 0;
    for(ll i=0; i<n; i++){
        cin >> a[i];
        if(a[i]%2 == 0){
            ev++;
        }
    }
    ll ans = 0, maxans = 0;
    for(ll i=0; i<n; i++){
        if(a[i] & 1){
            ans = 1;
            for(ll j=i+k; j<n; j+=k){
                if(a[j]&1){
                    ans++;
                }
            }
            maxans = max(maxans,ans);
        }
    }
    cout << n-maxans-ev << "\n";
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