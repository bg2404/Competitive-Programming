#include <bits/stdc++.h>

using namespace std;

vector<int> dfs(vector<vector<int> > &adj, int u = 0, int p = -1) {
    if (adj[u].size() == 1) {
        return {u + 1, 0};
    }
    int d = -1;
    vector<int> k;
    for (int v : adj[u]) {
        if (v != p) {
            vector<int> tk = dfs(adj, v, u);
            int td = tk.back();
            tk.pop_back();
            if (d == -1) {
                d = td;
                k = tk;
            } else if (p == -1) {
                if (td < d) {
                    d = td;
                    k = tk;
                } else if (td == d) {
                    k.insert(k.end(), tk.begin(), tk.end());
                }
            } else {
                if (td == d) {
                    k.insert(k.end(), tk.begin(), tk.end());
                } else if (d < td) {
                    d = d + 1;
                    k = tk;
                }
            }
        }
    }
    ++d;
    return k;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, u, v;
        scanf("%d", &N);

        vector<vector<int> > adj(N);
        for (int i = 1; i < N; ++i) {
            scanf("%d %d", &u, &v);
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans = dfs(adj);
        printf("%d\n", ans.size());
        for (int i : ans) {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}