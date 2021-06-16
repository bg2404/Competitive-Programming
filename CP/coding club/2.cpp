#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int A[26][2];
    for(int i = 0; i < 26; ++i) {
        for(int j = 0; j < 2; ++j) {
            A[i][j] = -1;
        }
    }

    for(int i = 0; i < s.length(); ++i) {
        int j = s[i] - 'a';
        A[j][0] = max(A[j][0], i - A[j][1]);
        A[j][1] = i;
    }

    int min_k = 1000000000;
    for(int i = 0; i < 26; ++i) {
        if(A[i][0] == -1) {
            continue;
        }
        if(n - A[i][1] > A[i][0]) {
            continue;
        }
        min_k = min(A[i][0], min_k);
    }

    cout << min_k << '\n';

    return 0;
}