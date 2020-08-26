#include<bits/stdc++.h>
using namespace std;

// problem : https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int r1=0,r2=n-1,c1=0,c2=n-1,i=1;
        while(r1<=r2 && c1<=c2){
            for(int c=c1;c<=c2;c++) matrix[r1][c] = i++;
            for(int r=r1+1;r<=r2;r++) matrix[r][c2] = i++;
            if(r1<r2 && c1<c2){
                for(int c=c2-1;c>c1;c--) matrix[r2][c] = i++;
                for(int r=r2;r>r1;r--) matrix[r][c1] = i++;
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return matrix;
    }
};