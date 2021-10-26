#include<bits/stdc++.h>
#define dbg(x) cout<<#x<<" = "<<x<<endl
using namespace std ;
 
const int N = 2e5+5 ;
 
int t ;
string str ;
vector<int> idx[128] ;
bool ok(int i){
    for(int ch='a';ch<='z';++ch){
        if(idx[ch].size()==0) continue ;
        if(idx[ch].back()<i) return 0;
    }
    return 1;
}
int main(){
    cin >> t ;
    while(t--){
        for(int i='a';i<='z';++i) idx[i].clear() ;
        cin >> str ;
        for(int i=0;i<str.size();++i) idx[str[i]].push_back(i) ;
        string ans = "" ;
        int cur = -1 ;
        set<char> st ;
        for(char ch:str) st.insert(ch) ;
        int len = st.size() ;
        while(len--){
            for(int i='z';i>='a';--i){
                if(idx[i].size()==0) continue ;
                int j = *upper_bound(idx[i].begin(),idx[i].end(),cur) ;
                if(ok(j)){
                    // dbg(j);
                    cur = j ;
                    ans += i ;
                    idx[i].clear() ;
                    break ;
                }
            }
        }
        cout << ans << endl ;
    }
    return 0;
}