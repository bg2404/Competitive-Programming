#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<vector<T> > &v) {
    for (vector<T> r : v) {
        for (T e : r) {
            os << e;
        }
        os << '\n';
    }
    return os;
}


int main() {
    int totalCases;
    cin >> totalCases;
    for (int caseNo = 1; caseNo <= totalCases; ++caseNo) {
        int C;
        cin >> C;
        vector<int> B(C), BC(C);
        for (int i = 0; i < C; ++i) {
            cin >> B[i];
            BC[i] = B[i];
        }
        vector<int> goesTo(C, -1);
        bool possible = true;
        int rows = 1;
        int i, j;
        for (i = 0, j = 0; i < C; ++i) {
            while (j < C && B[j] == 0) {
                ++j;
            }
            if (j == C) {
                break;
            }
            goesTo[i] = j;
            rows = max(rows, abs(j - i) + 1);
            --B[j];
        }
        if (goesTo[0] != 0 || goesTo[C - 1] != C - 1) {
            possible = false;
        }
        cout << "Case #" << caseNo << ": ";
        if (!possible) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << rows << '\n';
            vector<vector<char> > grid(rows, vector<char>(C, '.'));
            for (int i = 0; i < C; ++i) {
                if (i < goesTo[i]) {
                    for (int j = i, k = 0; j < goesTo[i]; ++j, ++k) {
                        grid[k][j] = '\\';
                    }
                } else if (i > goesTo[i]) {
                    for (int j = i, k = 0; j > goesTo[i]; --j, ++k) {
                        grid[k][j] = '/';
                    }
                }
            }
            cout << grid;
        }
    }
    return 0;
}