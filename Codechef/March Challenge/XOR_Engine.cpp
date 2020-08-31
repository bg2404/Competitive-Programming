#include<bits/stdc++.h>

using namespace std;

unsigned int countSetBits(unsigned int n) 
{ 
    unsigned int count = 0; 
    while (n) { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        int N, Q;
        cin >> N >> Q;
        int A[N];
        int odd = 0;
        for(int i = 0; i < N; ++i) {
            cin >> A[i];
            if(countSetBits(A[i]) & 1) {
                ++odd;
            }
        }
        int even = N-odd;

        int P;
        for(int i = 0; i < Q; ++i) {
            cin >> P;
            if(countSetBits(P) & 1) {
                cout << odd << ' ' << even << '\n';
            } else {
                cout << even << ' ' << odd << '\n';
            }
        }

    }
    return 0;
}