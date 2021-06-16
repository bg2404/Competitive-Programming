#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main() {
    int totalNumberOfCases;
    cin >> totalNumberOfCases;
    for (int caseNumber = 1; caseNumber <= totalNumberOfCases; ++caseNumber) {
        long long G;
        cin >> G;
        long long ans = 0;
        for (int i = 1; G > 0; ++i) {
            if (G % i == 0) {
                ++ans;
            }
            G -= i;
        }
        cout << "Case #" << caseNumber << ": " << ans << endl;
    }
    return 0;
}