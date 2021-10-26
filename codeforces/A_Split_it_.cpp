#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(){
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(k == 0){
        cout<<"YES"<<"\n";
        return;
    }
    ll i=0,j=n-1;
    while(i<j){
        if(s[i] != s[j]){
            cout<<"NO"<<"\n";
            return;
        }else{
            k--;
        }
        if(k == 0 && n&1){
            cout<<"YES"<<"\n";
            return;
        }else if(k<0 && n%2==0){
            cout<<"YES"<<"\n";
            return;
        }
        i++;
        j--;
    }
    cout<<"NO"<<"\n";
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