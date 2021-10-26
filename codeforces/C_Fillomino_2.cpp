#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define vdbg(v) for(auto x : v) cout<<x<<endl
#define INF 2e18
const ll N = 1e5+7;
#define all(x) x.begin(),x.end()
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 

void solve(){
    ll n;
    cin>>n;
    vector<vector<ll>>arr(n,vector<ll>(n));
    for (ll i=0;i<n;i++)
    {
        cin>>arr[i][i];
    }
    ll f=0;
    for (ll i=0;i<n;i++)
    {
        ll x=arr[i][i];
        ll currx=i;
        ll curry=i;
        ll count=1;
        while(count!=x)
        {
            if (curry-1>=0 && arr[currx][curry-1]==0){
                curry-=1;
                arr[currx][curry]=x;
                count++;
            }
            else if (currx+1<n && arr[currx+1][curry]==0){
                currx+=1;
                arr[currx][curry]=x;
                count++;                
            }
        }
        if (count!=x){
            cout<<-1<<"\n";
            return;   
        } 
    }
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<=i;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
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