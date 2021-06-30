#include<bits/stdc++.h>

using namespace std;

int const WHITE = 0;
int const GRAY = 1;
int const BLACK = 2;
int const INF = INT_MAX;

struct NODE {
    int v;
    int c;
    int d;
    int pred;
    NODE() {
        v = -1;
        c = WHITE;
        d = INF;
        pred = -1;
    }
};

class Graph {
    vector<int> *adj;
    int V;
public:
    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    void addEdge(int u, int v) {
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    void BFS(int v) {
        queue<NODE> q;
        vector<NODE> node(V);
        node[v].v = v;
        node[v].c = GRAY;
        node[v].d = 0;
        q.push(node[v]);
        while(!q.empty()) {
            NODE n = q.front();
            q.pop();
            node[n.v].c = BLACK;
            for(int i = 0; i < adj[n.v].size(); ++i) {.
                if(node[adj[n.v][i]].c == WHITE) {
                    node[adj[n.v][i]].v = adj[n.v][i];
                    node[adj[n.v][i]].d = n.d + 1;
                    node[adj[n.v][i]].c = GRAY;
                    node[adj[n.v][i]].pred = n.v;
                    NODE temp = node[adj[n.v][i]];
                    q.push(temp);
                }
            }
        }

        for(int i = 0; i < V; ++i) {
            cout << node[i].d << '\n';
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    Graph G(V);
    for(int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        G.addEdge(u-1, v-1);
    }
    G.BFS(0);
    return 0;
}

/*
10 9
1 2
1 3
1 4
2 5
2 6
3 7
3 8
4 9
4 10
*/