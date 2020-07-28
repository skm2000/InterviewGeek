#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>&board,int n,int row,int col,int num){
    // check safety for row and columm
    for(int i=0;i<n;i++){
        if(board[row][i] == num || board[i][col] == num){
            return false;
        }
    }
    // check safety in grid
    int s = sqrt(n);
    int l = row - row%s;
    int r = col - col%s;
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            if(board[i+l][j+r] == num){
                return false;
            }
        }
    }
    return true;
}

// print grid
void printGrid(vector<vector<int>>&board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool sudukoSolve(vector<vector<int>>&board,int n){
    int i,j;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // empty cell
            if(board[i][j] == 0){
                break;
            }
        }
    }
    if(i == n || j == n){
        return true;
    }
    // fill up empty cell
    for(int k=1;k<=n;k++){
        if(isSafe(board,n,i,j,k)){
            // put the value
            board[i][j] = k;
            // recursively call
            if(sudukoSolve(board,n)) return true;
            // if conditions not met make that 0 ie backtrack it
            board[i][j] = 0;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>sud(n);
    for(int i=0;i<n;i++){
        sud[i].resize(n);
        for(int j=0;j<n;j++){
            cin>>sud[i][j];
        }
    }
    if(sudukoSolve(sud,n)==true){
        cout<<"***************\n";
        printGrid(sud,n);
    }
    else{
        cout<<"Solution does not exists";
    }
}