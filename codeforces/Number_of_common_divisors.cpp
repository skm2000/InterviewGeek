#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll euclid(ll a,ll b){
    if(b == 0){
        return a;
    }
    return euclid(b,a%b);
}

ll countDivisors(ll n){
    ll res=0;
    for(ll i=1;i<=sqrt(n);i++){
        if(n%i == 0){
            if(n/i == i){
                res++;
            }else{
                res += 2;
            }
        }
    }
    return res;
}


void solve(){
    ll a,b;
    cin>>a>>b;
    ll gcd = euclid(a,b);
    // cout<<gcd<<"\n";
    cout<<countDivisors(gcd)<<"\n";
}


int main(){
    ll t;
    cin>>t;
    // t=1;
    while(t--){
        solve();
    }
}