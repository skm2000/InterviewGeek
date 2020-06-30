#include<bits/stdc++.h>
using namespace std;

// problem : https://leetcode.com/problems/top-k-frequent-words/

class Solution {
private:
    struct comparator {
//         operator overloading
        bool operator()(const pair<int,string>&s1,const pair<int,string>&s2) {
            if(s1.first != s2.first) {
//                 returns true if s1.first is less than s2.first
                return s1.first < s2.first;
            }
            return s1.second > s2.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
//         when we want to sort the heap in a particular order alaways define comparator
        priority_queue<pair<int,string>,vector<pair<int,string>>,comparator>heap;
        for(auto it:mp){
            heap.push({it.second,it.first});
        }
//         printing the values
        // while(heap.size() != 0){
        //     cout<<heap.top().first<<" "<<heap.top().second<<"\n";
        //     heap.pop();
        // }
        vector<string>ans;
        while(!heap.empty() && k-->0){
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};