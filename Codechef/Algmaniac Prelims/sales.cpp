#include<bits/stdc++.h>

using namespace std;

class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // adjacency lists 
public: 
    Graph(int V);  // Constructor 
    void addEdge(int v, int w); // to add an edge to graph 
    void DFS(int s);  // prints all vertices in DFS manner 
    // from a given source. 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
// prints all not yet visited vertices reachable from s 
void Graph::DFS(int s) 
{ 
    // Initially mark all verices as not visited 
    vector<bool> visited(V, false); 
  
    // Create a stack for DFS 
    stack<int> stack; 
  
    // Push the current source node. 
    stack.push(s); 
  
    while (!stack.empty()) 
    { 
        // Pop a vertex from stack and print it 
        s = stack.top(); 
        stack.pop(); 
  
        // Stack may contain same vertex twice. So 
        // we need to print the popped item only 
        // if it is not visited. 
        if (!visited[s]) 
        { 
            cout << s << " "; 
            visited[s] = true; 
        } 
  
        // Get all adjacent vertices of the popped vertex s 
        // If a adjacent has not been visited, then push it 
        // to the stack. 
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i) 
            if (!visited[*i]) 
                stack.push(*i); 
    } 
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    int u,v;

    Graph g(n);

    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        g.addEdge(--u,--v);
        g.addEdge(v,u);
    }

    for(int x = 0; x < q; ++x) {
        int m;
        cin >> m;
        if(n % m) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}