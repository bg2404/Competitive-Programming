#include<bits/stdc++.h>

using namespace std;

long long getLargest(long long a, long long b, long long c) {
    if(a > b) {
        if(a > c) {
            return a;
        }
        return c;
    }
    if(b > c) {
        return b;
    }
    return c;
}

long long getSmallest(long long a, long long b, long long c) {
    if(a < b) {
        if(a < c) {
            return a;
        }
        return c;
    }
    if(b < c) {
        return b;
    }
    return c;
}

long long getMiddle(long long a, long long b, long long c) {
    vector<long long> v = {a, b, c};
    sort(v.begin(), v.end());
    return v[1];
}

int main() {
    long long a[4];
    cin >> a[1] >> a[2] >> a[3];
    cout << "First" << endl;
    long long l = getLargest(a[1], a[2], a[3]), s = getSmallest(a[1], a[2], a[3]), m = getMiddle(a[1], a[2], a[3]);
    long long add = 2*l - s - m;
    cout << add << endl;
    cout.flush();
    int res;
    cin >> res;
    if(res < 1) {
        return 0;
    }
    if(a[res] == s) {
        cout << l - m << endl;
        cout.flush();
        int res;
        cin >> res;
        if(res < 1) {
            return 0;
        }
    } else if(a[res] == m) {
        cout << l - s << endl;
        cout.flush();
        int res;
        cin >> res;
        if(res < 1) {
            return 0;
        }
    } else {
        a[res] += add;
        long long l = getLargest(a[1], a[2], a[3]), s = getSmallest(a[1], a[2], a[3]), m = getMiddle(a[1], a[2], a[3]);
        long long add = 2*l - s - m;
        cout << add << endl;
        cout.flush();
        int res;
        cin >> res;
        if(res < 1) {
            return 0;
        }
        if(a[res] == s) {
            cout << l - m << endl;
            cout.flush();
            int res;
            cin >> res;
            if(res < 1) {
                return 0;
            }
        } else if(a[res] == m) {
            cout << l - s << endl;
            cout.flush();
            int res;
            cin >> res;
            if(res < 1) {
                return 0;
            }
        }
    }
    return 0;
}