#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll x,y;
    cin>>x>>y;
    if(min(x,y)+3 > max(x,y)) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
}

int main(){
    ll t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
}