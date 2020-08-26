#include<bits/stdc++.h>
using namespace std;


// similar to detect cycle in a directed graph.Used graph coloring approach(3-color approach).
// O(V+E) time
// 0->not visited
// 2->processing
// 3->processed
class Solution {
private:
    bool isCyclic(vector<vector<int>>&adj,vector<int>&visited,int current){
        if(visited[current]==2)
            return true;
        visited[current]=2;
        for(int i=0;i<adj[current].size();i++){
            if(visited[adj[current][i]]!=1){
                if(isCyclic(adj,visited,adj[current][i]))
                    return true;
            }
        }
        visited[current]=1;
        return false;
    }
public:
    bool canFinish(int nums, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(nums);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>visited(nums,0);
        for(int i=0;i<nums;i++){
            if(visited[i]==0){
                if(isCyclic(adj,visited,i)){
                    return false;
                }
            }
        }
        return true;
    }
};