#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,ans=0;
    cin>>n;
    vector<ll>a(n),b(n);
    for(auto i=0;i<n;i++){
        cin>>a[i];
    }
    for(auto i=0;i<n;i++){
        cin>>b[i];
        ans += (a[i]*b[i]);
    }
    if(ans == 0)cout<<"Yes"<<"\n";
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