#include<bits/stdc++.h>
using namespace std;

void helper(string s,int l,int r){
    if(l == r){
        cout<<s<<"\n";
    }
    for(int i=l;i<r;i++){
        swap(s[l],s[r]);
        helper(s,l+1,r);
        // backtrack
        swap(s[l],s[r]);
    }
}

void printPer(string s){
    int l=0,r=s.length()-1;
    helper(s,l,r);
}
