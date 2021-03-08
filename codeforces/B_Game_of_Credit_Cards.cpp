#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    string s,m;
    cin>>s>>m;
    sort(s.begin(),s.end());
    sort(m.begin(),m.end());
    ll j=n-1,min=0,max=0;
    for(ll i=n-1;i>=0;i--){
        if(s[i] <= m[j]){
            j--;
            min++;
        }
    }
    cout<<n-min<<"\n";
    j = n-1;
    for(ll i=n-1;i>=0;i--){
        if(s[i] < m[j]){
            j--;
            max++;
        }
    }
    cout<<max<<"\n";
}

int main(){
    ll t;
    // cin >> t;
    t=1;
    while(t--){
        solve();
    }
}