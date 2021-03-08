#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll n,x,y;

bool check(ll time){
    return ((time/min(x,y)) + ((time-min(x,y))/max(x,y)) >= n);
}


void solve(){
    cin>>n>>x>>y;
    ll low=1,high=max(x,y)*n,mid;
    while(high-low>1){
        mid = (low+high)/2;
        if(check(mid)){
            high = mid;
        }else{
            low = mid;
        }
    }
    cout<<high<<"\n";
}


int main(){
    ll t;
    t = 1;
    while(t--){
        solve();
    }
}