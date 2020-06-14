#include<bits/stdc++.h>
using namespace std;

//O(ElogV) time complexity implementation

vector<pair<int,int>>*G;

void djikstra(int source,int n) {
    vector<int>distance(n,INT_MAX);//assiging distance vector all values to infinity
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q; //min heap of pairs for distance value and source index
    distance[source] = 0;
    Q.push({0,source});
    while(!Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        for(auto &c : G[u]) {
            int v = c.first;
            int w = c.second;
            if(distance[v] > distance[u]+w){
                distance[v] = distance[u]+w;
                Q.push({distance[v],v});
            }
        }
    }
    //printing the distance
    cout<<"Source"<<"\t\t"<<"Minimum Distance"<<"\n";
    for(int i=0;i<distance.size();i++) {
        cout<<source<<" "<<distance[i]<<"\n";
    }
}

int main(){
    int n,e;//n:no of vertex;e: no of edges
    cin>>n>>e;
    G = new vector<pair<int,int>>[n+1];  // //weighted graph adjacency list, this is equivalent to vector<pair<int,int>>G[n+1];.Since passing into function will be difficult hence done like this
    for(int i=0;i<e;i++) {
        int u,v,w;
        cin>>u>>v>>w; //iniitial vertex,final vertex,weight of that edge
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    int source;
    cin>>source;
    djikstra(source,n);
}
