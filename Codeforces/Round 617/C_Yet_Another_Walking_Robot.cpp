#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long 

using namespace std;

struct coor {
    int x, y, index;

    bool operator < (const coor &o) {
        if(x == o.x) {
            if(y == o.y) {
                return index < o.index;
            }
            return y < o.y;
        }
        return x < o.x;
    }

    bool operator == (const coor &o) {
        return (x == o.x) && (y == o.y);
    }
};

int32_t main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        coor pos[n+1];
        pos[0] = {0,0,0};
        for(int i = 0; i < n; ++i) {
            pos[i+1] = pos[i];
            pos[i+1].index = i+1;
            if(s[i] == 'L') {
                pos[i+1].x -= 1;
            } else if(s[i] == 'R') {
                pos[i+1].x += 1;
            } else if(s[i] == 'U') {
                pos[i+1].y += 1;
            } else {
                pos[i+1].y -= 1;
            }
        }
        // for(int i = 0; i <= n; ++i) {
        //     cout << pos[i].x << " " << pos[i].y << '\n';
        // }
        // cout << '\n';
        sort(pos, pos + n + 1);
        int ans = 1000000000, a , b;
        for(int i = 1; i <= n; ++i) {
            if(pos[i] == pos[i-1]) {
                if(ans > pos[i].index - pos[i-1].index) {
                    ans = pos[i].index - pos[i-1].index;
                    b = pos[i].index;
                    a = pos[i-1].index+1;
                }
            }
        }
        if(ans == 1000000000) {
            a = -1; b = -1;
            cout << "-1\n";
        } else {
            cout << a << " " << b << '\n';
        }
        
    }
    return 0;
}