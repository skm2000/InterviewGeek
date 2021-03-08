#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll rec_sum(ll n,ll x){
    ll s = 0;
    while(n){
        if(n%x == 0){
            s++;
            n /= x;
        }else{
            break;
        }
    }
    return s;
}

void solve(){
    ll n,x,ans=0,ind=0,m;
    cin>>n>>x;
    vector<ll>a(n);
    vector<ll>d(n,1);
    for(ll i=0;i<n;i++){
        cin>>a[i];
        d[i] += rec_sum(a[i],x);
    }
    m = *min_element(d.begin(),d.end());
    for(ll i=0;i<n;i++){
        if(d[i] == m){
            ind = i;
            break;
        }
    }
    for(ll i=0;i<ind;i++){
        d[i] = m+1;
    }
    for(ll i=ind;i<n;i++){
        d[i] = m;
    }
    for(ll i=0;i<n;i++){
        ans += (d[i]*a[i]);
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