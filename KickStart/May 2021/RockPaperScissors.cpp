#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main() {
    int totalNumberOfCases;
    cin >> totalNumberOfCases;
    int X;
    cin >> X;
    for (int caseNumber = 1; caseNumber <= totalNumberOfCases; ++caseNumber) {
        int W, E;
        cin >> W >> E;
        cout << "Case #" << caseNumber << ": ";
        int r = 0, p = 0, s = 0, k = 20;
        for (int j = 0; j < k; ++j) {
            for (int i = 0; i < 20/k; ++i) {
                cout << 'R';
            }
            for (int i = 0; i < 20/k; ++i) {
                cout << 'S';
            }
            for (int i = 0; i < 20/k; ++i) {
                cout << 'P';
            }
        }
        cout << '\n';
    }
    return 0;
}