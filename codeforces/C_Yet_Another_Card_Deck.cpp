#include <bits/stdc++.h>  
#define ll long long  
const ll mod = 1000000007;  
using namespace std;
ll MOD = 998244353;
#define MAX 1000007
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define vdbg(v) for(auto x : v) cout<<x<<endl
#define INF 2e18
const ll N = 1e5+7;
#define all(x) x.begin(),x.end()
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll fact[MAX]; 
ll invFact[MAX];
ll lp[N+1];
vector<ll> pr;


void sieveMinmPrimeFactor(){
    for (ll i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (ll j=0; j<(ll)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}


void factorial(){
    fact[0] = 1;
    for(ll i=1;i<MAX;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
}


void modInverse(){
    invFact[0] = invFact[1] = 1;
    for(ll i=2;i<MAX;i++) invFact[i] = (mod - mod/i) * invFact[mod % i] % mod;
    for(ll i=1;i<MAX;i++) invFact[i] = (invFact[i-1] * invFact[i])%mod;
}


ll nCr(ll n, ll r){
   return (((fact[n]*invFact[r])%mod)*invFact[n-r])%mod;
}

const ll maxn=N;
template<typename NODE,typename UPDATE>
struct segtree {
    bool built=false,lazy[4*maxn];
    NODE zero=NODE(),t[4*maxn];
    UPDATE noop=UPDATE(),upds[4*maxn];
    ll tl[4*maxn],tr[4*maxn];
    inline void pushdown(ll v) {
        if(lazy[v]){
            apply(v*2,upds[v]);
            apply(v*2+1,upds[v]);
            lazy[v]=0;
            upds[v]=noop;
        }
    }
    inline void apply(ll v,UPDATE &val) {
        if(tl[v]!=tr[v]){
           lazy[v]=1;
           upds[v].combine(val,tl[v],tr[v]);
        }
        val.apply(t[v],tl[v],tr[v]);
    }
    template<typename T>
    void build(T a, ll v, ll l, ll r) {
        tl[v]=l;
        tr[v]=r;
        if(l == r) {
          t[v]=a[l];
          return;
        } else {
           ll tm = (l + r) / 2;
           build(a, v*2, l, tm);
           build(a, v*2+1, tm+1, r);
           t[v].merge(t[v*2],t[v*2+1]);
        }
    }
    NODE query(ll v, ll l, ll r) {
        if (l > tr[v] || r < tl[v])
           return zero;
        if (l <= tl[v] && tr[v] <= r) {
           return t[v];
        }
        pushdown(v);
        NODE a,b,ans;
        a=query(v*2, l, r);
        b=query(v*2+1, l, r);
        ans.merge(a,b);
        return ans;
    }
    void rupd(ll v, ll l, ll r, UPDATE &val) {
        if (l > tr[v] || r < tl[v])
           return;
        if (l <= tl[v] && tr[v] <= r) {
            apply(v,val);
            return;
        }
        pushdown(v);
        rupd(v*2,l,r,val);
        rupd(v*2+1,l,r,val);
        t[v].merge(t[v*2],t[v*2+1]);
    }
    template<typename T>
    ll descent_right(ll l, T x, ll v, NODE &prev) {
        if (l > tr[v]) // node is completely out of range
           return len;
        if (l <= tl[v]){ // node is completely in range
            NODE cur;
            cur.merge(prev,t[v]);
            if (!cur.check(x)) { // go further right than this node
                swap(prev,cur); // merging this node's contribution
                return len;
            }
            if (tl[v]==tr[v]) {
                 return tr[v];
            }
        }
        pushdown(v);
        ll ans=descent_right(l, x, v*2, prev); // trying to find in left child
        if(ans!=len)return ans; // found in left child
        return descent_right(l, x, v*2+1, prev); // finding in right child
    }
    template<typename T>
    ll descent_left(ll r, T x, ll v, NODE &prev) {
        if (r < tl[v]) // node is completely out of range
             return -1;
        if (r >= tr[v]){ // node is completely in range
            NODE cur;
            cur.merge(t[v],prev);
            if (!cur.check(x)) { // go further left than this node
                swap(cur,prev); // merging this node's contribution
                return -1;
            }
            if (tl[v]==tr[v]) {
                return tl[v];
            }
        }
        pushdown(v);
        ll ans=descent_left(r, x, v*2+1, prev); // trying to find in right child
        if(ans!=-1)return ans; // found in right child
          return descent_left(r, x, v*2, prev); // finding in left child
    }
    ll len=maxn;
    void clear() {
       fill(t,t+4*len,zero);
       fill(lazy,lazy+4*len,false);
       fill(upds,upds+4*len,noop);
       built = false;
    }
    template<typename T>
    void build(T a) {
        build(a,1,0,len-1);
        built=true;
    }
    template<typename T>
    ll descent_right(ll l, T x) { // minimum r such that [l...r].check(x) == true, returns segtree.len if not found
        NODE prev=zero;
        return descent_right(l,x,1,prev);
    }
    template<typename T>
    ll descent_left(ll r, T x) { // maximum l such that [l...r].check(x) == true, returns -1 if not found
        NODE prev=zero;
        return descent_left(r,x,1,prev);
    }
    NODE query(ll l,ll r) {
        if(!built)build(t);
           return query(1,l,r);
    }
    void rupd(ll l,ll r,UPDATE val) {
        if(!built)build(t);
           rupd(1,l,r,val);
    }
};



#define node node1
#define update update1
struct node {
    node(){}
    // store the value for the leaf
    node(ll val){
    }
    void merge(node &l,node &r) {
    }
    bool check(ll x){
       return false;
    }
};
struct update{
    ll v;
    update(){}
    update(ll val) {
    }
    void combine(update &other,ll tl,ll tr) {
        // only needed for range updates->lazy propagation,other is the new update that has arrived
    }
    void apply(node &x,ll tl,ll tr) {
    }
};


segtree<node,update> t;
#undef node
#undef update

unordered_map<ll,ll>mc;
 // for(auto p : mc){
    //     cout<<p.first<<" "<<p.second<<"\n";
    // }
 map<ll,ll>im;
 ll n, q;

void solve(){
    cin >> n;
    cin >> q;
    
    vector<ll>cxi(n);
    for(ll i=0; i<n; i++){
        cin >> cxi[i];
        mc[cxi[i]] = -1;
    }
    // dbg(mc.size());
    for(ll i=0; i<n; i++){
        if(mc[cxi[i]] == -1){
            mc[cxi[i]] = i+1;
        }
    }
    while(q--){
        ll query;
        cin>>query;
        cout<<mc[query]<<" ";
        for(auto y : mc){
            if(y.second < mc[query]){
                mc[y.first] = y.second + 1;
            }
        }
        mc[query] = 1;
    }
}


int main()
{
    fast_cin();
    ll t;
    // cin >> t;
    t = 1;
    while(t--) {
        solve();
    }
    return 0;
}