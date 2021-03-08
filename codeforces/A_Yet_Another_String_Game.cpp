#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s;
    cin>>s;
    char c;
    int p;
    for(ll i=0;i<s.length();i++){
        if(i%2 == 0){
            if(s[i] == 'a'){
                s[i] = 'b';
            }else{
               s[i] = 'a';
            }
        }else{
            if(s[i] == 'z'){
                s[i] = 'y';
            }else{
                s[i] = 'z';
            }
        }
    }
    cout<<s<<"\n";
}


int main(){
    ll t;
    cin>>t;
    // t=1;
    while(t--){
        solve();
    }
}