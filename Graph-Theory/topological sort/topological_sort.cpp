// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/

void topological(vector<int>adj[], int u, bool visited[], stack<int>&st) {
    if(visited[u] == false) {
        visited[u] = true;
        for(auto e : adj[u]) {
            if(!visited[e]) {
                topological(adj, e ,visited, st);
            }
        }
    }
    st.push(u);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    bool *visited = new bool[V];
    stack<int>st;
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }
    for(int i = 0; i < V; i++) {
        if(visited[i] == false) {
            topological(adj, i , visited, st);
        }
    }
    vector<int>ans;
    while(st.size()) {
        int a = st.top();
        ans.push_back(a);
        st.pop();
    }
    return ans;
}
