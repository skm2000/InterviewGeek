#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long


void solve(){
    string s;
    cin>>s;
    ll f=-1,n=s.length(),l=-1,c=0;
    for(ll i=0;i<s.length();i++){
        if(s[i] == '1'){
            f = i;
            break;
        }
    }
    for(ll i=s.length()-1;i>=0;i--){
        if(s[i] == '1'){
            l = i;
            break;
        }
    }
    for(ll i=f;i<=l;i++){
        if(s[i]=='0'){
            c++;
        }
    }
    cout<<c<<"\n";
}


int main(){
    ll t;
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
}