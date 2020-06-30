#include<bits/stdc++.h>
using namespace std;

// problem: https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
//      priority queue of vectors
        priority_queue<vector<int>, vector<vector<int>>, compare> pq(points.begin(), points.end());
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
private:
    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
        }
    };
};