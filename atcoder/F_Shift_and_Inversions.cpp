    #include<bits/stdc++.h>
    using namespace std;
    int A[300001],tree[1200000];
    void build(int node, int start, int end)
    {
        if(start == end)
        {
            // Leaf node will have a single element
            tree[node] = A[start];
        }
        else
        {
            int mid = (start + end) / 2;
            // Recurse on the left child
            build(2*node, start, mid);
            // Recurse on the right child
            build(2*node+1, mid+1, end);
            // Internal node will have the sum of both of its children
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
    void update(int node, int start, int end, int idx, int val)
    {
        if(start == end)
        {
            // Leaf node
            A[idx] += val;
            tree[node] += val;
        }
        else
        {
            int mid = (start + end) / 2;
            if(start <= idx and idx <= mid)
            {
                // If idx is in the left child, recurse on the left child
                update(2*node, start, mid, idx, val);
            }
            else
            {
                // if idx is in the right child, recurse on the right child
                update(2*node+1, mid+1, end, idx, val);
            }
            // Internal node will have the sum of both of its children
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
    int query(int node, int start, int end, int l, int r)
    {
        if(r < start or end < l)
        {
            // range represented by a node is completely outside the given range
            return 0;
        }
        if(l <= start and end <= r)
        {
            // range represented by a node is completely inside the given range
            return tree[node];
        }
        // range represented by a node is partially inside and partially outside the given range
        int mid = (start + end) / 2;
        int p1 = query(2*node, start, mid, l, r);
        int p2 = query(2*node+1, mid+1, end, l, r);
        return (p1 + p2);
    }
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        build(1,0,n-1);
        long long ans=0;
        for(int j=0;j<n;j++)
        {
            ans+=query(1,0,n-1,a[j],n);
            update(1,0,n-1,a[j],1);
        }
        for(int i=0;i<n;i++)
        {
            cout<<ans<<endl;
            ans+=n-2*a[i]-1;
        }
    }