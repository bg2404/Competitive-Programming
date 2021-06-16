#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > adj;
vector<int> parent;
vector<int> height;

void dfs(int u = 0, int p = -1) {
    for (int v : adj[u]) {
        if (v != p) {
            height[v] = height[u] + 1;
            dfs(v, u);
        }
    }
}

int dfs2(int u = 0) {
    for (int v : adj[u]) {
        if (v != parent[u]) {
            parent[v] = u;
            height[u] = max(dfs2(v), height[u]);
        }
    }
    height[u] += 1;
    sort(adj[u].begin(), adj[u].end(), [&height, &parent, u](int a, int b) {
        if (b == parent[u])
            return true;
        else if (a == parent[u])
            return false;
        else
            return height[a] < height[b];
    });
    if (adj[u].back() == parent[u]) {
        adj[u].pop_back();
    }
    return height[u];
}

struct comparator {
    bool operator()(const int a, const int b) const {
        return height[a] < height[b];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, u, v;
        cin >> n >> k;
        adj.resize(n);
        parent.assign(n, -1);
        height.assign(n, 0);
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        if (k == 1) {
            cout << 1 << endl;
        } else {
            dfs();
            int root = 0;
            for (int i = 1; i < n; ++i) {
                if (height[root] < height[i]) {
                    root = i;
                }
            }
            height.assign(n, 0);
            dfs2(root);
            priority_queue<int, vector<int>, comparator> pq;
            int leaves = 1;
            vector<int> nodes(1, root);
            for (int v : adj[root]) {
                pq.push(v);
            }
            int next, prev;
            while (nodes.size() < k) {
                next = pq.top();
                pq.pop();
                while (adj[next].size() != 0) {
                    nodes.push_back(next);
                    prev = next;
                    next = adj[prev].back();
                    adj[prev].pop_back();
                    for (int v : adj[prev]) {
                        pq.push(v);
                    }
                }
                nodes.push_back(next);
                ++leaves;
            }
            cout << leaves << endl;
        }
        adj.clear();
        parent.clear();
        height.clear();
    }
    return 0;
}