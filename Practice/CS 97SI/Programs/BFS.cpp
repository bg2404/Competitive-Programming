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
    void BFSUtil(int v, bool visited[]);

public:
    Graph(int N, int M);
    void addEdge(int u, int v, int k);
    void BFS(int v);
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

void Graph::BFSUtil(int v, bool visited[]) {
    queue<int> node_q;
    node_q.push(v);
    visited[v] = true;
    while(!node_q.empty()) {
        int v = node_q.front();
        node_q.pop();
        cout << v << ' ';
        for(int id = LE[v]; id != 0; id = E[id].nextID) {
            if(!visited[E[id].to]) {
                visited[E[id].to] = true;
                node_q.push(E[id].to);
            }
        }
    }
}

void Graph::BFS(int v) {
    bool visited[N+1];
    for(int i = 0; i <= N; ++i) {
        visited[i] = false;
    }
    
    BFSUtil(v, visited);
    for(int i = 1; i <= N; ++i) {
        if(!visited[i]) {
            BFSUtil(i, visited);
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
    G.BFS(1);
    return 0;
}