#include<bits/stdc++.h>

using namespace std;

int make_cgood(string s, int n, char c) {
    if(n == 1) {
        return s[0] != c;
    }
    int x1 = 0, x2 = 0, n1 = n / 2;
    string s1 = s.substr(0, n1), s2 = s.substr(n1, n1);
    for(int i = 0; i < n1; ++i) {
        x1 += (s1[i] != c);
        x2 += (s2[i] != c);
    }
    return min(x1 + make_cgood(s2, n1, c + 1), x2 + make_cgood(s1, n1, c + 1));
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << make_cgood(s, n, 'a') << '\n';
    }
    return 0;
}