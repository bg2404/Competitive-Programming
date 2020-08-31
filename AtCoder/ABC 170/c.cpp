#include<bits/stdc++.h>

using namespace std;

set<int> a;

int main() {
    int n, x;
    cin >> x >> n;
    for(int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        a.insert(p);
    }
    int c = x, b = x;
    bool found = false;
    while(!found) {
        if(a.count(b) == 0) {
            cout << b << '\n';
            return 0;
        }
        --b;
        if(a.count(c) == 0) {
            cout << c << '\n';
            return 0;
        }
        ++c;
    }
    return 0;
}