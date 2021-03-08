#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>freq(n+1,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        freq[a[i]]++;
    }
    int no = -1,ind = -1;
    for(int i=1;i<=n;i++){
        if(freq[i] == 1){
            no = i;
            break;
        }
    }
    if(no == -1) cout<<-1<<"\n";
    else{
        for(int i=0;i<n;i++){
            if(a[i] == no){
                ind = i;
                break;
            }
        }
        cout<<ind+1<<"\n";
    }
}


int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}      