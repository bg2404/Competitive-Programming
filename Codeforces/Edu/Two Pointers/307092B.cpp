#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int i, j;
    for (i = 0, j = 0, i = 0; j < m; ++j) {
        while (i < n && a[i] < b[j]) {
            ++i;
        }
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}