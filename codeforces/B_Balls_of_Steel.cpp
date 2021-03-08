#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n,k,dis,ans=0;
    cin>>n>>k;
    vector<pair<int,int>>p;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        p.push_back({x,y});
    }
    
    /* for(int i=0;i<n;i++){
        cout<<p[i].first<<" "<<p[i].second<<"\n";
    } */

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                dis = abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second);
                if(dis <= k){
                    ans++;
                }
            }
        }
        if(ans == n-1){
            ans = 1;
            break;
        }else{
            ans = 0;
        }
    }
    if(ans == 0) cout<<-1<<"\n";
    else cout<<1<<"\n";
}


int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}        