#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Graph {
    vector<vector<pair<int, int> > > adj;
    vector<int> dist;
    int n;
    int m;
public:
    Graph(int n, int m) {
        this->n = n;
        this->m = m;
        adj.resize(n);
        dist.assign(n, 0);
    }
    void add_edge(int u, int v, int d) {
        adj[u].push_back(make_pair(v, d));
        adj[v].push_back(make_pair(u, d));
    }

    vector<int> dijstra(int s) {
        auto cmp = [this](int u, int v) { return this->dist[u] < this->dist[v]; };
        set<int, decltype(cmp)> pq(cmp);
        dist.assign(n, INT_MAX);
        vector<bool> visited(n, false);
        dist[s] = 0;
        pq.emplace(s);
        visited[s] = true;
        while(!pq.empty()) {
            s = *pq.begin();
            pq.erase(pq.begin());
            for (auto [i, d]: adj[s]) {
                if(!visited[i] && dist[s] + d < dist[i]) {
                    pq.erase(i);
                    dist[i] = dist[s] + d;
                    pq.insert(i);
                }
            }
        }
        return dist;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n, m);
    for (int i; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        g.add_edge(u, v, d);
    }
    vector<int> d = g.dijstra(1);
    for(int i: d) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}