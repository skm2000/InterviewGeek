#include<bits/stdc++.h>
using namespace std;

// iterative dfs(nice question)
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int>dfs;
        dfs.push(0);
        unordered_set<int>seen;
        seen.insert(0);
        while(!dfs.empty()){
            int x = dfs.top();
            dfs.pop();
            for(int j : rooms[x]){
                if(seen.find(j) == seen.end()){
                    dfs.push(j);
                    seen.insert(j);
                    if(rooms.size() == seen.size()) return true;
                }
            }
        }
        return (rooms.size() == seen.size());
    }
};