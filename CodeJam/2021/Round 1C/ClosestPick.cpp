#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int numberOfTestCases;
    cin >> numberOfTestCases;
    for (int caseNumber = 1; caseNumber <= numberOfTestCases; ++caseNumber) {
        long long n, k;
        cin >> n >> k;
        vector<long long> p(n), q;
        for (long long i = 0; i < n; ++i) {
            cin >> p[i];
        }
        sort(p.begin(), p.end());
        long long diff = 0;
        for (long long i = 1; i < n; ++i) {
            q.push_back(p[i] - p[i - 1] - 1);
        }
        sort(q.begin(), q.end());
        if (n > 1) {
            diff = q.back();
        }
        diff = max(diff, max(((diff + 1) / 2) + max(k - p[n - 1], p[0] - 1), max(0LL, p[0] - 1) + k - p[n - 1]));
        if (n > 2) {
            diff = max(diff, (q[n - 2] + 1) / 2 + (q[n - 3] + 1) / 2);
        }
        double ans = (double)diff / k;
        cout << "Case #" << caseNumber << ": " << setprecision(9) << ans << '\n';
    }
    return 0;
}