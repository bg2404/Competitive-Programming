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
    void computeDegree(int v, int degree[]);

public:
    Graph(int N, int M);
    void addEdge(int u, int v, int k);
    void TSort();
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

void Graph::computeDegree(int v, int degree[]) {
    bool visited[N+1];
    for(int i = 0; i <= N; ++i) {
        visited[i] = false;
        degree[i] = 0;
    }

    queue<int> node_q;
    node_q.push(v);
    while(!node_q.empty()) {
        int v = node_q.front();
        node_q.pop();
        for(int id = LE[v]; id != 0; id = E[id].nextID) {
            ++degree[E[id].to];
            if(!visited[E[id].to]) {
                visited[E[id].to] = true;
                node_q.push(E[id].to);
            }
        }
    }
}

void Graph::TSort() {
    int degree[N+1];
    computeDegree(1, degree);
    queue<int> sort_q;
    for(int i = 1; i <= N; ++i) {
        if(!degree[i]) {
            sort_q.push(i);
        }
    }
    while(!sort_q.empty()) {
        int v = sort_q.front();
        sort_q.pop();
        cout << v << ' ';
        for(int id = LE[v]; id != 0; id = E[id].nextID) {
            --degree[E[id].to];
            if(!degree[E[id].to]) {
                sort_q.push(E[id].to);
            }
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
    G.TSort();
    return 0;
}