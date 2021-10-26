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
    ll a,b,c;
    cin >> a >> b >> c ;
    string s;
    for(ll i=1; i<=a; i++){
        s += '1';
    }
    ll g = stoi(s);
    if(a == 1 && b == 1){
        cout<<1<<" "<<1<<"\n";
        return;
    }
    if(c == 1){
        cout<<g<<" ";
        cout<<1;
        for(ll i=1; i<b; i++){
            cout<<0;
        }
        cout<<"\n";
        return;
    }
    for(ll i=1;i<=a+1-c;i++) cout<<1;
    for(ll i=1;i<=c-1;i++) cout<<0;
    cout<<" ";
    cout<<1;
    for(ll i=1;i<=b-1;i++) cout<<0;
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

// ll i, j, s = 0, c, k = 0, q = 0, m = 0, e = 1, f = 1, x, y, ans = INF, p = 0, r, a, b, d, len, ct = 0,n,h,l;
//         cin>>a>>b>>c;
//         if(a==1 && b==1){
//             cout<<"1 1" nl;con;
//         }
//         if(c==1){
//             for(i=1;i<=a;i++) cout<<1;
//             cout<<" ";
//             cout<<1;
//             for(i=1;i<=b-1;i++) cout<<0;
//             cout nl;
//             con;
//         }
//         for(i=1;i<=a+1-c;i++) cout<<1;
//         for(i=1;i<=c-1;i++) cout<<0;
//         cout<<" ";
//         cout<<1;
//         for(i=1;i<=b-1;i++) cout<<0;
//         cout nl;


