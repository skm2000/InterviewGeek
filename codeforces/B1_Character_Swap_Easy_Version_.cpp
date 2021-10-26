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
    string s, t, t1, t2;
    cin >> s >> t;
    t1 = s;
    t2 = t;
    vector<ll>sindex;
    vector<ll>tindex;
    for(ll i=0; i<n; i++){
        if(s[i] != t[i]){
            sindex.push_back(i);
            tindex.push_back(i);
        }
    }
    if(sindex.size() > 2){
        cout<<"No"<<"\n";
        return;
    }
    if(sindex.size() == 1){
        swap(t1[sindex[0]],t2[tindex[0]]);
        if(t1 == t2){
            cout<<"Yes"<<"\n";
            return;
        }
    }
    if(sindex.size() == 2){
        swap(t1[sindex[0]],t2[tindex[0]]);
        if(t1 == t2){
            cout<<"Yes"<<"\n";
            return;
        }
        t1 = s;
        t2 = t;
        swap(t1[sindex[0]],t2[tindex[1]]);
        if(t1 == t2){
            cout<<"Yes"<<"\n";
            return;
        }
    }
    cout<<"No"<<"\n";
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