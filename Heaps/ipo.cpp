#include<bits/stdc++.h>
using namespace std;

// leetcode question
// use 2 heaps to solve,similar to running median and sliding window median
class Solution {
public:
    struct compare1{
        bool operator()(const pair<int,int> &x,const pair<int,int> &y){
            return x.first < y.first;
        }
    };
    struct compare2{
        bool operator()(const pair<int,int> &x,const pair<int,int> &y){
            return x.first > y.first;
        }
    };
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare1>maxProfitHeap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare2>minCapitalHeap;
        for(int i=0;i<Capital.size();i++){
            minCapitalHeap.push({Capital[i],i});
        }
        for(int i=0;i<k;i++){
            while(!minCapitalHeap.empty() && minCapitalHeap.top().first<=W){
                auto capIndex = minCapitalHeap.top().second;
                minCapitalHeap.pop();
                maxProfitHeap.push({Profits[capIndex],capIndex});
            }
            if(maxProfitHeap.empty()){
                break;
            }
            W += maxProfitHeap.top().first;
            maxProfitHeap.pop();
        }
        return W;
    }
};