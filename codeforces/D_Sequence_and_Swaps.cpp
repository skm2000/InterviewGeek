#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool is_sorted(vector<ll>&a){
    for(int i = 0; i < a.size()-1; i++){
        if(a[i] > a[i+1]) return false;
    }
    return true;
}

void solve(){
    ll n,x,ans = 0;
    cin >> n >> x;
    vector<ll>a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    if(is_sorted(a)){
        cout<<0<<"\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(a[i] > x){
            swap(a[i],x);
            ans++;
        }
        if(is_sorted(a)){
            cout<<ans<<"\n";
            return;
        }
    }
    cout<<-1<<"\n";
    return;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}