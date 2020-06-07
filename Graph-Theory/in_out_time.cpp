#include<bits/stdc++.h>
using namespace std;
int inTime[100001],outTime[100001],visited[100001];
vector<int>ar[100001];
int timer=1;
int dfs(int node){
    visited[node]=1;
    inTime[node]=timer++;
    for(int child:ar[node]){
        if(visited[child]==0){
            dfs(node);
        }
    }
    outTime[node]=timer++;
}

int main(){
    
}