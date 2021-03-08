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
    ll h,m;
    cin >> m >> h;
    double bmi = ((m*1.0)/(h*h*1.0));
    // dbg(bmi);
    if(bmi <= 18){
        cout<<1<<"\n";
    }else if(bmi>=19 && bmi<=24){
        cout<<2<<"\n";
    }else if(bmi>=25 && bmi<=29){
        cout<<3<<"\n";
    }else{
        cout<<4<<"\n";
    }
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