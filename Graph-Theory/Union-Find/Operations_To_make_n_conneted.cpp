#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
private:
    vector<int>parent;
    int find(int v) {
        if(v == parent[v]) return v;
        return find(parent[v]);
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size();
        if(size < n-1) return -1;
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        int requireEdges=0;
        for(int i=0;i<size;i++){
            int x = find(connections[i][0]);
            int y = find(connections[i][1]);
            if(x != y){
                parent[x] = y;
            }
        }
        for(int i=0;i<n;i++){
            if(parent[i] == i) requireEdges++;
        }
        return requireEdges - 1;
    }
};