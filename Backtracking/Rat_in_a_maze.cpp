#include<bits/stdc++.h>
using namespace std;

void printSol(vector<vector<int>>&solution,int n){
    cout<<"**********************"<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solution[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"**********************"<<"\n";
}

void mazeHelper(vector<vector<int>>mat,vector<vector<int>>&solution,int n,int x,int y){
    // printing solution
    if(x==n-1 && y==n-1){
        solution[x][y] = 1;
        printSol(solution,n);
        return;
    }
    // outside the maze condition
    if(x<0 || x>=n || y<0 || y>=n || mat[x][y]==0 || solution[x][y]==1){
        return;
    }
    // rat can move in following order up,doen,left,right
    solution[x][y] = 1;
    mazeHelper(mat,solution,n,x-1,y);
    mazeHelper(mat,solution,n,x+1,y);
    mazeHelper(mat,solution,n,x,y-1);
    mazeHelper(mat,solution,n,x,y+1);
    solution[x][y] = 0;
}


void ratInMaze(vector<vector<int>>mat,int n){
    vector<vector<int>>solution(n,vector<int>(n,0));
    mazeHelper(mat,solution,n,0,0);
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>mat(n);
    for(int i=0;i<n;i++){
        mat[i].resize(n);
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    ratInMaze(mat,n);
}