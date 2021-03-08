#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long

set<ll>s;

void solve(){
    ll n;
    cin>>n;
    for(ll i=1;i<=10000;i++){
        if(s.find(n-(i*i*i)) != s.end()){
            cout<<"YES"<<"\n";
            return;
        }
    }
    cout<<"NO"<<"\n";
}


int main(){
    for(ll i=1;i<=10000;i++){
        s.insert(i*i*i);
    }
    ll t;
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
}