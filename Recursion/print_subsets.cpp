#include<bits/stdc++.h>
using namespace std;
// variations : print subsets, print powerset,print all subsequences
void solve(string ip,string op){
    // base condition
    if(ip.length() == 0){
        cout<<op<<" ";
        return;
    }
    // Hypothesis
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    // Inducton step
    solve(ip,op1);
    solve(ip,op2);
}

void printSubsets(string ip){
    string op=" ";
    return solve(ip,op);
}

int main(){
    string s;
    cin>>s;
    printSubsets(s);
}