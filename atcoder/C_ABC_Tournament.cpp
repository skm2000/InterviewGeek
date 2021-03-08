#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,ans=0;
    cin>>n;
    vector<ll>a(pow(2,n));
    for(auto i=0;i<pow(2,n);i++){
        cin>>a[i];
    }
    ll m1,m2,m;
    m1 = *max_element(a.begin(),a.begin()+(a.size()/2));
    m2 = *max_element(a.begin()+(a.size()/2),a.end());
    m = min(m1,m2);
    // cout<<m1<<" "<<m2<<endl;
    for(auto i=0;i<pow(2,n);i++){
        if(m == a[i]){
            cout<<i+1<<"\n";
            return;
        }
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