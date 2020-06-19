#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/friend-circles/

// just a demostration (1,2) & (2,3) which means if one element is common then take union ie (1,2,3)

class Solution {
    vector<int>parent;
private:
    int find(int v){
        if(v == parent[v]) return v;
        return find(parent[v]);
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty()) return 0;
        int n = M.size();
        parent.resize(n,0);
        int groups = n;
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){ //such that i!=j
                if(M[i][j]){
                    int x = find(i);
                    int y = find(j);
                    if(x != y){
                        parent[y] = x;
                        groups--;
                    }
                }
            }
        }
        return groups;
    }
};