#include<bits/stdc++.h>
using namespace std;

// a common approach and code for :
// 1) Best Time To Buy and Sell Stock-1.
// 2) Best Time To Buy and Sell Stock-2.
// 3) Best Time To Buy and Sell Stock-3.
// 4) Best Time To Buy and Sell Stock-4.


/*COMMON FOR ALL */
class Solution {
private:
    int printMax(vector<vector<int>>&dp,int row){
        int ans=0;
        for(int i=0;i<dp[0].size();i++){
            ans = max(ans,dp[row][i]);
        }
        return ans;
    }
    int profit(int k, vector<int>& prices) {
        if(k == 0 || prices.size()<2) return 0;
        if(k > prices.size()/2) k = prices.size()/2;
        vector<vector<int>>dp(k+1,vector<int>(prices.size(),0));
        int minm = prices[0],p=0;
        for(int i=0;i<prices.size();i++){
            minm = min(prices[i],minm);
            p = max(prices[i]-minm,p);
            dp[1][i] = p;
        }
        for(int i=2;i<=k;i++){
            int b2 = INT_MAX;
            int p2 = 0;
            for(int j=0;j<prices.size();j++){
                b2 = min(b2,prices[j]-dp[i-1][j]);
                p2 = max(prices[j]-b2,p2);
                dp[i][j] = p2;
            }
        }
        return printMax(dp,k);
    }
public:
// 1) Best Time To Buy and Sell Stock-1.(passed all testcases)
    int maxProfit(vector<int>& prices) {
        return profit(1,prices);
    }
// 2) Best Time To Buy and Sell Stock-2.(passed 199/200 testcases)
    int maxProfit(vector<int>& prices) {
        return profit(prices.size()/2,prices);
    }
// 3) Best Time To Buy and Sell Stock-3. (passed all testcases)
    int maxProfit(vector<int>& prices) {
        return profit(2,prices);
    }
// 4) Best Time To Buy and Sell Stock-4. (passed 209/211 testcases)
    int maxProfit(int k,vector<int>& prices) {
        return profit(k,prices);
    }
};

// better approach for 1) Best Time To Buy and Sell Stock-1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),max_cur=0,max_far=0,sum=0;
        int *diff = new int[n+1];
        diff[0]=0;
        for(int i=1;i<n;i++){
            diff[i]=prices[i]-prices[i-1];
        }
        max_cur=diff[0],max_far=diff[0];
        for(int i=1;i<n;i++){
            max_cur=max(max_cur+diff[i],diff[i]);
            max_far=max(max_cur,max_far);
        }
        return max_far;
    }
};

// better approach for 2) Best Time To Buy and Sell Stock-2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int profit=0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i+1]>prices[i]){
                profit+=prices[i+1]-prices[i];
            }
        }
        return 0;
    }
};
