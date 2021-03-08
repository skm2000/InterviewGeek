#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,a,b,c=0;
    cin>>n>>a>>b;
    vector<ll>x;
    vector<ll>k;
    for(ll i=1;i<=n;i++){
        x.push_back(i);
    }
    for(ll i=0;i<n;i+=2){
        if((x[i]==a && x[i+1]==b) || (x[i]==b && x[i+1]==a){

        }else if(x[i]==a || x[i]==b){
            k.push_back(x[i]);
        }else{
            k.push_back(x[i+1]);
        }
    }
}


int main(){
    ll t;
    cin>>t;
    // t=1;
    while(t--){
        solve();
    }
}