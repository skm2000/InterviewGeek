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

    ll i,m=0,s=0;
    string t;
    cin>>t;
    vector<ll>freq(30,0);
    for(i=0;i<t.size();i++) freq[t[i]-'a']++;
    for(i=0;i<30;i++) {
        if(freq[i]==0) continue;
        if(freq[i]==1) s++;
        // else if(freq[i]==2) m++;
        else if (freq[i]%2==0) {m+=freq[i]/2;}
        else {
            m=m+(freq[i]-3)/2;
        }
    }
    if(m>=s) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
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