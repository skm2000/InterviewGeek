#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll k,n;
vector<ll>a;

bool check(ll x){
    ll slots = x*k;
    for(ll i=0;i<n;i++){
        slots -= min(x,a[i]);
    }
    return (slots<=0);
}

void solve(){
    cin>>k>>n;
    ll s=0;
    a.resize(n);
    for(auto &i : a){
        cin>>i;
        s += i;
    }
    ll low=1,high=s,mid;
    while(high-low >1){
        mid = (low+high)/2;
        if(check(mid)){
            low = mid;
        }else{
            high = mid;
        }
    }
    cout<<low<<"\n";
}

int main(){
    ll t;
    t = 1;
    while(t--){
        solve();
    }
}