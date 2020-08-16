#include<bits/stdc++.h>
using namespace std;

int floorInASortedArray(vector<int>& nums,int k){
    int n = nums.size(),l=0,h=nums.size(),res=-1;
    while(l <= h){
        int mid = l + (h-l)/2;
        if(nums[mid] == k) return mid;
        else if(k > nums[mid]){
            res = mid;
            l = mid + 1;
        }
        else if(k < nums[mid]){
            h = mid - 1;
        }
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        cout<<floorInASortedArray(v,k)<<"\n";
    }
}