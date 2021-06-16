#include<bits/stdc++.h>

using namespace std;

bool checkClockwise(int p[], int n) {
    bool ret = true;
    int j = p[0];
    for(int i = 0; i < n; ++i) {
        if(p[i] != (j+i)%n) {
            ret = false;
            break;
        }
    }
    return ret;
}

bool checkCouterClockwise(int p[], int n) {
    bool ret = true;
    int j = p[0];
    for(int i = 0; i < n; ++i) {
        if(p[i] != (((j-i)%n+n)%n)) {
            ret = false;
        }
    }
    return ret;
}

int main() {
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        int p[n];
        for(int i = 0; i < n; ++i) {
            cin >> p[i];
            p[i]--;
        }

        if(checkClockwise(p, n) || checkCouterClockwise(p, n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}