#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    int dfs(vector<vector<char>>&grid,int x,int y){
        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]=='1'){
            grid[x][y] = '0';
            return 1+dfs(grid,x+1,y)+dfs(grid,x-1,y)+dfs(grid,x,y+1)+dfs(grid,x,y-1);
        }
        return 0;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int n=grid.size(),m=grid[0].size(),k,count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    k = dfs(grid,i,j);
                    if(k != 0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
