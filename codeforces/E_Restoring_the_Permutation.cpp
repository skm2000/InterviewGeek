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
    vector<ll>a(n);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll x[n];
    memset(x,-1,sizeof(x));
    set<ll> st;
    x[0]=a[0];
    st.insert(a[0]);
    for(ll i=1;i<n;i++)
    {
        if(a[i]!=a[i-1])
        {
            x[i]=a[i];
            st.insert(a[i]);
        }
    }
    vector<ll> v;
    for(ll i=1;i<=n;i++)
    {
        if(st.find(i)==st.end())
        {
            v.push_back(i);
        }
    }
    ll p=0;
    for(ll i=0;i<n;i++)
    {
        if(x[i]!=-1)
            cout<<x[i]<<" ";
        else
            cout<<v[p++]<<" ";
    }
    cout<<endl;
    for(ll i=0;i<n;i++)
    {
        if(x[i]!=-1)
            cout<<x[i]<<" ";
        else
        {
            ll indx=lower_bound(v.begin(),v.end(),a[i])-v.begin()-1;
            // dbg(indx);
            cout<<v[indx]<<" ";
            v.erase(v.begin()+indx);
        }
    }
    cout<<endl;
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