#include<bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){
    ll A,H,n,x,c=0;
    cin>>A>>H>>n;
    vector<ll>a(n);
    vector<ll>h(n);
    for(auto &i :a){
        cin>>i;
    }
    for(auto &i :h){
        cin>>i;
    }
    sort(a.begin(),a.end());
    for(ll i=0;i<n;i++){
        // cout<<x<<" "<<H<<"\n";
        if(i != n-1){
            x = ceil((h[i]*1.0)/(A*1.0));
            H -= (x*a[i]);
            if(H <= 0){
                cout<<"NO"<<"\n";
                return;
            }
        }else{
            x = ceil((h[i]*1.0)/(A*1.0));
            x = x-1;
            H -= (x*a[i]);
            if(H>0){
                cout<<"YES"<<"\n";
            }else{
                cout<<"NO"<<"\n";
            }
            return;
        }
    }
}


int main(){
    ll t;
    cin>>t;
    // t=1;
    while(t--){
        solve();
    }
}