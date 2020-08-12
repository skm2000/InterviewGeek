#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>&grid,int x,int y){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==1) return;
        grid[x][y] = 1;
        dfs(grid,x+1,y);
        dfs(grid,x,y+1);
        dfs(grid,x-1,y);
        dfs(grid,x,y-1);
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
//             make all edges with value of 0 to 1(since they will never be surrounded by 1 in all 4 sides)
                if((i == 0 || i == grid.size()-1 || j == 0 || j == grid[0].size()-1) && grid[i][j] == 0){
                    dfs(grid,i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 0){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};