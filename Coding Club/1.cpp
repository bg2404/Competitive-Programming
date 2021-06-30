#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    int l, m, r;
    for(l = 0, r = n-1; l <= r;) {
        if(l == r) {
            if(A[l] == 0) {
                l = -1;
            }
            break;
        }
        m = (l + r) / 2;
        if(A[m] == 1) {
            r = m;
        } else {
            l = m+1;
        }
    }
    cout << l;

    return 0;
}