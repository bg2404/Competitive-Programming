#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> w(n), h(n);
    for(int i = 0; i < n; ++i) {
        cin >> w[i] >> h[i];
    }
    int W, H, mA = 1000000001, A;
    for(int H = 1; H <= 1000; ++H) {
        W = 0;
        for(int i = 0; i < n; ++i) {
            if(h[i] >= w[i]) {
                if(h[i] <= H) {
                    W += w[i];
                } else if(w[i] <= H) {
                    W += h[i];
                } else {
                    W = -1;
                    break;
                }
            } else {
                if(w[i] <= H) {
                    W += h[i];
                } else if(h[i] <= H) {
                    W += w[i];
                } else {
                    W = -1;
                    break;
                }
            }
        }
        if(W >= 0) {
            A = W*H;
            mA = min(mA, A);
        }
    }
    cout << mA << '\n';
}