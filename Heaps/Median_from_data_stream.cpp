#include<bits/stdc++.h>
using namespace std;

// O(NlogN) time complexity
// O(N) space complexity
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<double>max_heap;
    priority_queue<double,vector<double>,greater<double>>min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.empty() && min_heap.empty()){
            max_heap.push(num);
            return;
        }
        if(num > max_heap.top()){
            min_heap.push(num);
            if(min_heap.size() - max_heap.size() > 1){
                int top = min_heap.top();
                min_heap.pop();
                max_heap.push(top);
            }
        }
        else{
            max_heap.push(num);
            if(max_heap.size() - min_heap.size() > 1){
                int top = max_heap.top();
                max_heap.pop();
                min_heap.push(top);
            }
        }
    }
    
    double findMedian() {
        int l = max_heap.size();
        int s = min_heap.size();
        if((l+s) % 2 == 1){
            if(l > s){
                return max_heap.top();
            }
            else{
                return min_heap.top();
            }
        }
        else{
          return (double)(max_heap.top()+min_heap.top())/2;  
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */