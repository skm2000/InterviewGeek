#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    double x,y,r;
    cin>>x>>y>>r;
    double mx = x+r, my = y+r, wx = x-r, wy = y-r;
    // cout<<mx<<" "<<my<<" ";
    wx = (ll)wx;
    wy = (ll)wy;
    ll imx = mx, imy = my, c=0;
    // cout<<imx<<" "<<imy<<" "<<wx<<" "<<wy<<" ";
    r = pow(r,2);
    cout<<r;
    for(ll i=wx;i<=imx;i++){
        for(ll j=wy;j<=imy;j++){
            double p1 = ((i-x)*(i-x));
            double p2 = ((j-y)*(j-y));
            double p3 = p1+p2;
            if(r >= p3){
                c++;
            }
        }
    }
    cout<<c<<"\n";
    
}

int main(){
    ll t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
}