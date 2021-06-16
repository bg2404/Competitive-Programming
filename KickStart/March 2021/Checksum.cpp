#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    int E;
    vector<vector<int> > adj;

   public:
    Graph(int v) {
        V = v;
        adj.resize(V, vector<int>(V, -1));
    }
    void insert(int u, int v, int w) {
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int prim() {
        int total_weight = 0;
        vector<bool> selected(V, false);
        vector<int> maxw(V, 0);
        maxw[0] = 0;
        for (int i = 0; i < V; ++i) {
            int v = -1;
            for (int j = 0; j < V; ++j) {
                if (!selected[j] && (v == -1 || maxw[j] > maxw[v])) {
                    v = j;
                }
            }
            if (maxw[v] == -1) {
                break;
            }

            selected[v] = true;
            total_weight += maxw[v];
            for (int j = 0; j < V; ++j) {
                if (adj[v][j] > maxw[j]) {
                    maxw[j] = adj[v][j];
                }
            }
        }
        return total_weight;
    }
};

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<vector<int> > a(n, vector<int>(n)), b(n, vector<int>(n));
        vector<int> r(n), c(n);
        int total_cost = 0;
        Graph g(n << 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> b[i][j];
                if (a[i][j] == -1) {
                    g.insert(i, n + j, b[i][j]);
                    total_cost += b[i][j];
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cin >> r[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        int ans = total_cost - g.prim();
        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}