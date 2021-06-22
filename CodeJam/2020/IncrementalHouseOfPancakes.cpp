#include <bits/stdc++.h>

using namespace std;

long long binary_search(long long x) {
    long long l = 0, r = 2000000001, m;
    while (l <= r) {
        m = (l + r) >> 1;
        if ((m * (m + 1)) / 2 <= x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return r;
}

long long sumo(long long &total, long long after) {
    long long init = (after + 1) / 2;
    total += init * init;
    long long l = 0, r = 2000000001, m;
    while (l <= r) {
        m = (l + r) >> 1;
        if (m * m <= total) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    total -= r * r;
    return 2 * r - 1;
}
long long sume(long long &total, long long after) {
    long long a = (after & 1) ? after + 1 : after + 2;
    long long l = 0, r = 2000000001, m;
    while (l <= r) {
        m = (l + r) >> 1;
        if (m * (a + m - 1) <= total) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    total -= r * (a + r - 1);
    return a - 2 + 2 * r;
}

int main() {
    int numCases;
    cin >> numCases;
    for (int caseNum = 1; caseNum <= numCases; ++caseNum) {
        long long stack[2];
        cin >> stack[0] >> stack[1];
        long long l = 0, n = 0;
        if (stack[0] < stack[1]) {
            l = 1;
        }
        n = binary_search(stack[l] - stack[l ^ 1]);
        stack[l] -= (n * (n + 1)) / 2;
        int o, e;
        if (stack[0] == stack[1]) {
            if (n & 1) {
                e = 0;
                o = 1;
            } else {
                e = 1;
                o = 0;
            }
        } else {
            if (n & 1) {
                e = l;
                o = l ^ 1;
            } else {
                e = l ^ 1;
                o = l;
            }
        }
        n = max(sume(stack[e], n), sumo(stack[o], n));
        cout << "Case #" << caseNum << ": " << n << ' ' << stack[0] << ' ' << stack[1] << '\n';
    }
    return 0;
}