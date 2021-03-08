#include<bits/stdc++.h>
#define ll long long int
using namespace std;


void solve(){
   ll n,q,m;
   cin>>n;
   vector<ll>x(n);
   for(auto &i : x){
       cin>>i;
   }
   sort(x.begin(),x.end());
   cin>>q;
   for(ll i=0;i<q;i++){
       cin>>m;
       auto l = upper_bound(x.begin(),x.end(),m);
       cout<<l-x.begin()<<"\n";
   }
}

int main(){
    ll t;
    t = 1;
    while(t--){
        solve();
    }
}