#include<bits/stdc++.h>
using namespace std;
#define ll long long 


void solve(){
    ll n,k;
    cin>>n>>k;
    if(n>=k){
        if(n%k == 0){
            cout<<1<<"\n";
        }else{
            cout<<2<<"\n";
        }
    }else{
        cout<<ceil((k*1.0)/(n*1.0))<<"\n";
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}