#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll n,k;
vector<ll>a;

bool check(ll mid){
    ll c=1,x=0;
    for(ll i=1;i<n;i++){
        if(a[i]-a[x] >= mid){
            c++;
            x=i;
        }
    }
    return (c<k);
}

void solve(){
    cin>>n>>k;
    a.resize(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    ll low = 0, high = a[n-1], mid;
    while(high-low>1){
        mid = (low+high)/2;
        if(check(mid)){
            high = mid;
        }else{
            low = mid;
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