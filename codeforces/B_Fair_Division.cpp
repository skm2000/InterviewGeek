#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll n,s=0;
    cin>>n;
    vector<ll>a(n);
    int f[3]={0};
    for(ll i=0; i<n; i++){
        cin>>a[i];
        s += a[i];
        f[a[i]]++;
    }
    if(s%2 == 1){
        cout<<"NO"<<"\n";
        // return;
    }else{
        if((f[2]%2 == 1) && (f[1] == 0)){
            cout<<"NO"<<"\n";
        }else{
            cout<<"YES"<<"\n";
        }
    }
    /* if(f[2] == 0){
        if(f[1]%2 == 0){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
        // return;
    }
    else if(f[1] == 0){
        if(f[2]%2 == 0){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
        // return;
    }
    else if((f[2]*2) == f[1]){
        cout<<"YES"<<"\n";
    }
    else if(f[1] == f[2]){
        if(f[2]%2 == 0 && f[1]%2 == 0){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    else{
        cout<<"NO"<<"\n";
    } */
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}