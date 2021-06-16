#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool operator<(const string &a, const string &b) {
    if (int n; (n = a.length()) == b.length()) {
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }
    }
    return a.length() < b.length();
}

bool operator<=(const string &a, const string &b) {
    if (int n; (n = a.length()) == b.length()) {
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                return a[i] <= b[i];
            }
        }
    }
    return a.length() <= b.length();
}

bool operator>(const string &a, const string &b) {
    if (int n; (n = a.length()) == b.length()) {
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
    }
    return a.length() > b.length();
}

bool operator>=(const string &a, const string &b) {
    if (int n; (n = a.length()) == b.length()) {
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                return a[i] >= b[i];
            }
        }
    }
    return a.length() >= b.length();
}

int main() {
    string MAX = "10000000001000000001";
    vector<string> roaringNumbers;
    roaringNumbers.reserve(2012302);
    for (int i = 1, j; i < 1000001; ++i) {
        j = i + 1;
        string temp = to_string(i).append(to_string(j++));
        while (temp < MAX) {
            roaringNumbers.push_back(temp);
            temp.append(to_string(j++));
        }
    }
    sort(roaringNumbers.begin(), roaringNumbers.end(), [](const string &a, const string &b) { return a < b; });
    roaringNumbers.push_back(MAX);
    int numberOfTestCases;
    cin >> numberOfTestCases;
    for (int caseNumber = 1; caseNumber <= numberOfTestCases; ++caseNumber) {
        long long y;
        cin >> y;
        string s = to_string(y);
        string ans = *upper_bound(roaringNumbers.begin(), roaringNumbers.end(), s, [](const string &a, const string &b) { return a < b; });
        int n = s.length();
        if (n > 5) {
            if (n & 1) {
                string p = string(n / 2, '9') + '1' + string(n / 2, '0');
                if (s < p) {
                    ans = min(ans, p);
                } else {
                    p = '1' + string(n / 2, '0') + '1' + string(n / 2 - 1, '0') + '1';
                    ans = min(ans, p);
                }
            } else {
                int num = stoll(s.substr(0, n / 2));
                string p = to_string(num) + to_string(num + 1);
                if (p < s) {
                    ans = min(ans, p);
                } else {
                    p = to_string(num + 1) + to_string(num + 2);
                    ans = min(ans, p);
                }
            }
        }
        cout << "Case #" << caseNumber << ": " << ans << '\n';
    }
    return 0;
}