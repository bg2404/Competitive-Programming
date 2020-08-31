#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

vector<vector<bool> > overlap;
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int count_overlap[401];
int start_day = 1;

bool isLeap(int x) {
    if(x % 400 == 0) {
        return true;
    }
    if(x%100 == 0) {
        return false;
    }
    if(x%4 == 0) {
        return true;
    }
    return false;
}

bool isOverlap(int start, int num_days) {
    int long_e = 11 + (12 - start) % 7;
    int cook_s = num_days - 7 - (start + num_days - 1) % 7;
    return cook_s < long_e;
}

void saveOverlaps() {
    overlap.resize(401);
    for(int i = 0; i <= 400; ++i) {
        overlap[i].resize(12);
        fill(overlap[i].begin(), overlap[i].end(), false);
    }
    int next = start_day;
    count_overlap[0] = 0;
    for(int i = 1; i < 401; ++i) {
        int m_s = next;
        count_overlap[i] += count_overlap[i-1];
        for(int j = 0; j < 12; ++j) {
            int num_days = days[j];
            if(j == 2 && isLeap(i)) {
                num_days += isLeap(i);
            }
            if(isOverlap(m_s, num_days)) {
                overlap[i][j] = true;
                ++count_overlap[i];
            }
            m_s = (m_s +  num_days) % 7;
        }
        ++next;
        if(isLeap(i)) {
            ++next;
        }
        next = next % 7;
    }
}

int32_t main() {
    saveOverlaps();
    int T;
    cin >> T;
    while(T--) {
        int m1, y1, m2, y2;
        cin >> m1 >> y1 >> m2 >> y2;
        int ans = ((y2-y1)/400)*count_overlap[400];
        y2 = y1 + (y2-y1)%400;
        if(y1 == y2) {
            y1 = y1 % 400;
            if(y1 == 0) {
                y1 = 400;
            }
            for(int i = m1-1; i < m2; ++i) {
                ans += overlap[y1][i];
            } 
        } else if(y1 + 1 == y2) {
            y1 = y1 % 400;
            if(y1 == 0) {
                y1 = 400;
            }
            y2 = y2 % 400;
            if(y1 == 0) {
                y2 = 400;
            }
            for(int i = m1-1; i <= 11; ++i) {
                ans += overlap[y1][i];
            }
            for(int i = 0; i < m2; ++i) {
                ans += overlap[y2][i];
            }
        } else {
            int z1 = y1%400;
            if(z1 == 0) {
                z1 = 400;
            }
            for(int i = m1-1; i <= 11; ++i) {
                ans += overlap[z1][i];
            }
            cout << ans << ' ';
            int z2 = y2%400;
            if(z2 == 0) {
                z2 = 400;
            }
            if(z1 < z2) {
                ans += (count_overlap[z2] - count_overlap[z1-1]);
            } else {
                ans += count_overlap[400] - count_overlap[z1-1];
                cout << ans << ' ';
                ans += count_overlap[z2];
            }

            cout << ans << ' ';
            for(int i = 0; i < m2; ++i) {
                ans += overlap[z2][i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}