#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    string ans="";
    cin>>n;
    if(n%2 == 0){
        for(ll i=0;i<n/2;i++){
            ans += "1";
        }
    }else{
        ans += "7";
        for(ll i=0;i<(n-3)/2;i++){
            ans += "1";
        }
    }
    cout<<ans;
}


int main(){
    ll t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}