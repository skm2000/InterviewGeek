#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long


void solve(){
    ll n,k=0;
    cin>>n;
    vector<ll>a(n);
    for(auto &i: a){
        cin>>i;
    }
    ll m = *min_element(a.begin(), a.end());
    for(auto &i: a){
        if(i != m){
            k++;
        }
    }
    cout<<k<<"\n";
}


int main(){
    ll t;
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
}