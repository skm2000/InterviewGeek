#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll n;
    cin>>n;
    if(n == 1){
        cout<<4<<"\n";
    }
    else if(n%2 == 1){
        n=n-1;
        cout<<2*(n/2+1)*(n/2+2)<<"\n";
    }else{
        cout<<(n/2+1)*(n/2+1)<<"\n";
    }
}

int main(){
    // ll t;
    // cin>>t;
    // while(t--){
        solve();
    // }
}