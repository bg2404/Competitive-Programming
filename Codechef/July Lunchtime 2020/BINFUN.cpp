#include<bits/stdc++.h>

using namespace std;

string get_binary(int n) {
    string a;
    while(n) {
        a.push_back(n&1);
        n >>= 1;
    }
    reverse(a.begin(), a.end());
    return a;
}

long long subtract(string a, string b) {
    long long x = 0, y = 0;
    for(int i = 0; i < a.size(); ++i) {
        x <<= 1;
        x += (a[i]-'0');
    }
    for(int i = 0; i < b.size(); ++i) {
        y <<= 1;
        y += (b[i]-'0');
    }
    return x - y;
}

long long binFun(int x, int y) {
    string binX = get_binary(x), binY = get_binary(y);
    return subtract(binX+binY, binY+binX);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a) {
        cin >> i;
    }
    long long ans = LLONG_MIN;
    cout << setw(4) << ' ';
    for(int i = 0; i < a.size(); ++i) {
        cout << setw(4) << a[i];
    }
    cout << '\n';
    for(int i = 0; i < n; ++i) {
        cout << setw(4) << a[i];
        for(int j = 0; j < n; ++j) {
            cout << setw(4) << binFun(a[i], a[j]);
            ans = max(ans, binFun(a[i], a[j]));
        }
        cout << '\n';
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}