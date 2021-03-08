#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long

bool check(ll n){
    for(ll i=2;i*i<=n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

void solve(){
    ll n,flag=0;
    cin>>n;
    vector<ll>a(n);
    for(auto &i : a){
        cin>>i;
        if(i == 1){
            flag = 1;
        }
    }
    if(flag == 1){
        cout<<1;
        return;
    }
    set<ll>s;
    for(auto &i : a){
        if(check(i)){
            s.insert(i);
        }
    }
    ll m = *min_element(a.begin(),a.end());
    ll x = *(s.begin());
    if(m == x){
        // ll c=0;
        // for(auto &i : a){
        //     if(i%x == 0){
        //         c++;
        //     }
        // }
        // cout<<c<<"\n";
        // if(c == n){
        //     cout<<1<<"\n";
        //     return;
        // }
    }
    s.clear();
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            s.insert(__gcd(a[i],a[j]));
        }
    }
    ll min = *min_element(a.begin(),a.end());
    s.insert(min);
    cout<<s.size();
}


int main(){
    ll t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
}