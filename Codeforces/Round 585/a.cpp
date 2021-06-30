#include<bits/stdc++.h>

using namespace std;

int main() {
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    int min_n = 3000000;
    int max_n = 0;
    int N = n - (k1-1)*a1 - (k2-1)*a2, M = n;
    min_n = max(0, N);
    if(k1 < k2) {
        k1 = k1+k2;
        k2 = k1-k2;
        k1 = k1-k2;
        a1 = a1+a2;
        a2 = a1-a2;
        a1 = a1-a2;
    }

    while(M >= k2 && a2--) {
         M -= k2;
         max_n++;
    }
    while(M >= k1 && a1--) {
        M -= k1;
        max_n++;
    }

    cout << min_n << ' ' << max_n << '\n';
    
    return 0;
}