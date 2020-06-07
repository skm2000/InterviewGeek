#include<bits/stdc++.h>
using namespace std;

// Problem : https://www.lintcode.com/problem/walls-and-gates/description

//bfs approach
class Solution {
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        int INF=2147483647;
        int n=rooms.size(),m=rooms[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
              if(rooms[i][j]==0){
                 q.push({i,j});
              }
           }
        }
        int count=1;
        while(!q.empty()){
           int size=q.size();
           while(size--){
              auto x=q.front();
              q.pop();
              int i=x.first,j=x.second;
              if(i>0){
                  if(rooms[i-1][j]==INF){
                     rooms[i-1][j]=count;
                     q.push({i-1,j});
                  } 
              }
              if(j>0){
                 if(rooms[i][j-1]==INF){
                     rooms[i][j-1]=count;
                     q.push({i,j-1});
                  }
              }
              if(i<n-1){
                 if(rooms[i+1][j]==INF){
                     rooms[i+1][j]=count;
                     q.push({i+1,j});
                  }
              }
              if(j<m-1){
                 if(rooms[i][j+1]==INF){
                     rooms[i][j+1]=count;
                     q.push({i,j+1});
                  }
              }
           }
           count++;
        }
    }
};



//dfs approach
class Solution {
private:
     void dfs(int i,int j,int count,vector<vector<int>>&rooms){
        if(i<0 || j<0 || i>=rooms.size() || j>=rooms[0].size() || rooms[i][j]<count) return;
        rooms[i][j]=count;
        dfs(i+1,j,count+1,rooms);
        dfs(i,j+1,count+1,rooms);
        dfs(i-1,j,count+1,rooms);
        dfs(i,j-1,count+1,rooms);
     }
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        int n=rooms.size(),m=rooms[0].size();
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
              if(rooms[i][j]==0){
                 dfs(i,j,0,rooms);
              }
           }
        }
    }
};