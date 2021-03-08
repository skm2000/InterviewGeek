#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll n,o=0,e=0;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<ll>());
    ll alice=0,bob=0;
    for(ll i=n-1;i>=0;i--){
        if(i%2==0){
            if(a[i]%2 == 0) alice += a[i];
        }else{
            if(a[i]%2 == 1) bob += a[i];
        }
    }
    if(alice > bob){
        cout<<"Alice"<<"\n";
    }else if(alice == bob){
        cout<<"Tie"<<"\n";
    }else{
        cout<<"Bob"<<"\n";
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}