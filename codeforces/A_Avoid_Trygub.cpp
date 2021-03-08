#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isSubsequence(string s1,string s2){
    int j=0;
    for(int i=0;i<s2.length()&&j<s1.length();i++){
        if(s1[j] == s2[i]) j++;
        else continue;
    }
    // cout<<j<<" ";
    return j==s1.length();
}

void solve(){
    int n;
    cin>>n;
    string s2;
    string s1 = "trygub";
    cin>>s2;
    if(isSubsequence(s1,s2) == false){
        cout<<s2<<"\n";
    }else{
        sort(s2.begin(),s2.end());
        cout<<s2<<"\n";
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}        