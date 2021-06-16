#include<bits/stdc++.h>

using namespace std;

int main() {
    int n = 30;
    int pow = 1;
    for(int i = 0; i < n; ++i) {
        printf("%d, ", pow);
        pow = pow << 1;
    }
    return 0;
}