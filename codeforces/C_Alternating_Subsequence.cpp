#include<bits/stdc++.h>
#define ll long long int
using namespace std;


void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(auto &i :a){
        cin>>i;
    }
    ll sum=0,pos=0,neg=INT_MIN,f=0;
    for(ll i=0;i<n;i++){
        if(a[i]>0){
            if(neg != INT_MIN && f==0){
                sum += neg;
                neg = INT_MIN;
            }
            pos = max(pos,a[i]);
            f=1;
        }else{
            if(pos !=0 && f==1){
                sum += pos;
                pos = 0;
            }
            neg = max(neg,a[i]);
            f=0;
        }
    }
    if(pos != 0) sum += pos;
    else sum += neg;
    cout<<sum<<"\n";
}



int main(){
    ll t;
    cin>>t;  
    while(t--){
        solve();
    }
}