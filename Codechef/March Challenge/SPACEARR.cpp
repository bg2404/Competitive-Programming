#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int a[N];
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }
        sort(a, a + N);
        int cnt = 0;
        int player = 1;
        for (int i = 0; i < N; ++i) {
            if (a[i] > i + 1) {
                player = 2;
                break;
            }
            cnt += i + 1 - a[i];
        }
        if (player == 1 && (cnt & 1)) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    }
}