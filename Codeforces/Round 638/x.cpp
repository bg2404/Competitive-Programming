#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n), v;
    long long s = 0;
    int max1 = 0, max2 = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] >= a[max1]) {
            max2 = max1;
            max1 = i;
        }
        s += a[i];
    }
    if(n == 1) {
        cout << 1 << '\n';
        cout << a[0] << '\n';
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        long long t = s - a[i];
        if(i == max1) {
            t -= a[max2];
            if(t == a[max2]) {
                v.push_back(i+1);
            }
        } else {
            t -= a[max1];
            if(t == a[max1]) {
                v.push_back(i+1);
            }
        }
    }

    cout << v.size() << '\n';
    for(int i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << '\n';

    return 0;
}