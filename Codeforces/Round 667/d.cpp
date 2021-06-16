#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        int s;
        cin >> n >> s;
        vector<int> v;
        while(n) {
            v.push_back(n % 10);
            n /= 10;
        }
        int m = v.size();
        for(int i = m-2; i >= 0; --i) {
            v[i] = v[i] + v[i+1];
        }
        if(v[0] <= s) {
            cout << 0 << '\n';
            continue;
        }
        int k = 0;
        while(k < m && v[k] > s) {
            ++k;
        }
        if(k < m && v[k] == s) {
            while(k + 1 < m && v[k+1] == v[k]) {
                ++k;
            }
        }
        long long ans = 0;
        if(k == m) {
            ans = 9 - v[m-1];
            for(int i = m-2; i >= 0; --i) {
                ans *= 10;
                ans += 9 - v[i] + v[i+1];
            }
            ans += 1;
        } else if(k > 0) {
            if(v[k] < s) {
                for(int i = k-1; i >= 0; --i) {
                    ans *= 10;
                    ans += 9 - v[i] + v[i+1];
                }
                ans += 1;
            } else {
                ans = 9 - ((k == m - 1) ? v[k] : v[k] - v[k+1]);
                for(int i = k-1; i >= 0; --i) {
                    ans *= 10;
                    ans += 9 - v[i] + v[i+1];
                }
                ans += 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}