#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int C, d;
        cin >> C;
        d = 0;
        int temp = 1;
        while (temp <= C) {
            temp <<= 1;
            ++d;
        }
        int A, B;
        A = B = temp - 1;
        temp = 1;
        while (temp <= C) {
            if ((temp & C) != 0) {
                A ^= temp;
            }
            temp <<= 1;
        }
        A ^= (temp >>= 1);
        B ^= temp;
        cout << (long long)A * B << '\n';
    }
    return 0;
}