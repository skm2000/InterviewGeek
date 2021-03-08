#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll n;
    cin>>n;
    string s[10]={"0","1","2","3","4","5","6","7","8","9"};
    string ans;
    if(n == 1){
        ans = "9";
    }else if(n == 2){
        ans = "98";
    }
    else{
        ans = "989";
        for(ll i=0; i<n-3;i++){
            ans += s[i%10];
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}