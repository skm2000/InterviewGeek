#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll w,h,n;

bool check(ll mid){
    if(((mid/w)*(mid/h))>=n) return true;
    return false;
}

void solve(){
    cin>>w>>h>>n;
    ll low=1,high=1,mid;
    while(!check(high)){
        high = high*2;
    }
    while(high-low > 1){
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