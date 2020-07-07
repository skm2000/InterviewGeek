// sort an array using recursion
// base : the smallest condition for which the function is valid
// hypothesis: the condition which will be recursive or recursion body
// induction: the last step after all recursion has been done

#include<bits/stdc++.h>
using namespace std;

// variation : sort an array in O(1) space ie recursion

void insert(vector<int>&v,int temp){
    // base condition
    if(v.size() == 0 || v[v.size()-1] <= temp) {
        v.push_back(temp);
        return;
    }
    // hypothesis
    int val = v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    // induction
    v.push_back(val);
}

void sort(vector<int>&v){
    // base condition
    if(v.size() == 1){
        return;
    }
    // hypothesis
    int temp = v[v.size()-1];
    v.pop_back();
    sort(v);
    // induction
    insert(v,temp);
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v);
    for(int i=0;i<n;i++)cout<<v[i]<<" ";
}