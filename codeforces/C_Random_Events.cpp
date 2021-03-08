#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int l = 0;
        for(int i=n-1;i>=0;i--){
            if(a[i] != i+1){
                l = i;
                break;
            }
        }
        l = l+1;
        int r;
        double p,t=1,ans=0;
        for(int i=0;i<m;i++){
            cin>>r>>p;
            if(r >= l){
                ans += t*p;
                t = (1-p)*t;
            }
        }
        if(l == 1) ans = 1.0;
        cout<<fixed<<setprecision(6)<<ans<<"\n";
    }
}