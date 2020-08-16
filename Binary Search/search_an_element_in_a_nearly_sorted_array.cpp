#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums,int x){
    int n = nums.size();
    int l=0,h=n-1;
    while(l <= h){
        int mid = l + (h-l)/2;
        if(nums[mid] == x) return mid;
        if((mid-1)>=l && nums[mid-1] == x) return mid-1;
        if((mid+1)<=h && nums[mid+1] == x) return mid+1;
        else if(x < nums[mid]){
            h = mid-2;
        }
        else{
            l = mid+2;
        }
    }
    return -1;
}

int main(){
    int n,k;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>k;
    cout<<search(v,k);
}