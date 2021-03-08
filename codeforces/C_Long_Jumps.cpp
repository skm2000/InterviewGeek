#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n+1),t(n+1);
    for(int i = 1 ; i <= n ; i++)
        cin>>a[i];
    t[n] = a[n] ; 
    for(int i = n-1 ; i >0 ; i--)
    {
        if(i + a[i] <= n )
            t[i] = a[i] + t[i + a[i]] ; 
        else
            t[i] = a[i] ; 
    }
    cout<<*max_element(t.begin()+1, t.end())<<endl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}