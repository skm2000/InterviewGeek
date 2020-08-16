#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1,prev,next;
        while(l <= h){
            if(nums[l] <= nums[h]){
                return l;
            }
            int mid = l+(h-l)/2;
            next = (mid + 1)%n;
            prev = (mid - 1 + n)%n;
            if(nums[mid] <= nums[prev]){
                return mid;
            }
            else if(nums[l] <= nums[mid]){
                l = mid+1;
            }
            else if(nums[mid] <= nums[h]){
                h = mid-1;
            }
        }
        return -1;
    }
    int binary_search(vector<int>&nums,int target,int start,int end){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(target==nums[mid]) return mid;
            else if(target<nums[mid])end=mid-1;
            else start=mid+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),minInd,k1,k2;
        if(n==0) return -1;
        minInd=findMin(nums);
        k1=binary_search(nums,target,0,minInd-1);
        k2=binary_search(nums,target,minInd,n-1);
        if(k1==-1 && k2==-1) return -1;
        return k1>k2?k1:k2;
    }
};