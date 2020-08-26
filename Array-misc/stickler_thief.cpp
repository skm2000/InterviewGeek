#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums,int n){
    if(n == 0) return 0;
    else if(n == 1) return nums[0];
    else if(n == 2) return max(nums[0],nums[1]);
    else{
        vector<int>dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-1];
    }
}