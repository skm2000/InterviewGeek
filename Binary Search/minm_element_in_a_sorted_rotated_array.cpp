#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l=0,h=n-1,prev,next,mid=-1;
        while(l <= h){
            if(nums[l] <= nums[h]){
                return nums[l];
            }
            int mid = l + (h-l)/2;
            prev = (mid + n - 1)%n;
            next = (mid + 1)%n; //not used
            if(nums[mid] <= nums[prev]){
                return nums[mid];
            }
            else if(nums[l] <= nums[mid]){
                l = mid + 1;
            }
            else if(nums[mid] <= nums[h]){
                h = mid-1;
            }
        }
        return -1;
    }
};