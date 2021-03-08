#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;

 

void solve(){
    ll n,u,r,d,l;
    cin >> n >> u >> r >> d >> l;
        if(l == 0 && (u == n || d == n)){
            // cout<<1;
            cout<<"NO"<<"\n";
            return;
        }
        if(r == 0 && (u == n || d == n)){
            // cout<<1;
            cout<<"NO"<<"\n";
            return;
        }
        if(u == 0 && (l == n || r == n)){
            cout<<"NO"<<"\n";
            return;
        }
        if(d == 0 && (l == n || r == n)){
            cout<<"NO"<<"\n";
            return;
        }
        if(r == n && l == n){
            // cout<<1;
            if(u<2 || d<2){
                cout<<"NO"<<"\n";
                return;
            }
        }
        if(u == n && d == n){
            // cout<<1;
            if(l<2 || r<2){
                cout<<"NO"<<"\n";
                return;
            }
        }
        if(u == n-1 && d == n-1){
            if((r==0 && l<=1) || (l==0 && r<=1)){
                cout<<"NO"<<"\n";
                return;
            }
        }
        if(r == n-1 && l == n-1){
            if((u==0 && d<=1) || (d==0 && u<=1)){
                cout<<"NO"<<"\n";
                return;
            }
        }
        if(u == n-1){
            if(r == 0 && l == 0){
                cout<<"NO"<<"\n";
                return;
            }
        }
        if(d == n-1){
            if(r == 0 && l == 0){
                cout<<"NO"<<"\n";
                return;
            }
        }
        if(l == n-1){
            if(u == 0 && d == 0){
                cout<<"NO"<<"\n";
                return;
            }
        }
        if(r == n-1){
            if(u == 0 && d == 0){
                cout<<"NO"<<"\n";
                return;
            }
        }
        
        cout<<"YES"<<"\n";
}


int main()
{
    // fast_cin();
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}