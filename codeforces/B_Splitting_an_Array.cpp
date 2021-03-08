#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll n,k;
vector<ll>a;

bool check(ll sum){
    ll seg = 1;
    ll temp = 0;
    bool flag = 1;
    for(ll i=0; i<n; i++) {
        if(a[i] > sum) {
            flag = 0; 
            break;
        }
        if(temp + a[i] <= sum) {
            temp += a[i];
        } else {
            temp = a[i];
            seg++;
        }
    }
    if(flag == 1) {
        return seg <= k;
    } else {
        return 0;
    }
}

void solve(){
    cin>>n>>k;
    a.resize(n);
    ll low=0,high=0,mid;
    for(auto &i : a){
        cin>>i;
        high += i;
    }
    // high += 100;
    // cout<<high;
    while(high-low>1){
        mid = (low+high)/2;
        // cout<<mid<<" ";
        if(check(mid)){
            high = mid;
        }else{
            low = mid;
        }
    }
    cout<<high<<"\n";
}

int main(){
    ll t;
    t = 1;
    while(t--){
        solve();
    }