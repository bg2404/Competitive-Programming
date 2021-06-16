#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
    void dfs(int s) {
        vector<bool> visited(n, false);
        visited[s] = true;
        stack<int> q;
        q.push(s);
        while(!q.empty()) {
            s = q.top();
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
    g.dfs(0);
    return 0;
}