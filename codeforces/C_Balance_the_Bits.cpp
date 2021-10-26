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

bool match(char a,char b){
    return (a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']');
}
bool isValid(string s) {
    stack<int>st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else{
            if(st.empty()) return false;
            else if(match(st.top(),s[i])==false){
                return false;
            }
            else{
                st.pop();
            }
        }
    }
    return (st.empty()==true);
}
 

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll>a(n);
    for(ll i=0; i<n; i++){
        a[i] = s[i]-'0';
    }
    if(a[0] == 0){
        cout<<"NO"<<"\n";
        return;
    }
    vector<char>ans1(n);
    vector<char>ans2(n);
    for(ll i=0; i<n/2; i++){
        if(i%2 == 0){
            ans1[i] = '(';
        }else{
            ans1[i] = ')';
        }
    }
    ll cost = 0;
    for(ll i=0; i<n; i++){
        if(a[i] == 1){
            ans2[i] = ans1[i];
            if(ans1[i] == '('){
                cost++;
            }else{
                cost--;
            }
        }else{
            if(ans1[i] == '('){
                cost++;
                ans2[i] = ')';
            }else{
                cost--;
                ans2[i] = '(';
            }
        }
    }
    if(cost != 0){
        cout<<"NO"<<"\n";
        return;
    }
    string c1="",c2="";
    for(ll i=0; i<n; i++){
        c1 += ans1[i];
        c2 += ans2[i];
    }
    if(isValid(c1) && isValid(c2)){
        cout<<"YES"<<"\n";
        cout<<c1<<"\n";
        cout<<c2<<"\n";
        return;
    }
    cout<<"NO"<<"\n";
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