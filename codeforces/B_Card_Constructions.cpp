#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll i=1,x=1;
vector<ll>p;

void solve(){
    ll n,ans=0,k;
    cin>>n;
    // for(ll i=0;i<=p.size();i++){
    //     cout<<p[i]<<" ";
    // }
    ll l = lower_bound(p.begin(), p.end(), n) - p.begin();
    // cout<<l<<" ";
    for(ll i=l;i>=0;i--){
        // cout<<p[i]<<" ";
        if(n >= p[i] && n>0 && p[i]>0){
            k = (n/p[i]);
            ans += k;
            n -= (p[i]*k);
        }
        if(n<=0){
            break;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ll t;
    cin>>t;
    while(i<100000){
        ll y = ((x*(3*x+1))/2);
        p.push_back(y);
        i++;
        x++;
    }   
    while(t--){
        solve();
    }
}