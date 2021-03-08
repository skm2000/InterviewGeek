#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll n,r=0,b=0;
    cin>>n;
    string rc,bc;
    cin>>rc>>bc;
    for(int i=0;i<n;i++){
        if(rc[i]>bc[i]) r++;
        else if(rc[i]<bc[i]) b++;
    }
    if(r>b) cout<<"RED"<<"\n";
    else if(r<b) cout<<"BLUE"<<"\n";
    else cout<<"EQUAL"<<"\n";
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}