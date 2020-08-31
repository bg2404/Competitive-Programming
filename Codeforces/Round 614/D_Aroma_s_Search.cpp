#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int x[64], y[64], num = 1;

int32_t main() {
    int T = 1;
    int ans = 0;
    // cin >> T;
    while(T--) {
        int ax, bx, ay, by, xs, ys, t;
        cin >> x[0] >> y[0] >> ax >> ay >> bx >> by >> xs >> ys >> t;
        int min_dist = 100000000000000000, pos, dist;
        for(; x[num-1] < 10000000000000000 && y[num-1] < 10000000000000000; ++num) {
            x[num] = x[num-1]*ax + bx;
            y[num] = y[num-1]*ay + by;
            dist = abs(x[num] - xs) + abs(y[num] - ys);
            if(dist <= min_dist) {
                min_dist = dist;
                pos = num;
            }
        }
        if((dist = abs(x[0] - xs) + abs(y[0] - ys)) < min_dist) {
            min_dist = dist;
            pos = 0;
        }
        
        int done_till = pos;
        int pos2 = pos + 1;
        int t2 = t;
        int ans2 = ans;
        if(t >= min_dist) {
            ans++;
            t -= min_dist;
        } else {
            t = 0;
        }

        for(--pos; pos >= 0; pos--) {
            dist = abs(x[pos+1] - x[pos]) + abs(y[pos+1] - y[pos]);
            if(t >= dist) {
                ++ans;
                t -= dist;
            } else {
                t = 0;
            }
        }

        pos = done_till + 1;

        dist = abs(x[pos] - x[0]) + abs(y[pos] - y[0]);
        if(t >= dist) {
            ++ans;
            t -= dist;
        } else {
            t = 0;
        }

        for(++pos; pos < num; ++pos) {
            dist = abs(x[pos] - x[pos-1]) + abs(y[pos] - y[pos-1]);
            if(t >= dist) {
                ++ans;
                t -= dist;
            } else {
                t = 0;
            }
        }

        dist = abs(x[pos2] - xs) + abs(y[pos2] - ys);

        if(t2 >= dist) {
            ans2++;
            t2 -= dist;
        } else {
            t2 = 0;
        }

        for(--pos2; pos2 >= 0; pos2--) {
            dist = abs(x[pos2+1] - x[pos2]) + abs(y[pos2+1] - y[pos2]);
            if(t2 >= dist) {
                ++ans2;
                t2 -= dist;
            } else {
                t2 = 0;
            }
        }

        pos2 = done_till + 2;

        dist = abs(x[pos2] - x[0]) + abs(y[pos2] - y[0]);
        if(t2 >= dist) {
            ++ans2;
            t2 -= dist;
        } else {
            t2 = 0;
        }

        for(++pos2; pos2 < num; ++pos2) {
            dist = abs(x[pos2] - x[pos2-1]) + abs(y[pos2] - y[pos2-1]);
            if(t2 >= dist) {
                ++ans2;
                t2 -= dist;
            } else {
                t2 = 0;
            }
        }

        if(ans2 > ans) {
            ans = ans2;
        }
    }

    cout << ans << '\n';
    return 0;
}