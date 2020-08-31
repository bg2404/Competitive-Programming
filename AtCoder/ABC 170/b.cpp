#include<bits/stdc++.h>

using namespace std;

set<int> a;

int main() {
    int x, y;
    cin >> x >> y;
    int a = y - 2*x;
    int b = 4*x - y;
    if(!(a&1) && !(b&1)) {
        a /= 2;
        b /= 2;
        if(a >= 0 && b >= 0) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}