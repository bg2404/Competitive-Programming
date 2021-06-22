#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int r, c;
        cin >> r >> c;
        vector<vector<int> > grid(r, vector<int>(c)), upper(r, vector<int>(c, 0)), lower(r, vector<int>(c, 0)), right(r, vector<int>(c, 0)), left(r, vector<int>(c, 0));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> grid[i][j];
            }
        }

        // UPPER
        for (int i = 0; i < c; ++i) {
            upper[0][i] = grid[0][i];
        }
        for (int i = 1; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j])
                    upper[i][j] = upper[i - 1][j] + grid[i][j];
                else
                    upper[i][j] = 0;
            }
        }

        // LOWER
        for (int i = 0; i < c; ++i) {
            lower[r - 1][i] = grid[r - 1][i];
        }
        for (int i = r - 2; i >= 0; --i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j])
                    lower[i][j] = lower[i + 1][j] + grid[i][j];
                else
                    lower[i][j] = 0;
            }
        }

        // RIGHT
        for (int i = 0; i < r; ++i) {
            right[i][c - 1] = grid[i][c - 1];
        }
        for (int i = 0; i < r; ++i) {
            for (int j = c - 2; j >= 0; --j) {
                if (grid[i][j]) {
                    right[i][j] = right[i][j + 1] + grid[i][j];
                } else {
                    right[i][j] = 0;
                }
            }
        }

        // LEFT
        for (int i = 0; i < r; ++i) {
            left[i][0] = grid[i][0];
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                if (grid[i][j]) {
                    left[i][j] = left[i][j - 1] + grid[i][j];
                } else {
                    left[i][j] = 0;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j]) {
                    // Upper-Left
                    for (int k = 2, l = 4; k <= left[i][j] && l <= upper[i][j]; ++k, l += 2) {
                        ++ans;
                    }
                    for (int k = 2, l = 4; k <= upper[i][j] && l <= left[i][j]; ++k, l += 2) {
                        ++ans;
                    }
                    // Upper-right
                    for (int k = 2, l = 4; k <= right[i][j] && l <= upper[i][j]; ++k, l += 2) {
                        ++ans;
                    }
                    for (int k = 2, l = 4; k <= upper[i][j] && l <= right[i][j]; ++k, l += 2) {
                        ++ans;
                    }
                    // Lower-right
                    for (int k = 2, l = 4; k <= right[i][j] && l <= lower[i][j]; ++k, l += 2) {
                        ++ans;
                    }
                    for (int k = 2, l = 4; k <= lower[i][j] && l <= right[i][j]; ++k, l += 2) {
                        ++ans;
                    }
                    // Lower-left
                    for (int k = 2, l = 4; k <= left[i][j] && l <= lower[i][j]; ++k, l += 2) {
                        ++ans;
                    }
                    for (int k = 2, l = 4; k <= lower[i][j] && l <= left[i][j]; ++k, l += 2) {
                        ++ans;
                    }
                }
            }
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}