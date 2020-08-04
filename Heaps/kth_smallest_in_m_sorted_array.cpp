#include<bits/stdc++.h>
using namespace std;

class kthSmallest{
    public:
    int findKthSmallest(vector<vector<int>>&lists,int k){
        struct compare{
            bool operator()(const pair<int,pair<int,int>> &x, const pair<int,pair<int,int>> &y){
                return x.first > y.first;
            }
        };
        // use a min_heap
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,compare>min_heap;
        // put the first element of every list in a min_heap
        for(int i=0;i<lists.size();i++){
            if(!lists[i].empty()){
                min_heap.push({lists[i][0],{i,0}});
            }
        }
        int result,count=0;
        while(!min_heap.empty()){
            auto node = min_heap.top();
            min_heap.pop();
            result = node.first;
            if(++count == k){
                break;
            }
            node.second.second++;
            if(lists[node.second.first].size() > node.second.second){
                node.first = lists[node.second.first][node.second.second];
                min_heap.push(node);
            }
        }
        return result;
    }
};