#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,j=-1;
    cin>>n;
    vector<ll>a(n);
    for(auto &i:a){
        cin>>i;
    }
    vector<ll>s1,s2;
    s1.push_back(a[0]);
    for(ll i=1;i<n;i++){
        if(s1.back() == a[i]){
            j=i;
            s2.push_back(a[i]);
            break;
        }else{
            s1.push_back(a[i]);
        }
    }
    if(j == -1){
        cout<<n<<"\n";
        return;
    }
    for(ll i=j+1;i<n;i++){
        if(s1.back() != a[i]){
           s1.push_back(a[i]);
        }else if(s2.back() != a[i]){
            s2.push_back(a[i]);
        }
    }
    cout<<s1.size()+s2.size()<<"\n";
}


int main(){
    ll t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}
