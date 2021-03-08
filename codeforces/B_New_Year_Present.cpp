#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,s=0,l=-1;
    cin>>n;
    vector<ll>h(n);
    for(auto &i:h){
        cin>>i;
        s += i;
    }
    // cout<<s;
    string ans="";
    for(ll i=0;i<n;i++){
        if(h[i]==0){
            ans += "R";
        }
        else{
            l = i;
            break;
        }
    }
    // cout<<ans<<l;
    if(l != -1){
        ans += "P";
        h[l]--;
        s--;
    }
    // cout<<ans<<s;
    while(s>0){
        for(ll i=l;i<n-1;i++){
            if(h[i+1]>0){
                ans += "RP";
                h[i+1]--;
                s--;
            }else{
                ans += "R";
            }
        }
        if(s>0){
            for(ll i=n-1;i>l;i--){
                if(h[i-1]>0){
                    ans += "LP";
                    h[i-1]--;
                    s--;
                }else{
                    ans += "L";
                }
            }
        }
    }
    cout<<ans<<"\n";
}


int main(){
    ll t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}