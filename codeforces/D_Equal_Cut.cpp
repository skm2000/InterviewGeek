// #include<bits/stdc++.h>
// using namespace std;

// const int mod = 1e9+7;

// string LCP(string X, string Y)
// {
//     int i = 0, j = 0;
//     while (i < X.length() && j < Y.length())
//     {
//         if (X[i] != Y[j]) {
//             break;
//         }
//         i++, j++;
//     }
//     return X.substr(0, i);
// }

// int main(){
//     int n, ans= 0;
//     string s;
//     cin >> n;
//     unordered_map<int,vector<string>>mp;
//     vector<string>inputs;
//     for(int i=0; i<n; i++){
//         cin >> s;
//         inputs.push_back(s);
//         mp[s[0]-'a'].push_back(s);
//     }
//     for(auto x: mp){
//         sort(x.second.begin(),x.second.end());
//         for(int j=0; j<x.second.size(); j++){
//             string test = x.second[j];
//             for(int k=j+1; k<x.second.size(); k++){
//                 string next = x.second[k];
//                 int len = LCP(test, next).size();
//                 ans = (ans + (len%mod*len%mod)%mod)%mod;
//             }
//         }
//     }
//     cout<<(ans%mod)<<"\n";
// }



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

int maxProfit(int n, string x, string y)
{
    int lcs[n + 1][n + 1];
    int result = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                lcs[i][j] = 0;
 
            else if (x[i - 1] == y[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                result = max(result, lcs[i][j]);
            }
            else
                lcs[i][j] = 0;
        }
    }
    return result;
}

 

void solve(){
    ll n;
    cin >> n;
    string s,q;
    cin >> s >> q;
    cout<<maxProfit(n,s,q)<<"\n";
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

