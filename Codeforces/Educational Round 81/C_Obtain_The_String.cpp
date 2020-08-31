#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int32_t main() {
    int TestCase = 1;
    cin >> TestCase;
    while(TestCase--) {
        vector<int> count[26];
        vector<int> index(26, 0);

        string s, t;
        cin >> s >> t;

        for(int i = 0; i < s.size(); ++i) {
            count[s[i]-'a'].push_back(i);
        }
        
        bool pos = true;
        int len = 0, moves = 0, cur = -1;
        while(len < t.size()) {
            moves++;
            for(int i = len; i < t.size(); ++i) {
                if(count[t[i]-'a'].size() == 0) {
                    pos = false;
                    break;
                } else if(index[t[i]-'a'] < count[t[i]-'a'].size()) {
                    int next = count[t[i]-'a'][index[t[i]-'a']];
                    while(next <= cur && index[t[i]-'a'] + 1 < count[t[i]-'a'].size()) {
                        ++index[t[i]-'a'];
                        next = count[t[i]-'a'][index[t[i]-'a']];
                    }
                    if(cur < next) {
                        index[t[i]-'a']++;
                        len++;
                        cur = next;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
            if(!pos) {
                moves = -1;
                break;
            }

            for(int i = 0; i < 26; ++i) {
                index[i] = 0;
                cur = -1;
            }
        }
        cout << moves << '\n';
    }
    return 0;
}