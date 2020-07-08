#include<bits/stdc++.h>
using namespace std;
// ip -> abc
// "a_b_c","a_bc","ab_c","abc" ["-"->stands for spaces]

void solve(string ip,string op){
    // base condition
    if(ip.length() == 0){
        cout<<op<<"\n";
        return;
    }
    // hypothesis
    string op1 = op;
    string op2 = op;
    op1.push_back(' ');
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    // induction step
    solve(ip,op1);
    solve(ip,op2);
}

void permutionWithSpaces(string ip){
    string op = "";
    op.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    return solve(ip,op);
}

int main(){
    string s;
    cin>>s;
    permutionWithSpaces(s);
}