#include<bits/stdc++.h>
using namespace std;

// ip-> "ABC"
// op-> "ABC ACB BAC BCA CBA CAB"
// draw recursion tree,code will be easy to understand
// Time Complexity: O(n*n!) Note that there are n! permutations and it requires O(n) time to print a a permutation.

void solve(string s,int l,int r){
    // base condition
    if(l == r){
        cout<<s<<"\n";
        return;
    }
    // Hypothesis
    for(int i=l;i<=r;i++){
        swap(s[l],s[i]);
        solve(s,l+1,r);
        // to regain back to its original position or backtrack
        swap(s[l],s[i]);
    }
}

void printPer(string s){
    int l=0,r=s.length()-1;
    return solve(s,l,r);
}

// variation: print all permutation such that "AB" is not together in any of substring
void helper(string s,int l,int r){
    // base condition
    if(l == r){
        if(s.find("AB") == string::npos){
            cout<<s<<"\n";
            return;
        }
    }
    // Hypothesis
    for(int i=l;i<=r;i++){
        swap(s[l],s[i]);
        helper(s,l+1,r);
        // to regain back to its original position or backtrack
        swap(s[l],s[i]);
    }
}

void printPerEx(string s){
    int l=0,r=s.length()-1;
    return helper(s,l,r);
}

// variation: print all permutation such that "AB" is not together in any of substring using backtracking(Worst Case: O(n)*n!) when "AB" not present
// but when "AB" is present it will definitely be more better

bool isSafe(string s,int i,int l,int r){
    if(l!=0 && s[l-1]=='A' && s[i]=='B') return false;
    if (r == l+1 && s[i] == 'A' && s[l] == 'B') return false;
    return true; 
}

void backHelper(string s,int l,int r){
    if(l == r){
        cout<<s<<"\n";
        return;
    }
    for(int i=l;i<=r;i++){
        if(isSafe(s,i,l,r)){
            swap(s[l],s[i]);
            backHelper(s,l+1,r);
            swap(s[l],s[i]);
        }
    }
}

void printperBac(string s){
    int l=0,r=s.length()-1;
    return backHelper(s,l,r);
}


int main(){
    string s;
    cin>>s;
    cout<<"****************ALL PERMUTATION*********"<<"\n";
    printPer(s);
    cout<<"****************Without AB**************"<<"\n";
    printPerEx(s);
    cout<<"****************BACKTRACKING APPROACH**************"<<"\n";
    printperBac(s);
}