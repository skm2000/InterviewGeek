#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define ll long long


void solve(){
    ll n,m,ans=0;
    cin>>n>>m;
    vector<vector<char>>mat(n,vector<char>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>mat[i][j];
            if(mat[i][j] == '.'){
                mat[i][j] = '1';
            }else{
                mat[i][j] = '0';
            }
        }
    }
    for(ll i=0;i<n-1;i++){
        for(ll j=0;j<m-1;j++){
            ll sum = (mat[i][j] - '0') + (mat[i+1][j]-'0') + (mat[i][j+1]-'0') + (mat[i+1][j+1]-'0');
            // cout<<sum<<" ";
            if(sum & 1){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}


int main(){
    ll t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
}