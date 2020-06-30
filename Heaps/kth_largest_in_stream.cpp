#include<bits/stdc++.h>
using namespace std;

// problem : https://leetcode.com/problems/kth-largest-element-in-a-stream/
// take a min-heap

class KthLargest {
    priority_queue<int,vector<int>,greater<int>>min_heap;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i=0;i<nums.size();i++){
            min_heap.push(nums[i]);
            if(min_heap.size()>k){
                min_heap.pop();
            }
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        if(min_heap.size()>size){
            min_heap.pop();
        }
        return min_heap.top();
    }
};