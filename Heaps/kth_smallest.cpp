#include<bits/stdc++.h>
using namespace std;

// use a max heap (smallest=>max-heap)
int findKthSmallest(vector<int>&nums, int k,int n) {
    priority_queue<int>max_heap;
    for(int i=0;i<n;i++){
        max_heap.push(nums[i]);
        if(max_heap.size()>k) {
            max_heap.pop();
        }
    }
    return max_heap.top();
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<findKthSmallest(v,k,n)<<"\n";
}