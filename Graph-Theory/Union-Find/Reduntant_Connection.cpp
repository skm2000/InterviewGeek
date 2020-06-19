#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/redundant-connection/

class Solution {
private:
    vector<int>parent;
    int find(int v){
        if(v == parent[v]) return v;
        return find(parent[v]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
        vector<int>res(2,0);
        for(int i=0;i<n;i++){
            int x = find(edges[i][0]);
            int y = find(edges[i][1]);
            if(x != y){
                parent[x] = y;
            }
            else{
                res[0] = edges[i][0];
                res[1] = edges[i][1];
            }
        }
        return res;
    }
};