#include<bits/stdc++.h>
using namespace std;

// submitted in leetcode
// Very good question of Djikstra algo implmentation,understand the question code is easy to implement 
// O(ElogV) solution

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& sp, int start, int end) {
        unordered_map<int,vector<pair<int,double>>>mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back({edges[i][1],sp[i]});
            mp[edges[i][1]].push_back({edges[i][0],sp[i]});
        }
        vector<double>visited(n,0),dis(n,0);
//      maximum when start==end distance is 1
        dis[start] = 1;
        priority_queue<pair<double,int>>q;
        q.push({1,start});
        while(!q.empty()){
            auto x = q.top();
            q.pop();
            if(!visited[x.second]){
                visited[x.second] = 1;
                for(auto c: mp[x.second]){
                    if(!visited[c.first]){
                        if(dis[c.first]<c.second*x.first){
                            dis[c.first] = c.second*x.first;
                            q.push({dis[c.first],c.first});
                        }
                    }
                }
            }
        }
        return dis[end];
    }
};