#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,m;
    cin>>n>>m;
    if(n == 1){
        cout<<1<<"\n";
        return;
    }
    ll x = m-1;
    ll y = n-m;
    if(x>=y){
        cout<<m-1<<"\n";
    }else{
        cout<<m+1<<"\n";
    }
}


int main(){
    ll t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}