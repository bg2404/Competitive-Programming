#include<bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        long long a[n], b[n], d[n];
        d[0] = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
            if(i) d[i] = a[i] - a[i-1];
        }
        long long left = a[0], right = 0, cost = 0;
        for(int i = 1; i < n; ++i) {
            if(d[i] == 0) {
                right = b[i];
                int j = i;
                while(j+1 < n && d[j+1] == 1) {
                    right += b[++j];
                }
                left = min(left, 2*b[i-1]);
                if(i+1 < n && d[i+1] == 1)
            }
            // if(d[i] == 0) {
            //     (d[i-1] == -1) ? left += b[i-1]: left = b[i-1];
            //     right += b[i];
            //     while(i < n && d[i+1] == 1) {
            //         right += b[++i];
            //     }
            //     if(left > right) {
            //         cost += right;
            //         a[i]++;
            //         d[i+1]--;
            //     } else {
            //         cost += left;
            //     }
            //     left = right = 0;
            // } else if(d[i] == -1) {
            //     left += b[i-1];
            // }
        }
        cout << cost << '\n';
    }
    return 0;
}