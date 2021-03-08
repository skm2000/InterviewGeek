#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll n;
vector<double>x,v;

bool check(double time){
    double l=INT_MIN,r=INT_MAX;
    for(ll i=0;i<n;i++){
        double left = x[i]-time*v[i];
        double right = x[i]+time*v[i];

        l = max(l,left);
        r = min(r,right);
    }
    return (r-l)>=0;
}

void solve(){
    cin>>n;
    x.resize(n);
    v.resize(n);
    for(ll i=0; i<n; i++){
        cin>>x[i]>>v[i];
    }
    double low = -1e9, high = 1e9, mid;
    for(ll i=0;i<80;i++){
        mid = (low+high)/2;
        if(check(mid)){
            high = mid;
        }else{
            low = mid;
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