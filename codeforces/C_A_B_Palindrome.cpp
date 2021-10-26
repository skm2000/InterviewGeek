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

bool checkPalindrome(string s){
    ll n = s.size();
    // dbg(n);
    for(ll i=0; i<n/2; i++){
        if(s[i] != s[n-i-1]){
            return false;
        }
    }
    return true;
}
 

void solve(){
    ll a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    ll n = s.size();
    ll qm = 0, c0 = 0, c1 = 0;
    for(ll i=0; i<n/2; i++){
        if(s[i] == '?' && s[n-i-1] != '?'){
            s[i] = s[n-i-1];
        }else if(s[i] != '?' && s[n-i-1] == '?'){
            s[n-i-1] = s[i];
        }
    }
    for(ll i=0; i<n; i++){
        if(s[i] == '1'){
            c1++;
        }else if(s[i] == '0'){
            c0++;
        }
    }
    c0 = a - c0;
    c1 = b - c1;
    if(c0 < 0 || c1 < 0){
        cout<<-1<<"\n";
        return;
    }
    for(ll i=0; i<n/2; i++){
        if(s[i] == '?' && s[n-i-1] == '?'){
            if(c0 > 1){
                s[i] = '0';
                s[n-i-1] = '0';
                c0 -= 2;
            }else if(c1 > 1){
                s[i] = '1';
                s[n-i-1] = '1';
                c1 -= 2;
            }
        }
    }
    // dbg(c0);
    // dbg(c1);
    // cout<<s<<"\n";
    if(c0 != 0){
        for(ll i=0; i<n; i++){
            if(s[i] == '?' && c0 != 0){
                s[i] = '0';
                c0--;
            }
        }
    }
    if(c1 != 0){
        for(ll i=0; i<n; i++){
            if(s[i] == '?' && c1 != 0){
                s[i] = '1';
                c1--;
            }
        }
    }
    // dbg(c0);
    // dbg(c1);
    if(checkPalindrome(s)){
        cout<<s<<"\n";
    }
    else cout<<-1<<"\n";
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