#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<double>a(n);
    set<double>s;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll k;
    for(ll i=1;i<n;i++){
        double initial = 0.5*a[0];
        k = 1;
        for(ll j=i;j<n;j++){
            double area = 0.5*a[j];
            s.insert(area - initial);
            initial = 0.5*a[k];
            k++;
        }
    }
    cout<<s.size()<<"\n";
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}