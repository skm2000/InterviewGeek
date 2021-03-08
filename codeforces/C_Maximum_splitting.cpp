#include<bits/stdc++.h>
#define m 16
using namespace std;
#define ll long long

void solve(){
    // vector<ll>ans(m,-1);
    // ans[0]=0;
    // for(ll i=1;i<m;i++){
    //     for(auto j: vector<ll>{4,6,9}){
    //         if(i>=j && ans[i-j]!=-1){
    //             ans[i] = max(ans[i],1+ans[i-j]);
    //         }
    //     }
    // }
    // for(ll i=0;i<m;i++){
    //     cout<<ans[i]<<" ";
    // }
    ll n;
    cin>>n;
    if(n%4 == 0 && (n-4)>=0){
        cout<<n/4<<"\n";
    }else if((n-6)%4 == 0 && (n-6)>=0){
        cout<<(1+(n-6)/4)<<"\n";
    }else if((n-9)%4 == 0 && (n-9)>=0){
        cout<<(1+(n-9)/4)<<"\n";
    }else if((n-15)%4 == 0 && (n-15)>=0){
        cout<<(2+(n-15)/4)<<"\n";
    }else{
        cout<<-1<<"\n";
    }
}

int main(){
    ll t;
    cin >> t;
    // t=1;
    while(t--){
        solve();
    }
}