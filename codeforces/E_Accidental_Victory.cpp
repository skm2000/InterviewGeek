#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long

void print(vector<ll>&a){
    for(auto &x : a){
        cout<<x<<" ";
    }
    cout<<"\n";
}

void solve(){
    ll n,x=-1,a,f=1;
    cin>>n;
    vector<ll>p(n);
    vector<pair<ll,ll>>xx;
    for(ll i=0;i<n;i++){
        cin>>a;
        xx.push_back({a,i});
    }
    sort(xx.begin(),xx.end());
    p[0] = xx[0].first;
    for(ll i=1;i<n;i++){
        p[i] = p[i-1] + xx[i].first;
    }
    // print(p);
    vector<ll>l;
    ll ans = 1;
    for(ll i=n-2;i>=0;i--){
        if(p[i]>=xx[i+1].first){
            l.push_back(xx[i+1].second);
            // cout<<xx[i+1].second<<" ";
            ans++;
        }else{
            l.push_back(xx[i+1].second);
            x = i;
            f = 0;
            break;
        }
    }
    if(f == 1){
        l.push_back(xx[0].second);
    }
    // cout<<"\n";
    cout<<ans<<"\n";
    // reverse(l.begin(),l.end());
    sort(l.begin(),l.end());
    for(ll i=0;i<l.size();i++){
        cout<<l[i]+1<<" ";
    }
    cout<<"\n";
}


int main(){
    ll t;
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
}