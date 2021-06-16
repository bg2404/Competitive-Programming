#include<bits/stdc++.h>

using namespace std;

int main() {
    int input, n, max_n = 0;;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> input;
        max_n = max(max_n, input);
    }
    int m , max_m = 0;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        cin >> input;
        max_m = max(max_m, input);
    }
    cout << max_n << " " << max_m << '\n';
    return 0;
}