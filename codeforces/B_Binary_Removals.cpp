#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


ll fact[MAX]; 
ll invFact[MAX];


void factorial(){
    fact[0] = 1;
    for(ll i=1;i<MAX;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
}


void modInverse(){
    invFact[0] = invFact[1] = 1;
    for(ll i=2;i<MAX;i++) invFact[i] = (mod - mod/i) * invFact[mod % i] % mod;
    for(ll i=1;i<MAX;i++) invFact[i] = (invFact[i-1] * invFact[i])%mod;
}


ll nCr(ll n, ll r){
   return (((fact[n]*invFact[r])%mod)*invFact[n-r])%mod;
}


 

void solve(){
    ll n;
    string s;
    cin>>s;
    n=s.size();
    ll noo=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='0') noo++;
    }
    if(noo==0 || noo==n){cout<<"YES"<<"\n"; return;}
    ll index=-1,nn=0;
    for(ll i=0;i<n-1;i++){
        if(s[i]=='1' && s[i+1]=='1') { index = i; break;}
    }
    if(index==-1){cout<<"YES"<<"\n"; return;}
    for(ll i=index;i<n-1;i++){
        if(s[i]=='0' & s[i+1]=='0'){
            nn=1;
            break;
        }
    }
    if(nn==0){cout<<"YES"<<"\n"; return;}
    index=-1;
    for(ll i=n-1;i>=1;i--){
        if(s[i]=='0' && s[i-1]=='0'){index=i;break;}
    }
    if(index==-1){cout<<"YES"<<"\n"; return;}
    nn=0;
    for(ll i=index;i>=1;i--){
        if(s[i]=='1' & s[i-1]=='1'){
            nn=1;break;
        }
    }
    if(nn==0){cout<<"YES"<<"\n"; return;}
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