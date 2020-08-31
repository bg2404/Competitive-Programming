#include<bits/stdc++.h>
#define PI 3.1415926535
using namespace std;

void solve() {
    int n;
    double h = 0;
    cin >> n;
    double s = sqrt((1-cos(PI/n))*(1-cos(PI/n)) + sin(PI/n)*sin(PI/n));
    // cout << s << ' ';
    int x = n / 2, y = n - n / 2;
    h = sqrt((1-cos(PI/n*x))*(1-cos(PI/n*x)) + sin(PI/n*x)*sin(PI/n*x));
    h += sqrt((1-cos(PI/n*y))*(1-cos(PI/n*y)) + sin(PI/n*y)*sin(PI/n*y));
    h /= sqrt(2);
    h /= s;
    cout << fixed << setprecision(9) << h << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}