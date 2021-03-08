#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll n,flag=0;
    cin>>n;
    vector<ll>a(n);
    set<ll>s;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(s.count(a[i])) a[i]++;
        s.insert(a[i]);
    }
    cout<<s.size()<<"\n";
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}