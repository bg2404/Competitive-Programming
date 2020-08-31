#include<bits/stdc++.h>

using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> grid(h), temp;
    for(int i = 0; i < h; ++i) {
        cin >> grid[i];
    }
    int x, y, ans = 0;
    for(x = 0; x < (1 << h); ++x) {
        for(y = 0; y < (1 << w); ++y) {
            temp = grid;
            for(int i = 0; i < h; ++i) {
                if(x & (1 << i)) {
                    for(int j = 0; j < w; ++j) {
                        temp[i][j] = 'c';
                    }
                }
            }
            for(int i = 0; i < w; ++i) {
                if(y & (1 << i)) {
                    for(int j = 0; j < h; ++j) {
                        temp[j][i] = 'c';
                    }
                }
            }

            int count = 0;
            for(int i = 0; i < h; ++i) {
                for(int j = 0; j < w; ++j) {
                    if(temp[i][j] == '#') {
                        ++count;
                    }
                }
            }
            if(count == k) {
                ++ans;
            }
            // cout << x << ' ' << y << ' ' << count << ' ' << ans << '\n';
            // for(string s: temp) {
            //     cout << s << '\n';
            // }
        }
    }
    cout << ans << '\n';
    return 0;
}