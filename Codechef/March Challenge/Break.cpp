#include<bits/stdc++.h>

using namespace std;

int main() {
    int T, S;
    cin >> T >> S;
    while(T--) {
        map<int, int> used;
        bool pos = true;
        used.clear();
        int N;
        cin >> N;
        int A[N], B[N];
        for(int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for(int i = 0; i < N; ++i) {
            cin >> B[i];
        }
        int ctr = 1;
        sort(A, A+N);
        sort(B, B+N);
        for(int i = 0; i < N; ++i) {
            if(B[i] <= A[i]) {
                pos = false;
            }
        }
        if(pos) {
            int a = A[0], b = B[0];
            while(a < b && ctr < N) {
                used[a] = 1;
                used[b] = 1;

                a = A[ctr];
                b = B[ctr++];
                if(used[a] != 1) {
                    pos = false;
                    break;
                }
            }
        }

        if(pos) {
            cout << "YES" << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}