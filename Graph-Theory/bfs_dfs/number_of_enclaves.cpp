#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int i,int j,vector<vector<int>>&A){
        if(i<0 || j<0 || i>A.size()-1 || j>A[0].size()-1 || A[i][j]==0) return;
            A[i][j]=0;
            dfs(i-1,j,A);
            dfs(i+1,j,A);
            dfs(i,j-1,A);
            dfs(i,j+1,A);
    }
public:
    int numEnclaves(vector<vector<int>>& A) {
        int n=A.size(),m=A[0].size(),ans=0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                if(i==0 || j==0 || i==A.size()-1 || j==A[0].size()-1){
                    dfs(i,j,A);
                }
            }
        }
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                if(A[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};