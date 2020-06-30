#include<bits/stdc++.h>
using namespace std;

string freqSort(string s) {
    unordered_map<int,char>mp;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }
    priority_queue<pair<int,char>>max_heap;
    for(auto it:mp){
        max_heap.push({it.second,it.first});
    }
    string ans="";
    while(max_heap.size() != 0) {
        int freq = max_heap.top().first;
        char ch = max_heap.top().second;
        for(int i=0;i<freq;i++){
            ans.push_back(ch);
        }
        max_heap.pop();
    }
    return ans;
}

int main() {
    string s;
    cin>>s;
    cout<<freqSort(s)<<"\n";
}