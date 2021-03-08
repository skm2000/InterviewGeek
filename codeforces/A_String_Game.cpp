#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s,p;
int a[200000];


bool check(ll mid){
    string temp = s;
    for(ll i=0;i<mid;i++){
        temp[a[i]-1] = '@';
    }
    ll j=0;
    for(ll i=0;i<s.size();i++){
       if(temp[i] == p[j]) j++;
       if(j == p.size()) return true; 
    }
    return false;
}


void solve(){
    cin>>s>>p;
    for(ll i=0;i<s.size();i++){
        cin>>a[i];
    }
    ll low=0,high=s.size(),mid=(low+high)/2;
    while(high-low > 1){
        if(check(mid)){
            low = mid;
        }else{
            high = mid;
        }
        mid = (low+high)/2;
    }

    if(check(high)) cout<<high<<"\n";
    else cout<<low<<"\n";
}


int main(){
    ll t;
    t = 1;
    while(t--){
        solve();
    }
}