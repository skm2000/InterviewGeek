#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll x,i=0;
    cin>>x;
    ll curr=0;
    while(curr < x){
        curr += i;
        i++;
    }
    if(curr-1 == x){
        cout<<i<<"\n";
    }else{
        cout<<i-1<<"\n";
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}