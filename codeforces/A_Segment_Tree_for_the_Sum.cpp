#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N = 100000;

ll n,m;
vector<ll>tree(2*N);


void build(vector<ll>&a){
    for(ll i=0;i<n;i++){
        tree[n+i] = a[i];
    }

    for(ll i=n-1;i>0;i--){
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

void modify(ll p, ll v){
    tree[p+n] = v;
    p = p+n;
    for(ll i=p;i>1;i/=2){
        tree[i/2] = tree[i] + tree[i^1];
    }
}

ll query(ll l,ll r){
    ll ans=0;
    for(l += n,r += n; l<r; l /= 2,r /= 2){
        if(l&1){
            ans += tree[l++];
        }
        if(r&1){
            ans += tree[--r];
        }
    }
    return ans;
}


void solve(){
    cin>>n>>m;
    vector<ll>a(n);
    for(auto &i : a){
        cin>>i;
    }
    build(a);
    ll ch,x,y;
    for(ll i=0;i<m;i++){
        cin>>ch>>x>>y;
        if(ch == 1){
            modify(x,y);
        }
        else{
            cout<<query(x,y)<<"\n";
        }
    }
}

int main(){
    ll t;
    t = 1;
    while(t--){
        solve();
    }
}