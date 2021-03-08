#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll euclid(ll a,ll b){
    if(b == 0) return a;
    return euclid(b,a%b);
}

void solve(){
    ll n,a,b,k;
    cin>>n>>a>>b>>k;
    ll gcd = euclid(a,b);
    ll lcm = (a*b)/gcd;
    ll rep = n/lcm;
    ll ans = (n/a) + (n/b) - 2*rep;
    if(ans >= k) cout<<"Win"<<"\n";
    else cout<<"Lose"<<"\n";
}


int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}