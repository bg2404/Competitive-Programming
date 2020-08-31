#include<bits/stdc++.h>
#define int long long

using namespace std;

vector<int> num[26];

int32_t main() {
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; ++i) {
        num[s[i]-'a'].push_back(i+1);
    }
    
    int ans = 0;
    for(int i = 0; i < 26; ++i) {
        ans = max(ans, (int)num[i].size());
    }

    for(int i = 0; i < 26; ++i) {
        int temp;
        for(int k = 0; k < 26; ++k) {
            temp = 0;
            for(int j = 0; j < num[i].size(); ++j) {    
                temp += num[k].end() - upper_bound(num[k].begin(), num[k].end(), num[i][j]);
                // if((num[k].end() - upper_bound(num[k].begin(), num[k].end(), num[i][j])) > 0) {
                //     cout << i << ' ' << j << ' ' << k << " " << num[k].end() - upper_bound(num[k].begin(), num[k].end(), num[i][j]) << '\n';
                // }
            }
            ans = max(ans, temp);
        }
    }

    cout << ans << '\n';

    return 0;
}