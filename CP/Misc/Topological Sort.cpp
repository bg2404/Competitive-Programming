#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Graph {
    int V;
    vector<vector<int> > adj;
    void topologicalSortUtil(int v, bool visited[], int order[], int& pos);
public:
    Graph(int V);
    void insertEdge(int v, int u);
    void topologicalSort();
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
    fill(adj.begin(), adj.end(), vector<int>());
}

void Graph::insertEdge(int v, int u) {
    adj[v].push_back(u);
}

void Graph::topologicalSortUtil(int v, bool visited[], int order[], int& pos) {
    visited[v] = true;
    for(auto u: adj[v]) {
        if(!visited[u]) {
            topologicalSortUtil(u, visited, order, pos);
        }
    }
    order[pos--] = v;
}

void Graph::topologicalSort() {
    bool visited[V];
    int order[V];
    int pos = V-1;
    for(int i = 0; i < V; ++i) visited[i] = false;
    for(int i = 0; i < V; ++i) {
        if(!visited[i]) {
            topologicalSortUtil(i, visited, order, pos);
        }
    }
    for(int i = 0; i < V; ++i) {
        cout << order[i] << ' ';
    }
    cout << endl;
}

int main() {
    int V, E, v, u;
    cin >> V >> E;
    Graph G(V);
    for(int i = 0; i < E; ++i) {
        cin >> v >> u;
        G.insertEdge(v, u);
    }
    G.topologicalSort();
    return 0;
}