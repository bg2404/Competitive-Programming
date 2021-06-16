#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string s[n];
    int a[m], score = 0;
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    for(int j = 0; j < m; ++j) {
        int max_opt = 0;
        vector<int> opt(5,0);
        for(int i = 0; i < n; ++i) {
            opt[s[i][j] - 'A']++;
        }
        for(int i = 0; i < 5; ++i) {
            if(opt[max_opt] < opt[i]) {
                max_opt = i;
            }
        }
        score += opt[max_opt] * a[j];
    }

    cout << score << '\n';
    return 0;
}