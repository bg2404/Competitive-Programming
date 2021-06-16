#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<vector<int> > adj;

int bfs(vector<int> source) {
    int ans = 0;
    queue<pair<int, int> > q;
    vector<bool> visited(n, false);
    for (int s : source) {
        q.push({s, 0});
        visited[s] = true;
    }

    while (!q.empty()) {
        int u = q.front().first;
        int d = q.front().second;
        ans += d;
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push({v, d + 1});
                visited[v] = true;
            }
        }
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &q);
        adj.clear();
        adj.resize(n);
        int u, v;
        for (int i = 1; i < n; ++i) {
            scanf("%d %d", &u, &v);
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        while (q--) {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", bfs({a-1, b-1}));
        }
    }
}