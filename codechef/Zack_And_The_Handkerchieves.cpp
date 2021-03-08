#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll euclid(ll a,ll b){
    if(b == 0) return a;
    return euclid(b,a%b);
}

void solve(){
    ll l,b;
    cin>>l>>b;
    cout<<euclid(l,b)<<"\n";
}


int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}