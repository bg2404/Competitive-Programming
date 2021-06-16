#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    os << "[ ";
    for (T e : v) {
        os << e << ' ';
    }
    os << ']';
    return os;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int score = s[0] == 'W';
        for (int i = 1; i < n; ++i) {
            if (s[i] == 'W') {
                ++score;
                if (s[i - 1] == 'W') {
                    ++score;
                }
            }
        }
        if (k > 0) {
            vector<int> d;
            int prev = -1;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'W') {
                    d.push_back(i - prev - 1);
                    prev = i;
                }
            }
            d.push_back(n - prev - 1);

            if (d.size() == 1) {
                score = k + k - 1;
            } else {
                sort(d.begin() + 1, d.end() - 1);
                for (int i = 1; i + 1 < d.size(); ++i) {
                    if (k >= d[i]) {
                        if (d[i] > 0) {
                            score += d[i] + d[i] + 1;
                            k -= d[i];
                        }
                    } else {
                        score += k + k;
                        k = 0;
                    }
                }
                score += min(k, d[0] + d.back()) * 2;
            }
        }
        cout << score << endl;
    }
}