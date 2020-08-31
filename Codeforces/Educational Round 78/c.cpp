//https://codeforces.com/contest/1278/problem/C
#include<bits/stdc++.h>

using namespace std;

const int RED = 1;
const int BLUE = 2;

bool comparator(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int binary_search(int l, int r, int k, vector<pair<int,int> > &arr) {
    int m;
    while(l < r) {
        m = (l+r)/2;
        // cout << l << ' ' << r << ' ' << m << '\n';
        if(arr[m].first < k) {
            l = m+1;
            if(arr[m+1].first > k) {
                return l;
            }
        } else {
            r = m;
        }
    }
    return l;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, r = 0, b = 0;
        cin >> n;
        vector<int> a(2*n);
        vector<pair<int, int> > left(n), right(n);
        for(int i = 0; i < 2*n; ++i) {
            cin >> a[i];
            if(a[i] == RED) {
                ++r;
            } else {
                ++b;
            }
        }
        if(a[n-1] == RED) {
            left[0] = {1, 1};
        } else {
            left[0] = {-1, 1};
        }
        if(a[n] == RED) {
            right[0] = {1, 1};
        } else {
            right[0] = {-1, 1};
        }

        for(int i = 2; i <= n; ++i) {
            if(a[n-i] == RED) {
                left[i-1] = {left[i-2].first + 1, i};
            } else {
                left[i-1] = {left[i-2].first + -1, i};
            }
            if(a[n+i-1] == RED) {
                right[i-1] = {right[i-2].first + 1, i};
            } else {
                right[i-1] = {right[i-2].first + -1, i};
            }
        }

        sort(left.begin(), left.end(), comparator);
        sort(right.begin(), right.end(), comparator);

        int target = r-b;
        if(target == 0) {
            cout << 0 << '\n';
            continue;
        }

        // cout << "right ";
        // for(int i = 0; i < n; ++i) {
        //     cout << right[i].first << ' ';
        // }
        // cout << '\n';

        int ans;
        if(target) {
            int index = binary_search(0, n, target, right);
            // cout << target << ' ' << index << ' ';
            if(right[index].first == target) {
                ans = right[index].second;
            } else {
                ans = 2*n;
            }
        } else {
            ans = 2*n;
        }

        // cout << ans << '\n';

        for(int i = 0; i < n; ++i) {
            int k = target - left[i].first;

            // cout << "k = " << k << ' ';
            if(k) {
                int index = binary_search(0, n, k, right);
                // int index = 0;

                if(right[index].first == k) {
                    ans = min(ans, left[i].second + right[index].second);
                    // cout << "ans = " << ans << ' ';
                }
            } else {
                ans = min(ans, left[i].second);
                // cout << "ans = " << ans << ' ';
            }
            // cout << '\n';
        }

        cout << ans << '\n';
    }

    return 0;
}