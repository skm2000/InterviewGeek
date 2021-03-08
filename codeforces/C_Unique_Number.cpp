#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int x;
    cin>>x;
    string ans = "";
    if(x>=0 && x<=9) ans = to_string(x);
    else if(x>=10 && x<=17) ans = to_string(x-9)+"9";
    else if(x>=18 && x<=24) ans = to_string(x-17)+"89";
    else if(x>=25 && x<=30) ans = to_string(x-24)+"789";
    else if(x>=31 && x<=35) ans = to_string(x-30)+"6789";
    else if(x>=36 && x<=39) ans = to_string(x-35)+"56789";
    else if(x>=40 && x<=42) ans = to_string(x-39)+"456789";
    else if(x>=43 && x<=44) ans = to_string(x-42)+"3456789";
    else if(x==45) ans = "123456789";
    else {
        cout<<-1<<"\n";
        return;
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