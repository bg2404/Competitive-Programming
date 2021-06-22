#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int> > a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i + 1;
        }
        sort(a.begin(), a.end());
        int pw = 0;
        long long cnt = 0;
        for (int i = 0; i < n;) {
            if (cnt < a[i].first) {
                pw = i;
            }
            long long cur = a[i].first;
            int j = i + 1;
            while (j < n && cur == a[j].first) {
                ++j;
            }
            cnt += cur * (j - i);
            i = j;
        }
        vector<int> winners;
        for (int i = pw; i < n; ++i) {
            winners.push_back(a[i].second);
        }
        sort(winners.begin(), winners.end());
        cout << winners.size() << '\n';
        for (unsigned int i = 0; i < winners.size(); ++i) {
            cout << winners[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}