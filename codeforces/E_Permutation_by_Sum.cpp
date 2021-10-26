#include <bits/stdc++.h>  
#define ll                     long long  
#define MAX                    1000007
#define dbg(x)                 cout<<#x<<" = "<<x<<endl
#define vdbg(v)                for(auto x : v) cout<<x<<endl
#define INF                    2e18
#define all(x)                 x.begin(),x.end()
#define mem0(a)                memset(a,0,sizeof(a))
#define mem1(a)                memset(a,-1,sizeof(a))
#define fast_cin()             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll N = 1e5+7;
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;

bool isPossible(ll len, ll s, ll n){
    ll d = n, maxi=0, mini=0;
    for(ll i=1; i<=len; i++){
        mini += i;
        maxi += d;
        d--;
    }
    if(s>maxi || s<mini){
        return false;
    }
    return true;
}
 

void solve(){
    ll n,l,r,s;
    cin >> n >> l >> r >> s;
    ll d = n, maxi = 0, mini = 0, len = r-l+1;
    for(ll i=1; i<=len; i++){
        mini += i;
        maxi += d;
        d--;
    }
    if(s>maxi || s<mini){
        // cout<<"hre";
        cout<<-1<<"\n";
        return;
    }
    vector<ll>ans;
    map<ll,ll>mp;
    for(ll i=n; i>=1; i--){
        if(s-i >=0 && isPossible(len-1, s-i, i-1)){
            s -= i;
            len--;
            ans.push_back(i);
            mp[i]++;
        }
        if(s == 0){
            break;
        }
    }
    // for(auto x: ans) cout<<x<<" ";
    // cout<<"\n";
    if(s != 0){
        cout<<-1<<"\n";
        return;
    }
    vector<ll>rem;
    for(ll i=1; i<=n; i++){
        if(mp.find(i) == mp.end()){
            rem.push_back(i);
        }
    }
    ll j = 0, k = 0;
    for(ll i=1; i<l; i++){
        cout<<rem[j++]<<" ";
    }
    for(ll i=l; i<=r; i++){
        cout<<ans[k++]<<" ";
    }
    for(ll i=r+1; i<=n; i++){
        cout<<rem[j++]<<" ";
    }
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