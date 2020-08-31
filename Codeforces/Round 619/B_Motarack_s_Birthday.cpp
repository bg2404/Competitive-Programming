#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

template<typename T>
void printVec(vector<T> a) {
    int n = a.size();
    for(int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

template<typename T>
void printArr(T a[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int maxDiff(vector<int> a, int n, int k) {
    int i = 1;
    int d = 0;
    if(a[0] == -1) {
        a[0] = k;
    }
    for(int i = 1; i < n; ++i) {
        if(a[i] < 0) {
            a[i] = k;
        }
        d = max(d,abs(a[i] - a[i-1]));
    }
    return d;
}

int32_t main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int l = 10000000000, r = -1;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            r = max(r, a[i]);
            if(a[i] >= 0) {
                l = min(l, a[i]);
            }
        }
        // cout << l << ' ' << r << ' ';
        int m;
        int diff, dl, dr;
        if(l > r) {
            l = r = 0;
        }
        while(l <= r) {
            m = (l + r) / 2;
            diff = maxDiff(a, n, m);
            if(l < m)
                dl = maxDiff(a, n, m-1);
            else
                dl = 10000000000;
            dr = maxDiff(a,n,m+1);

            // cout << m << ' ' << dl << ' ' << diff << ' ' << dr << '\n';
            if(diff <= dl && diff <= dr) {
                break;
            } else if(diff <= dl && dr <= diff){
                l = m+1;
            } else {
                r = m-1;
            }
        }

        cout << diff << ' ' << m << '\n';
    }
    return 0;
}