#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &os, vector<int> &a) {
    for (int d : a) {
        os << d;
    }
    return os;
}

int evaluate(vector<int> &a, vector<int> &b, int q) {
    int score = 0;
    for (int i = 0; i < q; ++i) {
        score += a[i] == b[i];
    }
    return score;
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, q;
        cin >> n >> q;
        vector<vector<int> > a(n, vector<int>(q));
        vector<int> s(n);
        for (int i = 0; i < n; ++i) {
            string aa;
            cin >> aa >> s[i];
            for (int j = 0; j < q; ++j) {
                a[i][j] = (aa[j] == 'T');
            }
        }

        vector<vector<int> > pos;
        vector<int> b(q, 0);
        int m = (1 << q);
        for (int i = 0; i < m; ++i) {
            bool correct = true;
            for (int j = 0; j < n; ++j) {
                // cout << b << ' ' << a[j] << ' ' << evaluate(b, a[j], q) << ' ' << s[j] << '\n';
                if (evaluate(b, a[j], q) != s[j]) {
                    correct = false;
                    break;
                }
            }

            if (correct) {
                pos.push_back(b);
            }

            int c = 1;
            for (int j = 0; j < q; ++j) {
                b[j] += c;
                c = (b[j] == 2 ? 1 : 0);
                b[j] %= 2;
            }
        }

        long long ans = 0;
        b = vector<int>(q, 0);
        vector<int> sol = b;
        n = pos.size();
        for (int i = 0; i < m; ++i) {
            long long score = 0;
            for (int j = 0; j < n; ++j) {
                score += evaluate(b, pos[j], q);
            }
            if (ans < score) {
                ans = score;
                sol = b;
            }

            int c = 1;
            for (int j = 0; j < q; ++j) {
                b[j] += c;
                c = (b[j] == 2 ? 1 : 0);
                b[j] %= 2;
            }
        }

        // cout << ans << ' ' << n << ' ';

        long long g = gcd(ans, n);
        // cout << g << '\n';

        long long z = ans / g;
        long long w = n / g;

        cout << "Case #" << t << ": ";
        for (int i = 0; i < q; ++i) {
            if (sol[i]) {
                cout << 'T';
            } else {
                cout << 'F';
            }
        }
        cout << ' ' << z << '/' << w << '\n';
    }
}