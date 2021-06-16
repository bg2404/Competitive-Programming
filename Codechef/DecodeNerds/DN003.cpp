#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, prev = 1, ans = 0, cur;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> cur;
        if((prev == 1 && cur == 0) || (prev == 0 && cur == 1)) {
            ++ans;
        }
        prev = cur;
    }
    cout << ans << endl;
    return 0;
}