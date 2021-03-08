#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n,m;
    cin >> n >> m;
    string s,t;
    cin>>s>>t;
    vector<ll>first;
    vector<ll>second;
    ll i=0,j=0;
    while(i<n && j<m){
        if(s[i] == t[j]){
            first.push_back(i);
            i++;
            j++;
        }else{
            i++;
        }
    }
    i=n-1,j=m-1;
    while(i>=0 && j>=0){
        if(s[i] == t[j]){
            second.push_back(i);
            i--;
            j--;
        }else{
            i--;
        }
    }
    ll mx=0;
    reverse(second.begin(),second.end());
    for(ll i=0;i<second.size()-1;i++){
        mx = max(mx,max(first[i+1],second[i+1])-min(first[i],second[i]));
    }
    cout<<mx<<"\n";
}


int main()
{
    fast_cin();
    ll t;
    // cin >> t;
    t = 1;
    while(t--) {
        solve();
    }
    return 0;
}