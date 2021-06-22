#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    os << "[ ";
    for (T e : v) {
        os << e << ' ';
    }
    os << "]";
    return os;
}

int main() {
    int totalCases;
    cin >> totalCases;
    for (int caseNo = 1; caseNo <= totalCases; ++caseNo) {
        int C, D;
        cin >> C >> D;
        vector<int> X(C), c1, c2, Y, nodeWeight(C);
        X[0] = 0;
        nodeWeight[0] = 0;
        c2.push_back(0);
        for (int i = 1; i < C; ++i) {
            cin >> X[i];
            if (X[i] < 0) {
                c2.push_back(i);
                nodeWeight[i] = -1;
            } else {
                c1.push_back(i);
                nodeWeight[i] = X[i];
            }
        }
        sort(c1.begin(), c1.end(), [&X](const int i, const int j) {
            return X[i] < X[j];
        });
        sort(c2.begin(), c2.end(), [&X](const int i, const int j) {
            return X[i] > X[j];
        });

        int i, j;
        for (i = 0, j = 0; i < c2.size(); ++i) {
            while (j < c1.size() && Y.size() < -X[c2[i]]) {
                Y.push_back(c1[j++]);
            }
            Y.push_back(c2[i]);
        }
        while (j < c1.size()) {
            Y.push_back(c1[j++]);
        }
        for (int i = 1; i < C; ++i) {
            if (nodeWeight[Y[i]] == -1) {
                nodeWeight[Y[i]] = nodeWeight[Y[i - 1]] + (X[Y[i - 1]] != X[Y[i]]);
            }
        }
        vector<pair<int, int> > edge(D);
        vector<vector<int> > adj(C);
        for (int i = 0; i < D; ++i) {
            cin >> edge[i].first >> edge[i].second;
            --edge[i].first;
            --edge[i].second;
            adj[edge[i].first].push_back(edge[i].second);
            adj[edge[i].second].push_back(edge[i].first);
        }
        map<pair<int, int>, int> edgeWeight;
        vector<bool> visited(C, false);
        auto compare = [nodeWeight](const pair<int, int> i, const pair<int, int> j) {
            return nodeWeight[i.first] > nodeWeight[j.first];
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(compare)> pq(compare);
        pq.push({0, 0});
        visited[0] = true;
        int u, p;
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            u = top.first;
            p = top.second;
            edgeWeight[{p, u}] = edgeWeight[{u, p}] = nodeWeight[u] - nodeWeight[p];
            pq.pop();
            for (int v : adj[u]) {
                if (!visited[v] && nodeWeight[u] < nodeWeight[v]) {
                    visited[v] = true;
                    pq.push({v, u});
                }
            }
        }
        cout << "Case #" << caseNo << ": ";
        for (int i = 0; i < D; ++i) {
            if (edgeWeight.find(edge[i]) != edgeWeight.end()) {
                cout << edgeWeight[edge[i]] << ' ';
            } else {
                cout << 1000000 << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}