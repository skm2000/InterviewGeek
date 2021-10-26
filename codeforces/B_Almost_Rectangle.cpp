#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define INF 2e18
const ll N = 1e5+7;
#define all(x) x.begin(),x.end()
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n;
    cin >> n;
    ll check = 1;
    char a[n][n], tem[n][n];
    pair<ll,ll> p1,p2;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    bool f = false;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if(a[i][j] == '*'){
                // cout<<i<<" "<<j<<"\n";
                if(check == 1){
                    check++;
                   p1.first = i;
                   p1.second = j; 
                }else{
                    p2.first = i;
                    p2.second = j;
                }
            }
        }
    }
    ll x = p1.first;
    ll y = p1.second;
    ll w = p2.first;
    ll z = p2.second;
    if(x==w){
            if(x-1>=0){
                a[x-1][y]=a[x-1][z]='*';
            }
            else{
                a[x+1][y]=a[x+1][z]='*';
            }
        }
        else if(y==z){
            if(y-1>=0){
                a[x][y-1]=a[w][y-1]='*';
            }
            else{
               // cout<<".";
                a[x][y+1]=a[w][y+1]='*';
            }
        }
        else {
            a[x][z] = '*';
            a[w][y] = '*';
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++)cout<<a[i][j];
            cout<<"\n";
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

