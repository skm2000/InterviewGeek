#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool isPowerOfTwo(ll n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}
 

ll div2(ll n){
    while(n){
        if(n%2 == 0) n = n / 2;
        else return n;
    }
    return 1;
}

void solve(){
    ll w,h,n,m;
    cin>>w>>h>>n;
    m = (w*h)/(div2(w)*div2(h));
    if(n <= m) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}