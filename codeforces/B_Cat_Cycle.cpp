#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long


void solve(){
    ll n,k;
    cin>>n>>k;
    k--;
    if(n%2){
        ll temp=n/2;
        k+=(k/temp);
        cout<<(k%n)+1;
    }else{
        cout<<(k%n)+1;
    }
    cout<<"\n";
}


int main(){
    ll t;
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
}