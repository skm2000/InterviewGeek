#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>&board,int x,int y){
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]=='X' || board[x][y]=='#') return;
        board[x][y] = '#';
        dfs(board,x+1,y);
        dfs(board,x-1,y);
        dfs(board,x,y+1);
        dfs(board,x,y-1);
    }
public:
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == 'O' && (i == 0 || j == 0 || i == board.size()-1 || j == board[0].size()-1)){
                    dfs(board,i,j);
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};