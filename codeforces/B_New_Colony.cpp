#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,k,l;
    cin>>n>>k;
    vector<ll>h(n);
    for(auto &i:h){
        cin>>i;
    }
    while(k>0){
        bool f=false;
        for(ll i=0;i<n-1;i++){
            if(h[i]<h[i+1]){
                f = true;
                h[i]++;
                l=i+1;
                k--;
                break;
            }
        }
        if(!f){
            cout<<-1<<"\n";
            return;
        }
    }
    cout<<l<<"\n";
}


int main(){
    ll t;
    cin>>t;
    // t=1;
    while(t--){
        solve();
    }
}