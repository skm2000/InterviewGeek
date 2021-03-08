#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n,c;
    cin>>n;
    vector<vector<char>>a(n,vector<char>(n));
    int colours[3]={0,0,0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j] == 'X'){
                colours[(i+j)%3]++;
            }
        }
    }

    int indMinm = min_element(colours,colours+3)-colours; // index of minm element 
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            if(a[i][j]=='X' && ((i+j)%3 == indMinm)){
                a[i][j]='O';
            }
        }
    }
    
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}        