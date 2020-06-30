#include<bits/stdc++.h>
using namespace std;

vector<int> kMostFreq(vector<int>&nums,int k){
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
    for(auto it:mp){
        min_heap.push({it.second,it.first});
        if(min_heap.size()>k){
            min_heap.pop();
        }
    }
    vector<int>ans;
    while(min_heap.size()>0) {
        ans.push_back(min_heap.top().second);
        min_heap.pop();
    }
    return ans;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>ans;
    ans = kMostFreq(v,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}