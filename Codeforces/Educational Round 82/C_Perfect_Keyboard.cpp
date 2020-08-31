#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int32_t main() {
    int T;
    cin >> T;
    while(T--) {
        // cout << T << '\n';
        string s;
        cin >> s;
        string keys = "abcdefghijklmnopqrstuvwxyz";
        char keyboard[60];
        memset(keyboard, '0', sizeof(keyboard));
        map<char, bool> used;
        int cur = 27;
        keyboard[cur] = s[0];
        used[s[0]] = true;
        bool pos = true;
        for(int i = 1; i < s.size(); ++i) {
            if(used[s[i]]) {
                if(keyboard[cur+1] == s[i]) {
                    ++cur;
                } else if(keyboard[cur-1] == s[i]) {
                    --cur;
                } else {
                    // cout << T << ' ' << i;
                    pos = false;
                    break;
                }
            } else {
                if(keyboard[cur+1] == '0') {
                    ++cur;
                } else if(keyboard[cur-1] == '0') {
                    --cur;
                } else {
                    // cout << i;
                    pos = false;
                    break;
                }
                keyboard[cur] = s[i];
                used[s[i]] = true;
            }
        }

        int i;
        for(i = 0; i < 60; ++i) {
            if(keyboard[i] != '0') {
                break;
            }
        }
        for(++i; i < 60; ++i) {
            if(keyboard[i] == '0') {
                break;
            }
        }
        for(int j = 0; j < 26; ++j) {
            if(used[keys[j]]) {
                continue;
            }
            keyboard[i++] = keys[j];
        }

        if(pos) {
            // keyboard[59] = '\0';
            // cout << keyboard << ' ';
            cout << "YES\n";
            for(int i = 0; i < 60; ++i) {
                if(keyboard[i] != '0') {
                    cout << keyboard[i];
                }
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}