#include<bits/stdc++.h>
using namespace std;

// Problem: https://leetcode.com/problems/rotting-oranges/

//bfs approach
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    c++;
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            if(c == 0) return ans;
            while(size--){
                auto x=q.front();
                q.pop();
                int i=x.first,j=x.second;
                if(i>0){
                    if(grid[i-1][j] == 1){
                        c--;
                        grid[i-1][j]=2;
                        q.push({i-1,j});
                    }
                }
                if(j>0){
                    if(grid[i][j-1] == 1){
                        c--;
                        grid[i][j-1]=2;
                        q.push({i,j-1});
                    }
                }
                if(i<grid.size()-1){
                    if(grid[i+1][j]==1){
                        c--;
                        grid[i+1][j]=2;
                        q.push({i+1,j});
                    }
                }
                if(j<grid[0].size()-1){
                    if(grid[i][j+1]==1){
                        c--;
                        grid[i][j+1]=2;
                        q.push({i,j+1});
                    }
                }
            }
            ans++;
        }
        return c==0?ans:-1;
    }
};