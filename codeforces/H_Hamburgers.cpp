#include<bits/stdc++.h>
#define ll long long int
using namespace std;


ll nb,ns,nc,ps,pb,pc,r;
string s;
vector<ll>a;
vector<ll>store(3);

bool check(ll x){
    ll z=0;
    ll tb=store[0]*x,tc=store[1]*x,ts=store[2]*x;
    ll db=max(tb-nb,z),dc=max(tc-nc,z),ds=max(ts-ns,z);
    if(db*pb + dc*pc + ds*ps > r){
        return false;
    }
    return true;
}

void solve(){
    cin>>s;
    cin>>nb>>ns>>nc>>pb>>ps>>pc>>r;
    for(char c:s){
        if(c=='B') store[0]++;
        else if(c=='C') store[1]++;
        else store[2]++;
    }
    ll low=0,high=1e13,mid;
    while(high-low >1){
        mid = (low+high)/2;
        if(check(mid)){
            low = mid;
        }else{
            high = mid;
        }
    }
    cout<<low<<"\n";
}

int main(){
    ll t;
    t = 1;
    while(t--){
        solve();
    }
}