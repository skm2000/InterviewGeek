// Reverse a stack without using extra spaces
// base : the smallest condition for which the function is valid
// hypothesis: the condition which will be recursive or recursion body
// induction: the last step after all recursion has been done

#include<bits/stdc++.h>
using namespace std;

// insert recursive function to insert an element at top of stack
void insert(stack<int>&s,int temp) {
    // base condition
    if(s.size() == 0){
        s.push(temp);
        return;
    }
    // hypothesis
    int val = s.top();
    s.pop();
    insert(s,temp);
    // induction
    s.push(val);
}

void reverse(stack<int>&s) {
    // base condition
    if(s.size() == 1) {
        return;
    }
    // hypothesis
    int temp = s.top();
    s.pop();
    reverse(s);
    // induction
    insert(s,temp);
}

int main(){
    int n,p;
    cin>>n;
    stack<int>s;
    for(int i=0;i<n;i++){
        cin>>p;
        s.push(p);
    }
    if(s.empty()){
        cout<<"Not Possible";
        exit;
    }
    reverse(s);
    cout<<"After Reversing : ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}