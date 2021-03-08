#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    string s,p;
    cin>>n>>s>>p;
    ll i=0,ans=0;
    while(i<n){
        if(s[i] != p[i]){
            if(i+1<n && s[i+1] != p[i+1] && s[i] != s[i+1]){
                ans++;
                i+=2;
            }else{
                ans++;
                i++;
            }
        }else{
            i++;
        }
    }
    cout<<ans<<"\n";
}


int main(){
    ll t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}