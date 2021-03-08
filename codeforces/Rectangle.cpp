#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


ll maximalRectangle(vector<vector<char> > &matrix) {
    if(matrix.empty()) return 0;
    const ll m = matrix.size();
    const ll n = matrix[0].size();
    ll left[n], right[n], height[n];
    fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);
    ll maxA = 0;
    for(ll i=0; i<m; i++) {
        ll cur_left=0, cur_right=n; 
        for(ll j=0; j<n; j++) { // compute height (can do this from either side)
            if(matrix[i][j]=='1') height[j]++; 
            else height[j]=0;
        }
        for(ll j=0; j<n; j++) { // compute left (from left to right)
            if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
            else {left[j]=0; cur_left=j+1;}
        }
        // compute right (from right to left)
        for(ll j=n-1; j>=0; j--) {
            if(matrix[i][j]=='1') right[j]=min(right[j],cur_right);
            else {right[j]=n; cur_right=j;}    
        }
        // compute the area of rectangle (can do this from either side)
        for(ll j=0; j<n; j++)
            maxA = max(maxA,(right[j]-left[j])*height[j]);
    }
    return maxA;
}

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<vector<char>>matrix(n,vector<char>(m));
    ll ones = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>matrix[i][j];
            if(matrix[i][j] == '1'){
                ones++;
            }
        }
    }
    ll ans = maximalRectangle(matrix);
    if(ans == ones){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
}


int main()
{
    fast_cin();
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}