#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<bool>prime(201,true);
vector<ll>x;
void seive(){
    prime[0]=false,prime[1]=false;
    for(ll i=2;i*i<=200;i++){
        if(prime[i]){
            for(ll j=i*i;j<=200;j+=i){
                prime[j]=false;
            }
        }
    }
    for(ll i=0;i<=200;i++){
        if(prime[i]){
            x.push_back(i);
        }
    }
    // for(ll i=0;i<x.size();i++){
    //     cout<<x[i]<<" ";
    // }
}

bool isSemiPrime(ll y){
    ll l=0,r=x.size()-1;
    while(l<r){
        if(x[l]*x[r] == y){
            return true;
        }else if(x[l]*x[r] < y){
            l++;
        }else{
            r--;
        }
    }
    return false;
}


void solve(){
    ll n; 
    cin>>n;
    for(ll i=2;i<=n/2;i++){
        if(isSemiPrime(i) && isSemiPrime(n-i)){
            cout<<"YES"<<"\n";
            return;
        }
    }
    cout<<"NO"<<"\n";
}


int main(){
    ll t;
    cin>>t;
    seive();
    while(t--){
        solve();
    }
}