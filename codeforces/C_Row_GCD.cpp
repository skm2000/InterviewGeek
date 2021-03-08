#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
  ll n,m,ma=LLONG_MAX;
  cin>>n>>m;
  vector<ll>a(n),b(m);
  vector<ll>v;
  for(int i=0;i<n;i++){
      cin>>a[i];
      ma = min(ma,a[i]);
  }
  for(int i=0;i<m;i++){
      cin>>b[i];
  }
  if(n == 1){
      for(int i=0;i<m;i++){
          cout<<a[0]+b[i]<<" ";
      }
      return;
  }  
  for(int i=0;i<n-1;i++){
     v.push_back(abs(a[i]-a[i+1]));
  } 
  ll g = v[0];
  for(int i=1;i<v.size();i++){
      g = __gcd(g,v[i]);
  }
  for(int i=0;i<m;i++){
      cout<<__gcd(ma+b[i],g)<<" ";
  } 
}

int main(){
    ll t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
}