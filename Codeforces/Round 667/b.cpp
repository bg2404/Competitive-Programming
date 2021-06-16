#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        int d1 = a - x, d2 = b - y;
        if(d1 + d2 <= n) {
            cout << (long long)x * y << '\n';
        } else {
            int a_ = a - n;
            int b_ = b;
            if(a_ < x) {
                b_ = b_ - (x - a_);
                a_ = x;
            }
            long long c_ = (long long)a_ * b_;
            a_ =  a;
            b_ = b - n;
            if(b_ < y) {
                a_ = a_ - (y - b_);
                b_ = y;
            }
            c_ = min(c_, (long long)a_ * b_);
            cout << c_ << '\n';
        }
    }
    return 0;
}