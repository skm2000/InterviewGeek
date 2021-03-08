#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve(){

    /* TLE
    int n;
    cin>>n;
    vector<int>a(n);
    unordered_set<int>u;
    vector<int>unique;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(u.count(a[i]) == 0){
            u.insert(a[i]);
        }
    }
    int c,no,ans=INT_MAX;
    if(unique.size() == n){
        ans = 1;
    }
    else{
        for (auto it = u.begin(); it != u.end(); ++it){
            unique.push_back(*it);
        }
        for(int i=0;i<unique.size();i++){
            vector<int>pos;
            pos.clear();
            c=0;no=unique[i];
            for(int j=0;j<n;j++){
                if(a[j] == no){
                    pos.push_back(j);
                }
            }
            if(pos[0] != 0) c++;
            if(pos[pos.size()-1] != n-1) c++;
            if(pos.size()>=0){c
                for(int i=0;i<pos.size()-1;i++){
                    if(pos[i] != pos[i+1]-1) c++;
                }
                ans = min(ans,c);
            }
        }
    }
    cout<<ans<<"\n";  */
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a) cin >> it;
    vector<int> res(n + 1, 1);
    n = unique(a.begin(), a.end()) - a.begin(); // removes all adjacent duplicates
    a.resize(n);
    // cout<<n<<"\n";
    // for (int i = 0; i < n; ++i) {
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";
    for (int i = 0; i < n; ++i) {
        res[a[i]]++;
    }
    res[a[0]]--;
    res[a[n - 1]]--;
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, res[a[i]]);
    }
    cout << ans << endl;
}


int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}      