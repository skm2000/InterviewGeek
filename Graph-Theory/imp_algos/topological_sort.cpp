#include<bits/stdc++.h>
using namespace std;

// 1. topological sort,this solution will fetch wrong answer is this particular question.
// since we have to check for cycle to.
class Solution {
private:
    vector<vector<int>>graph;
    vector<bool>visited;
    stack<int>s;
    void dfs(int node){
        visited[node] = true;
        for(auto child : graph[node]){
            if(!visited[child]){
                dfs(child);
            }
        }
        s.push(node);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        graph.resize(n);
        visited.resize(n,false);
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            graph[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};



// submitted code 
// source : https://leetcode.com/problems/course-schedule-ii/discuss/742323/C%2B%2B-Beginner-Topological-Sort-and-Cycle-detection-using-DFS.

class Solution {
//     topological sort solution
public:
    stack<int> S;
    vector<int> V;
    vector<int> P;
    bool cycle;
    map<int, vector<int> > G;
    
    void DFS(int n)
    {        
        for(int i=0;i<n;++i)
        {
            if(!V[i]) DFS_recur(i);
        }
    }
    
    void DFS_recur(int curr)
    {
        if(cycle) return;
        
        V[curr] = true;
        P[curr] = true;
        
        for(int i : G[curr])
        {   
            if(P[i] == true) cycle = true;
            if(!V[i]) DFS_recur(i);
        }
        
        S.push(curr);
        P[curr] = false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) 
    {
        vector<int> Ans;
        V.assign(n, false);
        P.assign(n, false);
        cycle = false;
        for(auto i : prerequisites)
        {
            G[i[1]].push_back(i[0]);
        }

        DFS(n);
        
        while(!S.empty())
        {
            Ans.push_back(S.top());
            S.pop();
        }
        
        if(cycle) return {};
        return Ans;
    }
};
