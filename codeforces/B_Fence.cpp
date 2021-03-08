#include<bits/stdc++.h>
#define ll long long int
using namespace std;


void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll>x(n);
    for(auto &i : x){
        cin>>i;
    }
    ll sum=0,ans,p;
    for(ll i=0;i<k;i++){
        sum += x[i];
    }
    p = 1;
    ans = sum;
    for(ll i=k;i<n;i++){
        sum += x[i]-x[i-k];
        // cout<<sum<<" ";
        if(sum < ans){
            ans = sum;
            p = i-k+2;
        }
    }
    cout<<p<<"\n";
}

int main(){
    ll t;
    t = 1;
    while(t--){
        solve();
    }
}