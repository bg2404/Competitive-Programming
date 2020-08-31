#include<bits/stdc++.h>

using namespace std;

int n;
bool cards[5][5];

int color2num(int c) {
    if(c == 'R') return 0;
    if(c == 'G') return 1;
    if(c == 'B') return 2;
    if(c == 'Y') return 3;
    return 4;
}

int getbits(int x) {
    int counter = 0;
    int y = 1;
    while(y <= x) {
        if(x&y) {
            ++counter;
        }
        y = y << 1;
    }
    return counter;
}

int main() {
    int types = 0;
    string s;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        int c = color2num(s[0]);
        int v = s[1]-'1';
        cards[c][v] = true;
    }

    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            // cout << cards[i][j] << ' ';
            if(cards[i][j]) {
                types++;
            }
        }
        // cout << '\n';
    }

    int ans = 11;

    for(int i = 0; i < (1 << 5); ++i) {
        for(int j = 0; j < (1 << 5); ++j) {
            int temp = 0;
            int bits = getbits(i) + getbits(j);
            int c_v[5], v_c[5];
            for(int i = 0; i < 5; ++i) {
                c_v[i] = v_c[i] = 0;
            }
            for(int m = 0; m < 5; ++m) {
                for(int n = 0; n < 5; ++n) {
                    if(cards[m][n]) {
                        c_v[n]++;
                        v_c[m]++;
                    }
                }
            }
            for(int m = 0; m < 5; ++m) {
                for(int n = 0; n < 5; ++n) {
                    if(cards[m][n] && (i & (1<<m)) && (j & (1<<n))) {
                        c_v[n]--;
                        v_c[m]--;
                    }
                }
            }
            for(int m = 0; m < 5; ++m) {
                for(int n = 0; n < 5; ++n) {
                    if(cards[m][n]) {
                        if((i & (1<<m)) && (j & (1<<n))) {
                            ++temp;
                        } else if((i & (1<<m)) && v_c[m] == 1) {
                            ++temp;
                        } else if((j & (1<<n)) && c_v[n] == 1) {
                            ++temp;
                        }
                    }
                }
            }

            if(temp + 1 >= types)
                ans = min(ans, bits);
            // cout << temp << ' ';
        }
    }
    cout << ans << '\n';
    return 0;
}