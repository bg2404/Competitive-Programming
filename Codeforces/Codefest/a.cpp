#include<iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long a, b, n;
        cin >> a >> b >> n;
        if(n%3 == 0) {
            cout << a << '\n';
        } else if(n%3 == 1) {
            cout << b << '\n';
        } else {
            cout << (a ^ b) << '\n';
        }
    }
    return 0;
}