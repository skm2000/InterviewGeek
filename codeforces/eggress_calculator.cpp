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


vector<string>eggressCalculator(string cidr, vector<string>ipList){
    vector<string>ans;
    
}
 

void solve(){

    string s;
    cin >> s;
    ll n;
    cin >> n;
    vector<string>ipList;
    for(int i=0; i<n; i++){
        cin >> s;
        ipList.push_back(s);
    }

    vector<string>ans = eggressCalculator(s, ipList);
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