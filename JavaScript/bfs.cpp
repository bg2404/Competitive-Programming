#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    vector<vector<int> > adj;
    int n;
    int m;
public:
    Graph(int n, int m) {
        this->n = n;
        this->m = m;
        adj.resize(n);
    }
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void bfs(int s) {
        vector<bool> visited(n, false);
        visited[s] = true;
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            s = q.front();
            cout << s << ' ';
            q.pop();
            for(int i: adj[s]) {
                if(!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n, m);
    for (int i; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v);
    }
    g.bfs(0);
    return 0;
}