#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll>k(n),c(m);
    for(auto &i : k){
        cin>>i;
    }
    for(auto &i : c){
        cin>>i;
    }
    sort(k.begin(),k.end(),greater<ll>());
    ll j=0,ans=0;
    for(ll i=0;i<n;i++){
        if((c[k[i]-1]) < 0){
            ans += abs(c[k[i]-1]);
        }else{
            ans += c[j];
            c[j] = -(1*c[j]);
            j++;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}