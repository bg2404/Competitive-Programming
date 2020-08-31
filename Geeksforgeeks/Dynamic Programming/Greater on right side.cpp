#include<bits/stdc++.h>

using namespace std;

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int main() {
    int T;
     cin >> T;
     while(T--) {
        int N;
        cin >> N;
        int A[N];
        for(int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        int ma = -1, r = -1;

        for(int i = N-1; i >= 0; --i) {
            ma = max(A[i], r);
            A[i] = r;
            r = ma;
        }

        for(int i = 0; i < N; ++i) {
            cout <<  A[i] << ' ';
        }
        cout << '\n';
        
     }
    return 0;
}