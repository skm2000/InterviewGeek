#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int source;
    int dest;
};

int find(int i,int* parent) {
    if(parent[i] == -1) return i;
    return find(parent[i],parent); //recurse to find the parent
}

void Union(int* parent,int x,int y) {
    int xSet = find(x,parent);
    int ySet = find(y,parent);
    if(xSet != ySet) { // check that the starting node and ending not are not same
       parent[xSet] = ySet;
    }
}

int isCycle(Edge* input,int n,int e) {
    int *parent = new int[n];
    for(int i=0;i<n;i++){
        parent[i] = -1;
    }
    for(int i=0;i<e;i++){
        int x = find(input[i].source,parent);
        int y = find(input[i].dest,parent);
        if(x == y){
            return 1;
        }
        Union(parent,x,y);
    }
    return 0;
}

int main() {
    int n,e;
    cin>>n>>e;
    Edge *input = new Edge[e];
    for(int i=0;i<e;i++) {
        int s,d;
        cin>>s>>d;
        input[i].source = s;
        input[i].dest = d;
    }
    if(isCycle(input,n,e) == 1){
        cout<<"The Cycle exists "<<"\n";
    }
    else{
        cout<<"The Cycle does not exists "<<"\n";
    }
}