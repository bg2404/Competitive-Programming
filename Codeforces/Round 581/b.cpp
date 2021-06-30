#include<iostream>

using namespace std;

int pow[21] = {1};

int main() {
    for(int i = 1; i < 21; ++i) {
        pow[i] = pow[i-1] << 1;
    }
    int n, l , r;
    cin >> n >> l >> r;
    cout << pow[l] - 1 + (n-l) << " " << pow[r] - 1 + (n-r)*pow[r-1] << '\n';
    return 0;
}