#include <bits/stdc++.h>

using namespace std;

int main() {
    double pl, pr, vl, vr, k;
    cin >> pl >> pr >> vl >> vr >> k;
    vector<int> number;
    int size = 1022, max_num = 777777777;
    number.reserve(size);
    number.push_back(4);
    number.push_back(7);
    int index = 0;
    while (number.back() < max_num) {
        number.push_back(number[index] * 10 + 4);
        number.push_back(number[index] * 10 + 7);
        ++index;
    }
    double ans = 0;
    int start = 0, end = 1000000000;
    for (int l = 0, r = k - 1; r < size; ++l, ++r) {
        double xl, xr, yl, yr;
        if (l <= 0) {
            xl = start;
        } else {
            xl = number[l - 1] + 1;
        }
        xr = number[l];
        yl = number[r];
        if (r >= size - 1) {
            yr = end;
        } else {
            yr = number[r + 1] - 1;
        }
        xl = max(xl, pl);
        xr = min(xr, pr);
        yl = max(yl, vl);
        yr = min(yr, vr);
        if (xl <= xr && yl <= yr) {
            ans += ((xr - xl + 1) / (pr - pl + 1)) * ((yr - yl + 1) / (vr - vl + 1));
        }
        if (l <= 0) {
            xl = start;
        } else {
            xl = number[l - 1] + 1;
        }
        xr = number[l];
        yl = number[r];
        if (r >= size - 1) {
            yr = end;
        } else {
            yr = number[r + 1] - 1;
        }
        xl = max(xl, vl);
        xr = min(xr, vr);
        yl = max(yl, pl);
        yr = min(yr, pr);
        if (xl <= xr && yl <= yr) {
            ans += ((xr - xl + 1) / (vr - vl + 1)) * ((yr - yl + 1) / (pr - pl + 1));
        }
        if (k == 1 && number[l] >= pl && number[l] <= pr && number[l] >= vl && number[l] <= vr) {
            ans -= 1 / ((pr - pl + 1) * (vr - vl + 1));
        }
    }
    cout << setprecision(12) << ans << endl;
    return 0;
}