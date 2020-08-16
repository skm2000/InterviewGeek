#include<bits/stdc++.h>
using namespace std;

// problem : https://leetcode.com/problems/unique-paths-iii
// good problem of dfs

class Solution {
int res = 0,empty = 1;
private:
    void dfs(vector<vector<int>>& grid,int x,int y){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y] < 0) return;
        if(grid[x][y] == 2){
            if(empty == 0) res++;
            return;
        }
        
        grid[x][y] = -2;
        empty--;
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
        grid[x][y] = 0;
        empty++;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x,y;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 0){
                    empty++;
                }
                else if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }
            }
        }
        dfs(grid,x,y);
        return res;
    }
};