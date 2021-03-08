#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll n,k,o=0,z=0,q=0;
    cin>>n>>k;
    string s;
    cin>>s;
    for(ll i=0;i<k;i++){
        if(s[i]=='?'){
            for(ll j=i+k;j<n;j+=k){
                if(s[j] != '?'){
                    s[i] = s[j];
                    break;
                }
            }
        }
    }
    for(ll i=0;i<k;i++){
        if(s[i] != '?'){
            for(ll j=i+k;j<n;j+=k){
                if(s[j] == '?'){
                    s[j] = s[i];
                }else if(s[i] != s[j]){
                    cout<<"NO"<<"\n";
                    return;
                }
            }
        }
    }
    for(ll i=0;i<k;i++){
        if(s[i] == '1') o++;
        else if(s[i] == '0') z++;
    }
    if(o<=k/2 && z<=k/2){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}