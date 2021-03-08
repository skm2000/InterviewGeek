#include<bits/stdc++.h>
using namespace std;
#define ll long long


int sumDivisors(int n){
    int res=0;
    for(int i=1;i*i<=(n);i++){
        if(n%i == 0){
            if(n/i == i){
                res++;
            }else{
                res+=2;
            }
        }
    }
    return res;
}


void solve(){
    int n;
    cin>>n;
    cout<<sumDivisors(n)<<"\n";
}


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin>>t;
    // t=1;
    while(t--){
        solve();
    }
}