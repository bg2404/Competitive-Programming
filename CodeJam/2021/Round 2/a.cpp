#include <bits/stdc++.h>

using namespace std;

int main() {
    int totalNumberOfCases;
    cin >> totalNumberOfCases;
    int N;
    cin >> N;
    int res;
    for (int caseNumber = 1; caseNumber <= totalNumberOfCases; ++caseNumber) {
        for (int i = 1; i < N; ++i) {
            cout << "M " << i << " " << N << endl;
            int min;
            cin >> min;
            if (i < min) {
                cout << "S " << i << " " << min << endl;
                cin >> res;
                if (res != 1) {
                    return 0;
                }
            }
        }
        cout << "D" << endl;
        cin >> res;
        if (res != 1) {
            return 0;
        }
    }
    return 0;
}