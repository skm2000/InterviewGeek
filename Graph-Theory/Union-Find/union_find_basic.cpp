#include<bits/stdc++.h>
using namespace std;
// Naive implementation of Union-find

//the time complexity in linear in worst case

int find(int i,int parent[]) {
    if(parent[i] == -1) return i;
    return find(parent[i],parent);
}


// [x]--------[y] x&y are nodes
//parent[srcParent] = destParent creates a set as to say [x]<---------[y]


void Union(int parent[],int x,int y) {
    int srcParent = find(x,parent);
    int destParent = find(y,parent);
    parent[srcParent] = destParent
}