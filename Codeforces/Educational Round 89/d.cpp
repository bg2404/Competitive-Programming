#include<bits/stdc++.h>

using namespace std;

int sPrime[10000001];

void sieve(int n) {
    sPrime[0] = 0;
    sPrime[1] = 1;
    for(int i = 2; i < n; ++i) {
        if(sPrime[i] == 0) {
            for(int j = i; j < n; j += i) {
                if(sPrime[j] == 0) {
                    sPrime[j] = i;
                }
            }
        }
    }
}

int main() {
    sieve(10000001);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i: a) {
        cin >> i;
    }
    vector<int> d1, d2;
    for(int i = 0; i < n; ++i) {
        if(sPrime[a[i]] == a[i]) {
            d1.push_back(-1);
            d2.push_back(-1);
        } else {
            long long p = sPrime[a[i]];
            int x = a[i];
            while(x % p == 0) {
                p *= sPrime[a[i]];
            }
            p /= sPrime[a[i]];
            int d = a[i] / p;
            if(d == 1) {
                d1.push_back(-1);
                d2.push_back(-1);
            } else {
                d1.push_back(p);
                d2.push_back(d);
            }
        }
    }
    for(auto i: d1) {
        cout << i << ' ';
    }
    cout << '\n';
    for(auto i: d2) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}