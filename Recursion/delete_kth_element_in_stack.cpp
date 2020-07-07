// delete kth element from the top using recursion or O(1) time
// base : the smallest condition for which the function is valid
// hypothesis: the condition which will be recursive or recursion body
// induction: the last step after all recursion has been done

#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>&s,int k) {
    // boundary condition
    if(s.empty()) return;
    // base condition
    if(k==1) {
        s.pop();
        return;
    }
    // hypothesis step
    int temp = s.top();
    s.pop();
    solve(s,k-1);
    // induction step
    s.push(temp);
}

int main(){
    int n,k,p;
    cin>>n>>k;
    stack<int>s;
    for(int i=0;i<n;i++){
        cin>>p;
        s.push(p);
    }
    solve(s,k);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}