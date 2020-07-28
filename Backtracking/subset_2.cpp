#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>subs;
        vector<int>sub;
        subsets(nums,0,sub,subs);
        return subs;
    }
private:
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
//             condition similar to 3-sum
            if(j==i || nums[j] != nums[j-1]){
                sub.push_back(nums[j]);
                subsets(nums, j + 1, sub, subs);
                sub.pop_back();
            }
        }
    }
};