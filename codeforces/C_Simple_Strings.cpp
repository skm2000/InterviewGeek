#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s;
    cin>>s;
    ll n=s.size();
    for(ll i=1;i<n-1;i++){
        if(s[i]==s[i-1] && s[i]==s[i+1]){
            if(s[i]=='z') s[i]='a';
            else s[i]='z';
        }else if(s[i] == s[i-1]){
            if(s[i]=='z') s[i]='a';
            else s[i]='z';
        }
    }
    if(s[n-1] == s[n-2]){
        if(s[n-1]=='z') s[n-1]='a';
        else s[n-1]='z';
    }
    cout<<s<<"\n";
}


int main(){
    ll t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}