#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll a,b;
    string s;
    cin>>a>>b>>s;
    ll f=-1,l=-1;
    for(ll i=0;i<s.size();i++){
        if(s[i]=='1'){
            f = i;
            break;
        }
    }
    for(ll i=s.size()-1;i>=0;i--){
        if(s[i] == '1'){
            l = i;
            break;
        }
    }
    if(f==-1 && l==-1){
        cout<<0<<"\n";
        return;
    }
    ll ans = a;
    for(ll i=f;i<=l;i++){
        ll x=0;
        while(s[i] == '0'){
            i++;
            x++;
        }
        ans += min(a,x*b);
    }
    cout<<ans<<"\n";
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}