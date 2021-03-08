#include<bits/stdc++.h>
#define ll long long int
using namespace std;


void solve(){
    ll n,d,c=0;
    cin>>n>>d;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<=d) c++;
    }
    if(c == n){
        cout<<"YES"<<"\n";
        return;
    }
    sort(a.begin(),a.end());
    ll x = a[0],y = a[1];
    if(x+y <= d){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}