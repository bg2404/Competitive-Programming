#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, x;
    cin >> n;
    vector<int> a;
    a.reserve(n);
    for(int i = 0; i < n; ++i) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for(int i = n-1; i > 1; --i) {
        if(a[i] < a[i-1] + a[i-2]) {
            cout << "YES\n" << a[i] << ' ' << a[i-1] << ' ' << a[i-2] << '\n';
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}