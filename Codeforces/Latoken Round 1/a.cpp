#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    os << "[ ";
    for (T e : v) {
        os << e << ' ';
    }
    os << ']';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (string& s : grid) {
            cin >> s;
        }
        int t = 0, u = 0, v = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != '.') {
                    if ((i + j) % 2 == 0) {
                        if (grid[i][j] == 'R') {
                            ++t;
                        } else {
                            ++u;
                        }
                    } else {
                        if (grid[i][j] == 'R') {
                            ++u;
                        } else {
                            ++t;
                        }
                    }
                } else {
                    ++v;
                }
            }
        }
        if (t > 0 && u > 0) {
            cout << "NO\n";
        } else if (t > 0 || u > 0 || v > 0) {
            if (t == 0 && u == 0) {
                t = v;
            }
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if ((i + j) % 2 == 0) {
                        if (t > 0) {
                            cout << 'R';
                        } else {
                            cout << 'W';
                        }
                    } else {
                        if (t > 0) {
                            cout << 'W';
                        } else {
                            cout << 'R';
                        }
                    }
                }
                cout << '\n';
            }
        } else {
            cout << "YES\n";
            for (string s : grid) {
                cout << s << '\n';
            }
        }
    }
    return 0;
}