#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<vector<char> > &grid, int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] != '.') {
                int count = 0;
                for (int k = 0; k < r; ++k) {
                    count += (grid[k][j] != '.');
                }
                for (int k = 0; k < c; ++k) {
                    count += (grid[i][k] != '.');
                }
                if (count == 2) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int totalNumberOfCases;
    cin >> totalNumberOfCases;
    for (int caseNumber = 1; caseNumber <= totalNumberOfCases; ++caseNumber) {
        int r, c;
        cin >> r >> c;
        vector<vector<char> > grid(r, vector<char>(c));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> grid[i][j];
            }
        }
        if (isPossible(grid, r, c)) {
            set<pair<int, int> > changes;
            // Column
            for (int i = 1; i < r - 1; ++i) {
                // First Column
                if (grid[i][0] == '<') {
                    changes.insert({i, 0});
                } else if (grid[i][0] == '.') {
                    int j = 1;
                    while (j < c && grid[i][j] == '.') {
                        ++j;
                    }
                    if (j < c && grid[i][j] == '<') {
                        changes.insert({i, j});
                    }
                }
                // Last Column
                if (grid[i][c - 1] == '>') {
                    changes.insert({i, c - 1});
                } else if (grid[i][c - 1] == '.') {
                    int j = c - 2;
                    while (j >= 0 && grid[i][j] == '.') {
                        --j;
                    }
                    if (j >= 0 && grid[i][j] == '>') {
                        changes.insert({i, j});
                    }
                }
            }
            // Row
            for (int j = 1; j < c - 1; ++j) {
                // First Row
                if (grid[0][j] == '^') {
                    changes.insert({0, j});
                } else if (grid[0][j] == '.') {
                    int i = 1;
                    while (i < r && grid[i][j] == '.') {
                        ++i;
                    }
                    if (i < r && grid[i][j] == '^') {
                        changes.insert({i, j});
                    }
                }
                // Last Row
                if (grid[r - 1][j] == 'v') {
                    changes.insert({r - 1, j});
                } else if (grid[0][j] == '.') {
                    int i = r - 2;
                    while (i >= 0 && grid[i][j] == '.') {
                        --i;
                    }
                    if (i >= 0 && grid[i][j] == 'v') {
                        changes.insert({i, j});
                    }
                }
            }
            // Corners
            if (grid[0][0] == '^' || grid[0][0] == '<') {
                changes.insert({0, 0});
            }
            if (grid[0][c - 1] == '^' || grid[0][c - 1] == '>') {
                changes.insert({0, c - 1});
            }
            if (grid[r - 1][0] == 'v' || grid[r - 1][0] == '<') {
                changes.insert({r - 1, 0});
            }
            if (grid[r - 1][c - 1] == 'v' || grid[r - 1][c - 1] == '>') {
                changes.insert({r - 1, c - 1});
            }
            cout << "Case #" << caseNumber << ": " << changes.size() << '\n';
        } else {
            cout << "Case #" << caseNumber << ": "
                 << "IMPOSSIBLE" << '\n';
        }
    }
    return 0;
}