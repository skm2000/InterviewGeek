#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long


void solve(){
    ll n,g,b,ans;
    cin>>n>>g>>b;
    ll x = ceil((n*1.0)/(2*1.0));
    ll m = ceil((x*1.0)/(g*1.0));
    // cout<<x<<" "<<m<<" ";
    if(m == 1){
        ans = n;
    }else{
        ans = x + ((m-1)*b);
    }
    cout<<max(ans,n)<<"\n";
}


int main(){
    ll t;
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
}