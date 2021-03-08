#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 100000;
vector<ll>a(N);
pair<ll,ll>t[4*N];


pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) 
        return a;
    if (b.first < a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(INT_MAX, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_pair(new_val, 1);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}


void solve(){
	int n,m;
	cin>>n>>m;
    int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
    build(a,1,0,n-1);
	cout<<t[6].first;
	// cout<<query(1,0,5,0,3).first<<" "<<query(1,0,5,0,3).second<<"\n";
    // int ch,x,y;
    // for(int i=0;i<m;i++){
    //     cin>>ch>>x>>y;
    //     if(ch == 1){
    //         update(1,0,n-1,x,y);
    //     }
    //     else{
    //         cout<<query(1,0,n-1,x,y).first<<query(1,0,n-1,x,y).second<<"\n";
    //     }
    // }
}

int main(){
	int t;
	t = 1;
	while(t--){
		solve();
	}
}

















/* void build(vector<ll>&a){

    for(ll i=0;i<n;i++){
        tree[n+i] = {a[i],1};
        cout<<n+i<<" "<<tree[n+i].first<<" "<<tree[n+i].second<<endl;
    }
    cout<<"\n";
    for(ll i=n-1;i>0;i--){
        if(tree[2*i].first < tree[2*i+1].first){
            tree[i] = {tree[2*i].first,tree[2*i].second};
        }else if(tree[2*i+1].first < tree[2*i].first){
            tree[i] = {tree[2*i+1].first,tree[2*i+1].second};
        }else if(tree[2*i+1].first == tree[2*i].first){
            tree[i] = {tree[2*i].first,tree[2*i].second + tree[2*i+1].second};
        }
        cout<<i<<" "<<tree[i].first<<" "<<tree[i].second<<endl;
    }
}

void modify(ll p, ll v){
    tree[p+n].first = v;
    tree[p+n].second = 1;
    p += n;
    // cout<<p<<"**";
    for(ll i=p;i>1;i/=2){
        if(tree[i].first < tree[i^1].first){
            tree[i/2] = {tree[i].first,tree[i].second};
        }else if(tree[i^1].first < tree[i].first){
            tree[i/2] = {tree[i^1].first,tree[i^1].second};
        }else{
            tree[i/2] = {tree[i].first,tree[i].second + tree[i^1].second};
        }
    }
}

pair<ll,ll> query(ll l,ll r){
    pair<ll,ll>res;
    res.first = INT_MAX;
    res.second = 0;
    for(l += n,r += n; l<r; l /= 2,r /= 2){
        if(l&1){
            if(res.first >= tree[l].first){
                res.first = tree[l].first;
                res.second = tree[l].second;
            }
            l++;
        }
        if(r&1){
            --r;
            if(res.first >= tree[r].first){
                res.first = tree[r].first;
                res.second = tree[r].second;
            }
        }
    }
    // cout<<res.first<<" "<<res.second<<" ";
    return res;
}
 */