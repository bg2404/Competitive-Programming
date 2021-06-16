#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int d = abs(a - b);
        if(d == 0) {
            cout << 0 << '\n';
        } else {
            cout << (d-1)/10 + 1 << '\n';
        }
    }
    return 0;
}