#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(auto &i : a){
        cin>>i;
    }
    reverse(a.begin(), a.end());
    for(auto &i : a){
        cout<<i<<" ";
    }
    cout<<"\n";
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}