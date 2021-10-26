#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<x<<" ";
#define vdbg(x) for(auto x : x) cout<<x<<" ";
#define INF 2e18
const ll N = 1e5+7;
#define all(x) x.begin(),x.end()
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


 

void solve(){
    ll k,n, m;
    cin >> k >> n >> m;
    vector<ll>a(n);
    vector<ll>b(m);
    for(auto &i : a){
       cin >> i;
    }
    for(auto &i : b){
       cin >> i;
    }
    ll flag = 0;
    vector<ll>x(n+m);
    ll i1 = 0, i2 = 0, i = 0;
    while(i1<n && i2<m){
        if(a[i1]==0) {
            k++;
            x[i]=a[i1];
            i++;
            i1++;
            continue;
        }
        if(b[i2]==0){
            k++;
            x[i]=b[i2];
            i++;
            i2++;
            continue;
        }
        if(a[i1]<=k){
            x[i]=a[i1];
            i++;
            i1++;
            continue;
        }
        if(b[i2]<=k){
            x[i]=b[i2];
            i++;
            i2++;
            continue;
        }
        flag=1;
        break;
    }
    while(i1<n){
        if(a[i1]==0) {
            k++;
        
            x[i]=a[i1];
            i++;
            i1++;
            continue;
        }
        if(a[i1]<=k){
            x[i]=a[i1];
            i++;
            i1++;
            continue;
        }
        flag=1;
        break;
    }
    while(i2<m){
        if(b[i2]==0){
            k++;
            x[i]=b[i2];
            i++;
            i2++;
            continue;
        }
        if(b[i2]<=k){
            x[i]=b[i2];
            i++;
            i2++;
            continue;
        }
        flag=1;
        break;
    }
    if(flag){
        cout<<"-1"<<"\n";
        return;
    }
    vdbg(x);
    cout<<"\n";
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
