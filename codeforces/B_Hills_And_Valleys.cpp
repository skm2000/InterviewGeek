#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll cost(vector<ll>&v,ll pos,ll n) {
  if(pos == 0 || pos == n - 1) return 0;
  return (v[pos] > v[pos - 1] && v[pos] > v[pos + 1]) || (v[pos] < v[pos - 1] && v[pos] < v[pos + 1]);  
}
void solve(){
    ll n,ans=0,tot=0;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<n-1;i++){
        tot += cost(a,i,n);
    }
    ans = tot;
    for(ll i=1;i<n-1;i++){
        ll old = a[i];
        ll now = cost(a,i-1,n) + cost(a,i,n) + cost(a,i+1,n);
        a[i] = a[i-1];
        ans = min(ans,tot-now+cost(a,i-1,n) + cost(a,i,n) + cost(a,i+1,n));
        a[i] = a[i+1];
        ans = min(ans,tot-now+cost(a,i-1,n) + cost(a,i,n) + cost(a,i+1,n));
        a[i] = old;
    }
    cout<<ans<<"\n";
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}