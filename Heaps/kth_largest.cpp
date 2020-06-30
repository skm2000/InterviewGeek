#include<bits/stdc++.h>
using namespace std;

// using a min-heap (largest-min-heap)
int findKthLargest(vector<int>& nums, int k,int n) {
    priority_queue<int, vector<int>, greater<int>>min_heap;
    for(int i=0;i<nums.size();i++){
        min_heap.push(nums[i]);
        if(min_heap.size()>k){
            min_heap.pop();
        }
    }                                   
    return min_heap.top();
}


int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<findKthLargest(v,k,n)<<"\n";
}