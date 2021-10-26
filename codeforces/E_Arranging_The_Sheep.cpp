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

ll minMoves(vector<ll>& nums, ll k) {
    vector<ll> ones;
    for (ll i=0; i<nums.size(); i++) {
        if (nums[i] == 1) ones.push_back(i);
    }
    ll zeroespref[nums.size()];
    for (ll i=0; i<nums.size(); i++) {
        if (i == 0) {
            zeroespref[0] = (nums[0] == 0 ? 1 : 0);
        }
        else {
            zeroespref[i] = zeroespref[i-1] + (nums[i] == 0 ? 1 : 0);
        }
    }
    
    ll n = ones.size();
    ll right=k-1;
    ll left=0;
    ll mindist = 0;
    
        // centered at 0
    for (ll i=0; i<k; i++) {
        mindist += zeroespref[ones[i]] - zeroespref[ones[0]];
    }
    
    ll curdist = mindist;
    
        // centered at i
    for (ll i=1; i<n; i++) {
        ll zeroeschange = zeroespref[ones[i]] - zeroespref[ones[i-1]];
        curdist += (i - left)*zeroeschange;
        curdist -= (right - i + 1)*zeroeschange;
        
        while (right+1<n) {
            ll zeroesleft = zeroespref[ones[i]] - zeroespref[ones[left]];
            ll zeroesright = zeroespref[ones[right+1]] - zeroespref[ones[i]];
            if (zeroesright < zeroesleft) {
                curdist -= zeroesleft;
                curdist += zeroesright;
                right++;
                left++;
            }
            else break;
        }
        mindist = min(mindist, curdist);
        
        if (right == i && right+1 < n) {
            ll zeroesleft = zeroespref[ones[i]] - zeroespref[ones[left]];
            ll zeroesright = zeroespref[ones[right+1]] - zeroespref[ones[i]];
            curdist -= zeroesleft;
            curdist += zeroesright;
            right++;
            left++;
        }
    }
    
    return mindist;
}
 

void solve(){
    ll n;
    cin >> n;
    vector<char>c(n);
    vector<ll>a(n);
    ll ones = 0;
    for(ll i=0; i<n; i++){
        cin >> c[i];
        if(c[i] == '.'){
            a[i] = 0;
        }else if(c[i]=='*'){
            a[i] = 1;
            ones++;
        }
    }
    // for(auto x: a){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";
    ll ans = minMoves(a,ones);
    // if(ans == 2147483647) ans = 0;
    cout<<ans<<"\n";
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