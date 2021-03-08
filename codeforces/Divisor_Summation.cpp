#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll sumDivisors(ll n){
    ll res=0;
    for(ll i=1;i<=sqrt(n);i++){
        if(n%i == 0){
            if(n/i == i){
                res += i;
            }else{
                res = res + (i) + (n/i);
            }
        }
    }
    return res;
}


void solve(){
    ll n;
    cin>>n;
    cout<<sumDivisors(n)-n<<"\n";
}


int main(){
    ll t;
    cin>>t;
    // t=1;
    while(t--){
        solve();
    }
}