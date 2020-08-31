#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

string s;
vector<vector<int> > num;
int32_t main() {
    cin >> s;
    int n = s.size();
    s = "0" + s;
    num.assign(n+1, vector<int>(26, 0));
    for(int i = 1; i <= n; ++i) {
        num[i][s[i]-'a']++;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 26; ++j) {
            num[i][j] += num[i-1][j];
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;
        if(r-l+1 == 1) {
            cout << "Yes\n";
        } else if(s[l] != s[r]) {
            cout << "Yes\n";
        } else {
            int count = 0;
            for(int i = 0; i < 26; ++i) {
                if(num[r][i] > num[l-1][i]) {
                    ++count;
                }
            }
            if(count > 2) {
                cout << "Yes\n";
            } else {
                cout  << "No\n";
            }
        }
    }

    return 0;
}