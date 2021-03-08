#include<bits/stdc++.h>
using namespace std;
#define ll long long int


void solve(){
    ll n,t,s,d;
    cin>>n>>t>>s>>d;
    double m = ((d*1.0)/(n*1.0));
    // cout<<m;
    if(t<=m && m<=s){
        cout<<"No"<<"\n";
    }else{
        cout<<"Yes"<<"\n";
    }
}

int main(){
    ll t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
}