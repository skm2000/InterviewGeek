#include<bits/stdc++.h>
using namespace std;

// ip-> ab (ip will always be in lowercase)
// op-> ab,aB,Ab,AB

void solve(string ip,string op){
    // base case
    if(ip.length() == 0){
        cout<<op<<"\n";
        return;
    }
    // hypothesis
    string op1 = op;
    string op2 = op;
    op1.push_back(ip[0]);
    op2.push_back(toupper(ip[0]));
    ip.erase(ip.begin()+0);
    // induction step
    solve(ip,op1);
    solve(ip,op2);
}

void perCaseChange(string ip){
    string op = " ";
    return solve(ip,op);
}

int main(){
    string s;
    cin>>s;
    perCaseChange(s);
}