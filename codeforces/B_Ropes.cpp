#include<bits/stdc++.h>
#define ll long long int
#define lld long double
using namespace std;

ll n,k;
vector<ll>a;

bool check(lld mid){
    double sum = 0;
    for(ll i=0;i<n;i++){
        sum += floor(a[i]/mid);
    }
    return (sum >= k);
}


void solve(){
    cin>>n>>k;
    a.resize(n);
    for(auto &i : a){
        cin>>i;
    }
    lld low=0,high=1e7,mid;
    for(ll i=0;i<45;i++){
        mid = (low+high)/2;
        if(check(mid)){
            low = mid;
        }else{
            high = mid;
        }
    }
    cout<<setprecision(8)<<low<<"\n";
}


int main(){
    ll t;
    t = 1;
    while(t--){
        solve();
    }
}