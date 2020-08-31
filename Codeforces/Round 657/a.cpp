#include<bits/stdc++.h>

using namespace std;

const string t = "abacaba";

bool checkPos(string &st, int n) {
    for(int i = 0; i < n; ++i) {
        if(st[i] == '?') {
            st[i] = 'd';
        }
    }
    int cnt = 0;
    for(int i = 0; i + 6 < n; ++i) {
        if(st.substr(i, 7) == t) {
            ++cnt;
        }
    }
    return cnt == 1;
}

void solve() {
    int n;
    cin >> n;
    string s, st;
    cin >> s;
    st = s;
    bool flag;
    for(int i = 0; i < n; ++i) {
        st = s;
        flag = true;
        for(int j = 0; j < 7 && i + j < n; ++j) {
            if(st[i + j] != t[j]) {
                if(st[i + j] == '?') {
                    st[i+j] = t[j];
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) {
            if(checkPos(st, n)) {
                cout << "Yes\n" << st << '\n';
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}