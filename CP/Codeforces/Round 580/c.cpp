#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if(n&1) {
        cout << "YES" << '\n';
        int a[2*n+1];
        a[1] = 1;
        for(int i = 2; i <= 2*n; ++i) {
            if((i/2)&1) {
                if(i&1) {
                    a[n+i/2+1] = i;
                } else {
                    a[n+i/2] = i;
                }
            } else {
                if(i&1) {
                    a[i/2+1] = i;
                } else {
                    a[i/2] = i;
                }
            }
        }
        for(int i = 1; i <= 2*n; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}