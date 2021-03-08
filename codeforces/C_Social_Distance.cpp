#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n,k,z=0,sum=0;
    cin>>n>>k;
    string s;
    cin>>s;
    ll seg = 2*k+1;
    if(s[0] == '0'){
        for(ll i=0;i<=min(n-1,k);i++){
            sum += s[i]-'0';
        }
        if(sum == 0){
            s[0] = '1';
            z++;
        }
    }
    sum = 0;
    if(s[n-1] == '0'){
        for(ll i=n-1;i>=max(n-1-k,0LL);i--){
            sum += s[i] - '0';
        }
        if(sum == 0){
            s[n-1] = '1';
            z++;
        }
    }
    sum = 0;
    for(ll i=0;i<n;i++){
        sum += s[i] - '0';
        if(i >= seg-1){
            if(sum == 0){
                s[i-k] = '1';
                z++;
                sum++;
            }
            if(s[i-seg+1] == '1'){
                sum--;
            }
        }
    }
    cout<<z<<"\n";
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