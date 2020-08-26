#include<bits/stdc++.h>
using namespace std;

// good question
// problem : https://leetcode.com/problems/longest-increasing-path-in-a-matrix
class Solution {
private:
    int dfs(vector<vector<int>>&matrix,int i,int j,int prev,vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || prev >= matrix[i][j]) return 0;
        else if(dp[i][j] != 0) return dp[i][j];
        int path1 = dfs(matrix,i+1,j,matrix[i][j],dp);
        int path2 = dfs(matrix,i-1,j,matrix[i][j],dp);
        int path3 = dfs(matrix,i,j+1,matrix[i][j],dp);
        int path4 = dfs(matrix,i,j-1,matrix[i][j],dp);
        dp[i][j] = 1+max({path1,path2,path3,path4});
        return dp[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size(),m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j] == 0){
                    dfs(matrix,i,j,INT_MIN,dp);
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};