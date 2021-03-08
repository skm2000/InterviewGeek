#include<bits/stdc++.h>
#define ll long long
using namespace std;

int check(vector<int>&a, int k){
    int sum = 0,total = 0,j = 0;
    for(int i=0;i<a.size();i++){
        sum += a[i];
        if(sum == k){
            total += (i-j);
            j = i + 1;
            sum = 0;
        }
        else if(sum>k){
            return -1;
        }
    }
    return total;
}

void solve(){
    int n,total=0;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        total += a[i];
    }
    int ans = n-1,f1,f2,a1,a2;
    for(int i=1;i<=total;i++){
        if(total%i == 0){
            f1 = i;
            f2 = total/i;
            a1 = check(a,f1);
            a2 = check(a,f2);
            if(a1 != -1){
                ans = min(ans,a1);
            }
            if(a2 != -1){
                ans = min(ans,a2);
            }
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}    