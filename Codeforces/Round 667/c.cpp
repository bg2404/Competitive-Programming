#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int d = y - x;
        for(int i = 1; i <= d; ++i) {
            if(d % i == 0 && d / i < n) {
                int a = y;
                for(int j = 1; j < n && a > 0; ++j) {
                    a -= i;
                }
                if(a <= 0) {
                    a += i;
                }
                for(int j = 0; j < n; ++j) {
                    cout << a << ' ';
                    a += i;
                }
                cout << '\n';
                break;
            }
        }
    }
    return 0;
}