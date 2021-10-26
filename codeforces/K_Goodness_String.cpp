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

ll pallindrome(string s){
    ll g = 0, n = s.size();
    for(ll i=0; i<n/2; i++){
        if(s[i] != s[n-i-1]){
            g++;
        }
    }
    return g;
} 

void solve(){
    
}


int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(ll i=1; i<=t; i++){
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll check_goodness = pallindrome(s);
        cout<<"Case #"<<i<<":"<<" "<<abs(check_goodness-k)<<"\n";
    }
    return 0;
}