#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(auto &i : a){
        cin>>i;
    }
    ll sum=0,cost=0;
    for(auto &i : a){
        sum += i;
        if(sum < 0){
            cost += abs(sum);
            sum = 0;
        }
    }
    cout<<cost<<"\n";
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}