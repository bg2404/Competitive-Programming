#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int to;
    int nextID;
};

class Graph {
    int N;
    int M;
    struct Edge *E;
    int *LE;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int N, int M);
    void addEdge(int u, int v, int k);
    void DFS(int v);
};

Graph::Graph(int N, int M) {
    this->N = N;
    this->M = M;
    E = new struct Edge[M+1];
    LE = new int[N+1];
    for(int i = 0; i <= N; ++i) {
        LE[i] = 0;
    }
}

void Graph::addEdge(int u, int v, int k) {
    E[k].to = v;
    E[k].nextID = LE[u];
    LE[u] = k;
}

void Graph::DFSUtil(int v, bool visited[]) {
    stack<int> node_s;
    node_s.push(v);
    visited[v] = true;
    while(!node_s.empty()) {
        int v = node_s.top();
        node_s.pop();
        cout << v << ' ';
        for(int id = LE[v]; id != 0; id = E[id].nextID) {
            if(!visited[E[id].to]) {
                visited[E[id].to] = true;
                node_s.push(E[id].to);
            }
        }
    }
}

void Graph::DFS(int v) {
    bool visited[N+1];
    for(int i = 0; i <= N; ++i) {
        visited[i] = false;
    }
    DFSUtil(v, visited);
    for(int i = 1; i <= N; ++i) {
        if(!visited[i]) {
            DFSUtil(i, visited);
        }
    }
    
    cout << '\n';
}

int main() {
    int N, M;
    cin >> N >> M;
    Graph G(N,M);
    int u, v;
    for(int i = 0; i < M; ++i) {
        cin >> u >> v;
        G.addEdge(u,v, i+1);
    }
    G.DFS(1);
    return 0;
}