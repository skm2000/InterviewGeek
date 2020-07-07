#include<bits/stdc++.h>
using namespace std;
// print unique subsets in lexicographical order
set<string>sub;
void helper(string ip,string op){
    // base condition
    if(ip.length() == 0){
        sub.insert(op);
        return;
    }
    // hypothesis
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    // induction step
    helper(ip,op1);
    helper(ip,op2);
}

void printUniqueSubsets(string ip){
    string op = " ";
    helper(ip,op);
    for(auto it:sub){
        cout<<it<<" ";
    }
}

int main(){
    string s;
    cin>>s;
    printUniqueSubsets(s);
}