#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    string s;
    cin>>s;
    ll n = s.length(),ans=0;
    if(n == 1){
        cout<<0<<"\n";
        return;
    }
    for(ll i=1;i<n;i++){
        if((s[i] == s[i-1]) || ((s[i] == s[i-2]) && (i-2 >= 0))){
            s[i] = '#';
            ans++;
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