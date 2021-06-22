#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

vector<int> pr;
vector<int> lp;

ostream &operator<<(ostream &os, vector<int> &a) {
    int n = a.size();
    if (n == 0) {
        os << "{ }";
        return os;
    }
    cout << '{';
    for (int i = 0; i < n - 1; ++i) {
        os << a[i] << ", ";
    }
    os << a[n - 1] << "}";
    return os;
}

vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> ans({1});
    int cnt;
    for (int prime : pr) {
        cnt = 0;
        while (x % prime == 0) {
            ++cnt;
            x /= prime;
        }
        if (cnt) {
            ans.push_back({prime, cnt});
        }
    }
    return ans;
}

vector<pair<int, int>> set_union(vector<pair<int, int>> &a, vector<pair<int, int>> &b) {
    int j = 1;
    int n = b.size();
    vector<pair<int, int>> c;
    for (auto x : a) {
        while (j < n && b[j].first < x.first) {
            c.push_back(b[j++]);
        }
        if (j < n && b[j].first == x.first) {
            c.push_back({x.first, x.second + b[j].second});
            ++j;
        } else {
            c.push_back(x);
        }
    }
    while (j < n) {
        c.push_back(b[j++]);
    }
    return c;
}

vector<pair<int, int>> set_intersection(vector<pair<int, int>> &a, vector<pair<int, int>> &b) {
    if (b.size() == 0) {
        return a;
    }
    int j = 0;
    int m = b.size();
    vector<pair<int, int>> c;
    for (auto x : a) {
        while (j < m && b[j].first < x.first) ++j;
        if (j == m) {
            break;
        } else if (b[j].first == x.first) {
            c.push_back({x.first, min(x.second, b[j].second)});
            ++j;
        }
    }
    return c;
}

class SegmentTree {
    int SIZE;
    vector<vector<pair<int, int>>> tree;

    void constructSegementTree(vector<int> &v, int idx, int l, int r) {
        if (l == r) {
            if (r < (int)v.size()) {
                tree[idx] = factorize(v[r]);
            }
        } else {
            int m = (l + r) >> 1;
            constructSegementTree(v, 2 * idx + 1, l, m);
            constructSegementTree(v, 2 * idx + 2, m + 1, r);
            tree[idx] = set_intersection(tree[2 * idx + 1], tree[2 * idx + 2]);
        }
    }

    void update(int idx, int l, int r, int i, int x) {
        if (l == r) {
            if (r <= i) {
                vector<pair<int, int>> v = factorize(x);
                tree[idx] = set_union(tree[idx], v);
            }
        } else {
            int m = (l + r) >> 1;
            if (i > m) {
                update(2 * idx + 2, m + 1, r, i, x);
            } else {
                update(2 * idx + 1, l, m, i, x);
            }
            tree[idx] = set_intersection(tree[2 * idx + 1], tree[2 * idx + 2]);
        }
    }

   public:
    SegmentTree(vector<int> &v) {
        int n = (int)v.size();
        SIZE = 1;
        while (SIZE < n) {
            SIZE <<= 1;
        }
        tree.resize(2 * SIZE - 1, {});
        constructSegementTree(v, 0, 0, SIZE - 1);
    }

    void update(int i, int x) {
        update(0, 0, SIZE - 1, i, x);
    }

    int gcd() {
        long long ans = 1;
        for (auto f : tree[0]) {
            for (int j = 0; j < f.second; ++j) {
                ans = (ans * f.first) % MOD;
            }
        }
        return ans;
    }
};

int main() {
    int N = 200000;
    lp.resize(N + 1, 0);
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    SegmentTree st(a);
    int i, x;
    while (q--) {
        cin >> i >> x;
        st.update(i - 1, x);
        cout << st.gcd() << endl;
    }
    return 0;
}