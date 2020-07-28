#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<vector<int>>&board,int n,int row,int col) {
    // same column
    for(int i=row-1;i>=0;i--){
        if(board[i][col] == 1){
            return false;
        }
    }
    // upper left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j] == 1){
            return false;
        }
    }
    // upper right diagonal
    for(int i=row-1,j=col+1;i>=0 && j>=0;i--,j++){
        if(board[i][j] == 1){
            return false;
        }
    }
    return true;
}

void nQueen(vector<vector<int>>&board,int n,int row){
    if(row == n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"*******************"<<"\n";
        return;
    }
    for(int j=0;j<n;j++){
        if(isPossible(board,n,row,j)){
            board[row][j]=1;
            nQueen(board,n,row+1);
            board[row][j]=0;
        }
    }
}

void placeQueen(int n){
    vector<vector<int>>board(n);
    for(int i=0;i<n;i++){
        board[i].resize(n);
        for(int j=0;j<n;j++){
            board[i][j] = 0;
        }
    }
    nQueen(board,n,0);
}

int main(){
    int n;
    cin>>n;
    placeQueen(n);
    return 0;
}