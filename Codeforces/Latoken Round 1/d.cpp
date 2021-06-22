#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > edges;

vector<int> query(int x, int n) {
    cout << "? " << x << endl;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    return d;
}

void addEdges(vector<int>& d, int x) {
    for (int idx = 1; int i : d) {
        if (i == 1) {
            edges.emplace_back(x, idx);
        }
        ++idx;
    }
}

int main() {
    int n;
    cin >> n;
    int p;
    auto d = query(1, n);
    int o = 0, e = 0;
    for (int i : d) {
        if (i & 1) {
            ++o;
        } else {
            ++e;
        }
    }
    if (o < e) {
        p = 1;
    } else {
        p = 0;
    }
    if (p == 0) {
        addEdges(d, 1);
    }
    for (int i = 1; i < n; ++i) {
        if ((d[i] & 1) == p) {
            auto t = query(i + 1, n);
            addEdges(t, i + 1);
        }
    }
    cout << "!" << endl;
    for (auto e : edges) {
        cout << e.first << ' ' << e.second << endl;
    }
    return 0;
}