//https://codeforces.com/contest/1324/problem/B

#include<bits/stdc++.h>
#define int long long

using namespace std;

template<typename T>
void printVector(vector<T> v) {
    for(auto u: v) {
        cout << u << ' ';
    }
    cout << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    // t = 1'
    while(t--) {
        int n;
        cin >> n;
        bool palindrome = false;
        vector<int> a(n);
        vector<int> count(n+1, 0);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i) {
            if(count[a[i]] == 0) {
                count[a[i]] = i+1;
            } else {
                if(i + 1 - count[a[i]] > 1) {
                    palindrome = true;
                    break;
                }
            }
        }

        if(palindrome) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}