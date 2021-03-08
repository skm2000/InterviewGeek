#include<bits/stdc++.h>
#define ll long long int
using namespace std;

double c;

bool check(double x){
    return ((x*x) + sqrt(x)) >= c;
}


void solve(){
    cin>>c;
    double low=1,high=1e5,mid;
    for(ll i=0;i<50;i++){
        mid = (low+high)/2;
        if(check(mid)){
            // cout<<high<<"\n";
            high = mid;
        }else{
            low = mid;
        }
    }
    cout<<setprecision(8)<<high<<"\n";
}


int main(){
    ll t;
    t = 1;
    while(t--){
        solve();
    }
}