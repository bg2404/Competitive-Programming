//https://codeforces.com/contest/1325/problem/B

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        int distinct = 0;
        map<int, int> used;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(used[a[i]] == 0) {
                ++distinct;
                ++used[a[i]];
            }
        }
        cout << distinct << '\n';
    }
    return 0;
}