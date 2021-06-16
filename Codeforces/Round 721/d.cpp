#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    os << "[ ";
    for (T e : v) {
        os << e << ' ';
    }
    os << ']';
    return os;
}

void dfs(vector<vector<long long> > &adj, vector<long long> &parent, vector<long long> &subtree, long long u = 0) {
    for (long long v : adj[u]) {
        if (v != parent[u]) {
            parent[v] = u;
            dfs(adj, parent, subtree, v);
            subtree[u] += subtree[v];
        }
    }
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, u, v;
        cin >> n;
        vector<vector<long long> > adj(n);
        vector<long long> parent(n, -1), subtree(n, 1);
        for (long long i = 1; i < n; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj, parent, subtree);
        vector<long long> mex(n + 1, 0);

        vector<bool> visited(n, false);
        long long l = 0, r = 0;
        visited[0] = true;
        for (long long v : adj[0]) {
            mex[0] += (subtree[v] * (subtree[v] - 1)) >> 1;
        }
        long long p = ((n * (n - 1)) >> 1) - mex[0];
        for (long long i = 1; i < n; ++i) {
            // cout << p << ' ' << subtree << ' ' << l << ' ' << r << ' ' << visited << endl;
            if (!visited[i]) {
                long long j = i;
                do {
                    subtree[parent[j]] -= subtree[j];
                    visited[j] = true;
                    j = parent[j];
                } while (!visited[j]);

                mex[i] = p;
                if (j == l) {
                    l = i;
                    p = subtree[l] * subtree[r];
                    mex[i] -= p;
                } else if (j == r) {
                    r = i;
                    p = subtree[l] * subtree[r];
                    mex[i] -= p;
                } else {
                    p = 0;
                    break;
                }
            }
        }
        mex[n] = p;
        for (long long m : mex) {
            cout << m << ' ';
        }
        cout << endl;
    }
    return 0;
}
