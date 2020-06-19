#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>courses(n,0);
        for(auto val :prerequisites)
        {
            courses[val[0]]++;
        }
        queue<int>currCourse;
        for(int i=0;i<n;i++)
        {
            if(courses[i]==0)
            {
                currCourse.push(i);
            }
        }
        while(currCourse.size())
        {
            int front = currCourse.front();
            currCourse.pop();
            n--;
            for(auto val : prerequisites)
            {
                if(val[1] == front)
                {
                    courses[val[0]]--;
                    if(courses[val[0]]==0)currCourse.push(val[0]);
                }
            }
        }
        return n==0;
    }
};