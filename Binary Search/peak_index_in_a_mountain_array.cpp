#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int start=0,end=A.size()-1;
        while(start<end){
            int mid=start+(end-start)/2;
            if(A[mid-1]>A[mid]) end=mid;
            else if(A[mid]<A[mid+1]) start=mid+1;
            else return mid;
        }
        return -1;
    }
};