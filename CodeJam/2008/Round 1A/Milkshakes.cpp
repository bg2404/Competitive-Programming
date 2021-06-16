#include <iostream>
#include <vector>

using namespace std;

int main() {
    int C;
    cin >> C;
    for (int c = 1; c <= C; ++c) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int> > > customer(m, vector<pair<int, int> >());
        vector<vector<vector<int> > > flavour(n, vector<vector<int> >(2, vector<int>()));
        vector<int> satisfiablity(m, 0), batch(n, 0);
        for (int i = 0; i < m; ++i) {
            int t;
            cin >> t;
            customer[i].resize(t, {0, 0});
            for (int j = 0; j < t; ++j) {
                cin >> customer[i][j].first >> customer[i][j].second;
                --customer[i][j].first;
                flavour[customer[i][j].first][customer[i][j].second].push_back(i);
                if (customer[i][j].second == 0) {
                    ++satisfiablity[i];
                }
            }
        }
        bool pos = true;
        do {
            pos = true;
            int unsatisfied = -1;
            for (int i = 0; i < m; ++i) {
                if (satisfiablity[i] == 0) {
                    pos = false;
                    unsatisfied = i;
                    break;
                }
            }
            if(unsatisfied == -1) {
                break;
            }
            int toggle = -1;
            int t = customer[unsatisfied].size();
            for (int i = 0; i < t; ++i) {
                if (customer[unsatisfied][i].second == 1) {
                    toggle = customer[unsatisfied][i].first;
                    break;
                }
            }
            if (toggle == -1) {
                break;
            } else {
                int n = flavour[toggle][0].size();
                for (int i = 0; i < n; ++i) {
                    --satisfiablity[flavour[toggle][0][i]];
                }
                n = flavour[toggle][1].size();
                for (int i = 0; i < n; ++i) {
                    ++satisfiablity[flavour[toggle][1][i]];
                }
                batch[toggle] = 1;
            }
        } while (!pos);
        cout << "Case #" << c << ":";
        if (pos) {
            for (int i = 0; i < n; ++i) {
                cout << ' ' << batch[i];
            }
            cout << '\n';
        } else {
            cout << " IMPOSSIBLE\n";
        }
    }
    return 0;
}