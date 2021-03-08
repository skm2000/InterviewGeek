#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll n,k;
vector<ll>a;

bool solve(){
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    ll sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += a[i];
        if(sum <= 0) return 0;
    }
    sum = 0;
    for(int i = n - 1 ; i >= 0 ; i--){
        sum += a[i];
        if(sum <= 0) return 0;
    }
    return 1;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        if(solve())cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}