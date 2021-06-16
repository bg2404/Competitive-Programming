#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    os << "[ ";
    for (T e : v) {
        os << e << ' ';
    }
    os << "]\n";
    return os;
}

int NOT(int i) {
    vector<int> bits;
    while (i > 0) {
        bits.push_back(!(i & 1));
        i /= 2;
    }
    if (bits.empty()) {
        return 1;
    }
    int b = 0;
    for (int i = (int)(bits.size()) - 1; i >= 0; --i) {
        b = b * 2 + bits[i];
    }
    return b;
}

vector<vector<int> > init() {
    vector<vector<int> > adj(100000, vector<int>());
    for (int i = 0; i < 100000; ++i) {
        int d = i * 2, n = NOT(i);
        if (d < 100000 && d != 0) {
            adj[i].push_back(d);
        }
        adj[i].push_back(n);
    }
    return adj;
}

int bfs(vector<vector<int> > &adj, int s, int e) {
    if (s == e) {
        return 0;
    }
    vector<int> visited(100000, false);
    queue<pair<int, int> > q;
    q.push({s, 0});
    visited[s] = true;
    while (!q.empty()) {
        int s = q.front().first;
        int d = q.front().second;
        q.pop();
        for (int u : adj[s]) {
            if (!visited[u]) {
                if (u == e) {
                    return d + 1;
                }
                visited[u] = true;
                q.push({u, d + 1});
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int> > adj = init();
    int numberOfTestCases;
    cin >> numberOfTestCases;
    for (int caseNumber = 1; caseNumber <= numberOfTestCases; ++caseNumber) {
        string ss, se;
        cin >> ss >> se;
        int s = stoi(ss, 0, 2), e = stoi(se, 0, 2);
        int ans = bfs(adj, s, e);
        if (ans == -1) {
            cout << "Case #" << caseNumber << ": "
                 << "IMPOSSIBLE" << '\n';
        } else {
            cout << "Case #" << caseNumber << ": " << ans << '\n';
        }
    }
    return 0;
}
