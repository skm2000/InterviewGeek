#include<bits/stdc++.h>
using namespace std;

// problem : https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
private:
    void dfs(vector<vector<int>>&matrix,int row,int col,int pre,vector<vector<int>>&temp){
        if(row<0 || row>=matrix.size() || col<0 || col>=matrix[0].size() || temp[row][col]==1 || pre>matrix[row][col]) return;
        temp[row][col] = 1;
        dfs(matrix,row+1,col,matrix[row][col],temp);
        dfs(matrix,row-1,col,matrix[row][col],temp);
        dfs(matrix,row,col+1,matrix[row][col],temp);
        dfs(matrix,row,col-1,matrix[row][col],temp);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>>ans;
        if(matrix.empty()) return ans;
        int row = matrix.size(),col = matrix[0].size();
        vector<vector<int>>pac(row,vector<int>(col,0));
        vector<vector<int>>atl(row,vector<int>(col,0));
//         first row of pacific ocean
        for(int i=0;i<col;i++){
            dfs(matrix,0,i,INT_MIN,pac);
        }
//         first col of pacific ocean
        for(int i=0;i<row;i++){
            dfs(matrix,i,0,INT_MIN,pac);
        }
//         first row of atlantic ocean
        for(int i=0;i<col;i++){
            dfs(matrix,row-1,i,INT_MIN,atl);
        }
//         first col of atlantic ocean
        for(int i=0;i<row;i++){
            dfs(matrix,i,col-1,INT_MIN,atl);
        }
//         the place where both waters meet will be the place where both values of pac and atl matrix are 1
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(pac[i][j]==1 && atl[i][j]==1){
                    vector<int>t(2);
                    t[0] = i;
                    t[1] = j;
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};