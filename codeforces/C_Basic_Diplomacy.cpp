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
    ll n, m, k, x;
    cin >> n >> m;
    vector<vector<ll>>day(m);
    vector<pair<ll,ll>>ans;
    unordered_map<ll,ll>mp;
    set<ll>finished;
    ll limit = (m+1)/2;
    bool ok = true;
    for(ll i=0; i<m; i++){
        cin >> k;
        vector<ll>v;
        for(ll j=0; j<k; j++){
            cin >> x;
            v.push_back(x);
        }
        day[i] = v;
        if(day[i].size() == 1){
            ans.push_back({i,day[i][0]});
            mp[day[i][0]]++;
            finished.insert(i);
        }
        if(mp[day[i][0]] > limit){
            ok = false;
        }
    }

    if(ok) {
        for(ll i=0; i<m; i++){
            if(finished.count(i) == 0){
                for(ll j=0; j<day[i].size(); j++){
                    if(mp[day[i][j]] < limit){
                        mp[day[i][j]]++;
                        ans.push_back({i,day[i][j]});
                        finished.insert(i);
                        break;
                    }
                }
            }
        }
        if(ans.size() < m){
            cout<<"NO"<<"\n";
            return;
        }
        cout<<"YES"<<"\n";
        sort(ans.begin(), ans.end());
        for(auto x : ans){
            cout<<x.second<<" ";
        }
        cout<<"\n";
        return;
    }
    cout << "NO\n";
}


int main()
{
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}