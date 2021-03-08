#include<bits/stdc++.h>
using namespace std;
#define ll long long

string gcdOfStrings(string str1, string str2) {
    if (str1.size() < str2.size()) return gcdOfStrings(str2, str1);
    if (str2.empty()) return str1;
    if (str1.substr(0, str2.size()) != str2) return "";
    return gcdOfStrings(str1.substr(str2.size()), str2);
}

void solve(){
    string s,t,st,ans="";
    ll d=0;
    cin>>s>>t;
    ll n = s.size(), m = t.size();
        if(n == 1 && m == 1){
        if(s[0] == t[0]){
            cout<<s[0]<<"\n";
            return;
        }else{
            cout<<-1<<"\n";
            return;
        }
    }
    st = s+t;
    for(ll i=1;i<n;i++){
        if(st[i] != st[i-1]){
            d = 1;
            break;
        }
    }
    if(d == 0){
        for(ll i=0;i<(n*m);i++){
            ans += s[0];
        }
        cout<<ans<<"\n";
    }else{
        string ans = gcdOfStrings(s,t);
        if(ans.length()>0){
            if(n>=m){
                cout<<s<<"\n";
            }else{
                cout<<t<<"\n";
            }
        }else{
            cout<<-1<<"\n";
        }
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}