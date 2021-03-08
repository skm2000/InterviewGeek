#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        a[i] = n-i;
    }
    if(n%2==1) reverse(a.begin()+n/2,a.end());
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}


int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}      